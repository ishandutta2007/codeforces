#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
const int N=300000;
int n,m,s;
int a[N+1];
int Sum[N+1];
int mxarr(int l,int r){
	return *max_element(Sum+l,Sum+r+1)-Sum[l-1];
}
signed main(){
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&s);
	for(int i=1;i<=n;i++)scanf("%lld",a+i),Sum[i]=Sum[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=m&&i<=n;i++){
		int las=n-(n-i+1)%m+1;
		if(las==n+1)las-=m;
		int now=mxarr(las,n)-s;
		ans=max(ans,now);
		for(int j=las-m;j>=i;j-=m){
			now=max(now+Sum[j+m-1]-Sum[j-1],mxarr(j,j+m-1))-s;
			ans=max(ans,now);
		}
	}
	printf("%lld\n",ans);
	return 0;
}