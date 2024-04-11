using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define N 401
#define ll long long
ll dp1[N][N],dp2[N][N];
ll n,v[N],w[N];
ll doit1(int l,int r);
ll doit2(int l,int r);
ll doit1(int l,int r) {
	if(r<l) return 0;
	if(dp1[l][r]>-1e15) return dp1[l][r];
	if(l==r) return dp1[l][r]=v[1];
	dp1[l][r]=-1e15+1;
	for(int i=l;i<=r-1;i++) {
		dp1[l][r]=max(dp1[l][r],doit1(l,i)+doit1(i+1,r));
	}
	for(int i=l;i<=r;i++) {
		dp1[l][r]=max(dp1[l][r],doit2(l,i)+doit2(i,r)+(((w[i]*2-w[l]-w[r]+1)>0&&(w[i]*2-w[l]-w[r]+1)<=n&&(w[l]<=w[i]&&w[r]<=w[i]))?v[w[i]*2-w[l]-w[r]+1]:(ll)-1e15));
	}
	return dp1[l][r];
}
ll doit2(int l,int r) {
	if(dp2[l][r]>-1e15) return dp2[l][r];
	if(l==r) return dp2[l][r]=0;
	if(r-l==1) {
		if(abs(w[l]-w[r])==1) return 0;
		return -1e15;
	}  
	dp2[l][r]=-1e15+1;
	if(abs(w[l]-w[r])==1) return dp2[l][r]=doit1(l+1,r-1);
	for(int i=l+1;i<=r;i++) {
		if(abs(w[i]-w[l])==1&&((w[i]-w[l])*(w[r]-w[i])>0)) {
			dp2[l][r]=max(dp2[l][r],doit1(l+1,i-1)+doit2(i,r));
		}
	}
	return dp2[l][r];
}
ll ans[N];
int main() {
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&v[i]);
	}
	for(int i=1;i<=n;i++) {
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			dp1[i][j]=dp2[i][j]=-1e15;
		}
	}
/*	for(int i=1;i<=n;i++) {
		for(int j=i;j<=n;j++) {
			doit1(i,j);doit2(i,j);
		}
	}*/
	ans[0]=0;
	for(int i=1;i<=n;i++) {
		ans[i]=ans[i-1];
		for(int j=1;j<=i;j++) {
			ans[i]=max(ans[i],ans[j-1]+doit1(j,i));
		}
	}
	cout<<ans[n]<<endl;
}