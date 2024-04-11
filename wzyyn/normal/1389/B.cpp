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
int n,k,z,a[100005];
void solve(){
	scanf("%d%d%d",&n,&k,&z);
	For(i,1,n) scanf("%d",&a[i]);
	int ans=0;
	For(i,0,z) if (2*i<=k){
		int mx=0,sum=0;
		For(j,1,k-2*i) sum+=a[1+j];
		For(j,1,k-2*i+1) if (j!=n)
			mx=max(mx,a[j]+a[1+j]);
		ans=max(ans,i*mx+sum);
	}
	cout<<ans+a[1]<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}