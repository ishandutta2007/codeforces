#include<bits/stdc++.h>
#define PB push_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=200005;
int n,Q,a[N],tt[N],pos3[N],pos4[N];
array<int,3>ans3[N];
array<int,4>ans4[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	memset(pos3,63,sizeof(pos3));
	memset(pos4,63,sizeof(pos4));
	scanf("%d%d",&n,&Q);
	rep(i,1,n)scanf("%d",&a[i]);
	set<int>S;
	vector<int>mn,mx;
	int l1=1,l2=1;
	for(int i=n,j;i>=1;i=j){
		j=i;
		while(j>=1&&a[i]==a[j])--j;
		while(SZ(mn)&&a[i]<a[mn.back()]){
			if(!--tt[mn.back()])S.insert(mn.back());
			mn.pop_back();
			l1=0;
		}
		while(SZ(mx)&&a[i]>a[mx.back()]){
			if(!--tt[mx.back()])S.insert(mx.back());
			mx.pop_back();
			l2=0;
		}
		int k1=lower_bound(mn.begin(),mn.end(),i,[&](int k1,int k2){return a[k1]<a[k2];})-mn.begin()-1;
		int k2=lower_bound(mx.begin(),mx.end(),i,[&](int k1,int k2){return a[k1]>a[k2];})-mx.begin()-1;
		pos3[i]=i+max(l1,l2)+1;
		if(pos3[i]<=n){
			ans3[i]={i,pos3[i]-1,pos3[i]};
		}
		if(k1!=-1&&k2!=-1){
			auto it=S.upper_bound(max(mn[k1],mx[k2]));
			if(it!=S.end()){
				pos4[i]=*it;
				k1=*lower_bound(mn.begin(),mn.end(),*it,greater<int>());
				k2=*lower_bound(mx.begin(),mx.end(),*it,greater<int>());
				ans4[i]={i,min(k1,k2),max(k1,k2),*it};
			}
		}
		if(pos4[i+1]<pos4[i]){
			pos4[i]=pos4[i+1];
			ans4[i]=ans4[i+1];
		}
		if(pos3[i+1]<pos3[i]){
			pos3[i]=pos3[i+1];
			ans3[i]=ans3[i+1];
		}
		mn.PB(i);
		mx.PB(i);
		++l1,++l2;
		tt[i]+=2;
		per(k,i-1,j+1){
			mn.PB(k);
			mx.PB(k);
			++l1,++l2;
			tt[k]+=2;
			pos4[k]=pos4[k+1],ans4[k]=ans4[k+1];
			pos3[k]=pos3[k+1],ans3[k]=ans3[k+1];
		}
	}
	rep(_,1,Q){
		int l,r;
		scanf("%d%d",&l,&r);
		if(pos4[l]<=r){
			puts("4");
			for(auto x:ans4[l])printf("%d ",x);
			puts("");
		}
		else if(pos3[l]<=r){
			puts("3");
			for(auto x:ans3[l])printf("%d ",x);
			puts("");
		}
		else
			puts("0");
	}
	return 0;
}