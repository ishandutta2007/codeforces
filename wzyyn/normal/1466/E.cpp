#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;
const int mo=1000000007;
int n,b[65];
ll a[500005];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld",&a[i]);
	memset(b,0,sizeof(b));
	For(i,1,n) For(j,0,59) if (a[i]&(1ll<<j)) ++b[j];
	int ans=0;
	For(i,1,n){
		int v0=0,v1=0;
		For(j,0,59)
			if (a[i]&(1ll<<j)){
				v0=(v0+(1ll<<j)%mo*b[j])%mo;
				v1=(v1+(1ll<<j)%mo*n)%mo;
			}
			else
				v1=(v1+(1ll<<j)%mo*b[j])%mo;
		ans=(ans+1ll*v0*v1)%mo;
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}