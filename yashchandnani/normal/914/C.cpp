#include <bits/stdc++.h>
using namespace std;

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll fac[1009],inv[1009];
const int MOD = 1e9+7;
// C function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll *x, ll *y);
 
// Function to find modulo inverse of a
ll modInverse(ll a, ll m)
{
	    ll x, y;
		    ll g = gcdExtended(a, m, &x, &y);
			   
			    {
					        // m is added to handle negative x
					        ll res = (x%m + m) % m;
							        return res;
									    }
}
 
// C function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
	    // Base Case
	    if (a == 0)
			    {
					        *x = 0, *y = 1;
							        return b;
									    }
		 
		    ll x1, y1; // To store results of recursive call
			    ll gcd = gcdExtended(b%a, a, &x1, &y1);
				 
				    // Update x and y using results of recursive
				    // call
				    *x = y1 - (b/a) * x1;
					    *y = x1;
						 
						    return gcd;
}
void pre(){
	repA(i,2,1000){
		fac[i] = 1ll*i*fac[i-1];
		fac[i]%=MOD;
		inv[i] = inv[i-1]*modInverse(i,MOD);
		inv[i]%=MOD;
	}
}
int r(int i){
	int ans = 0;
	while(i){
		if(i%2) ans++;
		i/=2;
	}
	return ans;
}
ll C(int n,int r){
	if(r>n) return 0;
	ll ans = fac[n]*inv[r];
	ans%=MOD;
	ans*=inv[n-r];
	ans%=MOD;
	return ans;
}
int fns[1019];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	fac[0] = fac[1] =inv[0] = inv[1] = 1;
	pre();
	string s;cin>>s;
	int k;cin>>k;
	if(k==0){
		cout<<1;return 0;
	}
	else if(k==1){
		cout<<sz(s)-1;return 0;
	}
	else if(k>5){
		cout<<0;return 0;
	}
	int cnt = 0;
	vi n,pos;

	rep(i,sz(s)){
		if(s[i]=='1') cnt++;
		else n.pb(cnt),pos.pb(i);
	}
	int l = sz(s);
	ll ans = 0;
	fns[1] = 0;
	vi ks;
	repA(i,2,1010){
		fns[i] = 1+fns[r(i)];
		if(fns[i]==k-1) {
			ks.pb(i);
		}
	}
	trav(i,ks){
		if(i>l) break;
		ans+=C(l,i);
		ans%=MOD;
		rep(j,sz(pos)){
			if(i<n[j]+1) break;
			int kk = i-n[j]-1;
			int ll = l-pos[j]-1;
			ans-=C(ll,kk);ans%=MOD;
		}
	}
	cout<<(ans%MOD+MOD)%MOD;

	return 0;
}