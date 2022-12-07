#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
vector<ll> v[3005];
ll f[20][3005],ans;
int n,k; 
void solve(int l,int r,int d){
	if (l==r){
		For(i,0,v[l].size()-1)
			if (i+1<=k) ans=max(ans,v[l][i]+f[d][k-i-1]);
		return;
	}
	int mid=(l+r)/2;
	memcpy(f[d+1],f[d],sizeof(f[d]));
	For(i,mid+1,r){
		ll v1=v[i].size(),v2=v[i][v1-1];
		Rep(j,k-v1,0) f[d+1][j+v1]=max(f[d+1][j+v1],f[d+1][j]+v2);
	}
	solve(l,mid,d+1);
	memcpy(f[d+1],f[d],sizeof(f[d]));
	For(i,l,mid){
		ll v1=v[i].size(),v2=v[i][v1-1];
		Rep(j,k-v1,0) f[d+1][j+v1]=max(f[d+1][j+v1],f[d+1][j]+v2);
	}
	solve(mid+1,r,d+1);
}
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,n){
		int t;
		scanf("%d",&t);
		v[i].resize(t);
		For(j,0,t-1) scanf("%lld",&v[i][j]);
		For(j,1,t-1) v[i][j]+=v[i][j-1];
	}
	solve(1,n,0);
	cout<<ans<<endl;
}