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
int lvl(ll x){
	return 63-__builtin_clzll(x);
}
ll a[3][64];
ll rot(ll x,ll y){
	int l = lvl(x);
	ll st = (1ll<<l);
	ll en = (1ll<<(l+1))-1;
	ll ans = ((x+y)%st+st)%st;
	return ans+st;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int q;cin>>q;
	rep(i,q){
		ll t,x;cin>>t>>x;
		ll k;
		if(t!=3) {cin>>k;
			int l = lvl(x);
			a[t][l]+=k;
			a[t][l]%=(1ll<<l);
		}
		else{
			int l = lvl(x);
			while(l>=0){
				cout<<x<<' ';
				x = rot(x,a[1][l]+a[2][l]);
				x /= 2 ;
				l--;
				if(l>=0) x = rot(x,-a[1][l]); 

			}
			cout<<'\n';
		}
	}

				
	return 0;
}