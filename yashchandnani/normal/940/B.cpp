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

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll n,k,a,b;cin>>n>>k>>a>>b;
	if(k==1) {
		cout<<a*(n-1);
	}
	else{
		ll x = b/((k-1)*a);
		ll ans =0;
		while(n>x*k){
			if(n%k==0) ans+=b,n/=k;
			else ans+=a*(n%k),n-=n%k;
		}
		ans+=a*(n-1);
		cout<<ans;

	}
	return 0;
}