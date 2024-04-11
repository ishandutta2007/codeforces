#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int n,m;ll f[100009],sum[100009];
struct pp{int s,t;}a[100009];
bool cmp(pp x,pp y){return x.t==y.t?(x.s<y.s):(x.t<y.t);}
int find(int x,int id){
	int l=0,r=id,ans=id;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid].t>=x) ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
int re_find(int x,int id){
	int l=0,r=id,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid].t<x) ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int main(){
	memset(f,0,sizeof(f));
	memset(sum,0,sizeof(sum));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&a[i].s,&a[i].t);
	sort(a+1,a+m+1,cmp);
	a[0].t=0,f[0]=1,sum[0]=1;
	ll ans=0;
	for(int i=1;i<=m;i++){
		int l=find(a[i].s,i);
		int r=re_find(a[i].t,i);
		if(l<=r) f[i]=(f[i]+(sum[r]-(l<=0?0:sum[l-1])+mod+mod)%mod)%mod;
		sum[i]=(sum[i-1]+f[i])%mod;
		if(a[i].t==n) ans=(ans+f[i])%mod;
	}
	if(a[m].t<n){
		printf("0\n");
		return 0;
	}
	printf("%lld\n",ans%mod);
	return 0;
}