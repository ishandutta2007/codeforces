#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define PB push_back
#define LL long long
using namespace std;
const int N=300005,INF=0X3F3F3F3F;
int n,m,f[N];
struct data{
	int x,y;
	bool operator<(const data&k2)const{return x^k2.x?x<k2.x:y<k2.y;}
};
set<data>S;
set<data>::iterator jt,it;
vector<data>v[N];
int main(){
	scanf("%d%d",&n,&m);
	S.insert((data){1,0}),S.insert((data){INF,0});
	rep(i,1,n){
		int l,r,id;scanf("%d%d",&l,&r);
		jt=(it=S.upper_bound((data){l,INF}))--;
		v[i].PB((data){id=it->y,it->x-jt->x});
		if(it->x<l)v[i].PB((data){id,l-it->x});else S.erase(it);
		v[i].PB((data){i,r-l}),S.insert((data){l,i});
		while(jt->x<r)it=jt++,v[i].PB((data){id=it->y,it->x-jt->x}),S.erase(it);
		if(jt->x>r)v[i].PB((data){id,jt->x-r}),S.insert((data){r,id});
	}
	int l=1,r=INF;LL X,S1,S2;
	while(l<=r){
		int mid=(l+r)>>1;
		memset(f,0,sizeof(f));
		int j=1;
		LL t1=0,t2=0,s1=0,s2=0;
		rep(i,1,n){
			for(auto k:v[i])if(k.x<j)t1+=1LL*k.x*k.y;
			else t1+=1LL*(j-1)*k.y,t2+=k.y,f[k.x]+=k.y;
			while(j<=i&&t2>=mid)t1+=t2,t2-=f[j++];
			s1+=t1,s2+=j-1;
		}
		if(s2>=m)X=mid,S1=s1,S2=s2,l=mid+1;else r=mid-1;
	}
	printf("%lld\n",S1-(S2-m)*X);
	return 0;
}