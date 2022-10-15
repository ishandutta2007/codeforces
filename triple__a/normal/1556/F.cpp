#include<bits/stdc++.h>
#define int long long
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int maxn=200007;
const int mod=1e9+7;
const int inf=LLONG_MAX/4;
mt19937 rng(time(NULL)); // don't hack, pls!
int n,q;
int a[maxn],p[14][14],win_prob[1<<14],dp[1<<14],pb[14][1<<14];

int modpow(int u,int v){
	int res=1, t=u%mod;
	while (v){
		if (v&1) res=res*t%mod;
		t=t*t%mod, v>>=1;
	}
	return res;
}

int inv(int u){
	return modpow(u,mod-2);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(15);
	cin>>n;
	rep(i,n) cin>>a[i];
	rep(i,n) rep(j,n) p[i][j]=a[i]*inv(a[i]+a[j])%mod;
	rep(i,n) rep(j,1<<n){
		if (j>>i&1) continue;
		pb[i][j]=1;
		rep(s,n) if (j>>s&1) pb[i][j]=pb[i][j]*p[i][s]%mod;
	}
	int ans=0;
	rep(i,1<<n){
		if (!i) continue;
		win_prob[i]=1;
		for (int mask=i;mask;mask=(mask-1)&i){
			if (i==mask) continue;
			rep(j,n){
				if ((mask>>j&1)||!(i>>j&1)) continue;
				win_prob[mask]=win_prob[mask^(1<<j)]*pb[j][((1<<n)-1)^i]%mod;
				break;
			}
			dp[i]=(dp[i]-dp[mask]*win_prob[mask])%mod;
			dp[i]+=mod, dp[i]%=mod;
		}
		rep(j,n){
			if (!(i>>j&1)) continue;
			win_prob[0]=win_prob[1<<j]*pb[j][((1<<n)-1)^i]%mod;
			break;
		}
		dp[i]=(dp[i]+win_prob[0])%mod;
		ans=(ans+dp[i]*__builtin_popcount(i))%mod;
	}
	cout<<ans;
	return 0;
}