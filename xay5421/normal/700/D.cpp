#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=100005,B=350;
int n,Q,a[N],tt[N],bin[N],tmp[N],len,num[N/B+5],ans[N];
struct ff{
	int l,r,id;
	bool operator<(const ff&k)const{
		return l/B^k.l/B?l<k.l:l/B&1?r<k.r:r>k.r;
	}
}q[N];
void put(int k1,int k2){
	--bin[tt[k1]];
	tt[k1]+=k2;
	++bin[tt[k1]];
}
int sol(){
	priority_queue<int,vector<int>,greater<int> >q;
	int ans=0;
	rep(i,1,len){
		if(tt[num[i]]>B)q.push(tt[num[i]]);
	}
	rep(i,1,B){
		tmp[i]=bin[i];
	}
	int j=0;
	rep(i,1,B)if(tmp[i]){
		if(j){
			--tmp[i];
			ans+=i+j;
			if(i+j<=B){
				++tmp[i+j];
			}else{
				q.push(i+j);
			}
			j=0;
		}
		if(tmp[i]&1){
			--tmp[i];
			j=i;
		}
		ans+=i*tmp[i];
		if(i*2<=B){
			tmp[i*2]+=tmp[i]>>1;
		}else{
			rep(_,1,tmp[i]>>1)q.push(i*2);
		}
		tmp[i]=0;
	}
	if(j)q.push(j);
	while(SZ(q)>1){
		int k1=q.top();
		q.pop();
		int k2=q.top();
		q.pop();
		ans+=k1+k2;
		q.push(k1+k2);
	}
	return ans;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
		if(++tt[a[i]]==B+1){
			num[++len]=a[i];
		}
	}
	scanf("%d",&Q);
	rep(i,1,Q){
		int l,r;
		scanf("%d%d",&l,&r);
		q[i]=(ff){l,r,i};
	}
	sort(q+1,q+1+Q);
	memset(tt,0,sizeof(tt));
	int l=1,r=0;
	rep(i,1,Q){
		while(l>q[i].l)put(a[--l],1);
		while(r<q[i].r)put(a[++r],1);
		while(l<q[i].l)put(a[l++],-1);
		while(r>q[i].r)put(a[r--],-1);
		ans[q[i].id]=sol();
	}
	rep(i,1,Q)printf("%d\n",ans[i]);
	return 0;
}