#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=1<<17|5;
int n,k,m,mx[N],smx[N];
void solve(){
	scanf("%d%d",&n,&k);
	for (m=1;m<=n;m<<=1);
	for (int i=0;i<m;i++) mx[i]=smx[i]=-1;
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if (mx[x]==-1) mx[x]=i;
		else smx[x]=mx[x],mx[x]=i; 
	}
	for (int d=1;d<m;d<<=1)
		for (int i=0;i<m;i++) if (i&d){
			if (mx[i]<mx[i^d]) smx[i]=max(mx[i],smx[i^d]);
			else smx[i]=max(smx[i],mx[i^d]);
			mx[i]=max(mx[i],mx[i^d]);
		}
	ll ans=-(1ll<<60);
	for (int i=0;i<m;i++)
		if (smx[i]!=-1)
			ans=max(ans,1ll*mx[i]*smx[i]-1ll*k*i);
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}