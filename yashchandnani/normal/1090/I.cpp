#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define repA(i, a, n) for(int i = a; i <= (n); ++i)
#define repD(i, a, n) for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
#define fill(a) memset(a, 0, sizeof(a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 1e7 + 19;
ll n,l,r,x,y,z,b[maxn],a[maxn];
const ll tmod = (1LL<<32);

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t; cin >> t;
	while(t--){
		cin >> n >> l >> r >> x >> y >> z >> b[0] >> b[1];
		ll mod = r - l + 1;
		//set <ll> neg;
		ll ans = LLONG_MAX;
		a[0] = ((b[0]%mod) + mod)%mod + l;
		a[1] = ((b[1]%mod) + mod)%mod + l;
		ll amin = min(a[0], a[1]);	
		if(a[0] < a[1]) ans = min(ans,a[0]*a[1]);
		repA(i,2,n-1){
			b[i] = b[i-2]*x + b[i-1]*y + z;
			b[i] = ((b[i])%tmod + tmod)%tmod;
		   	a[i] = ((b[i])%mod + mod)%mod + l;
			if(a[i] > amin){
				ans = min(ans,amin*a[i]);
			}else if(a[i] < amin){
				amin = a[i];
			}
			/*
			 *if(a[i] < 0 && !neg.empty()){
			 *    auto low = neg.lower_bound(a[i]);
			 *    if(low == neg.begin()){
			 *        neg.insert(a[i]);
			 *        continue;
			 *    }else low--;
			 *    ans = min((*low)*a[i],ans);
			 *}
			 *if(a[i] < 0) neg.insert(a[i]);
			 */
		}
		int mi = -1;
		for(int i=n-1;i>=0;i--){
			if(mi != -1 && a[i]<0){
				ll ai = -a[i];
				if(mi<ai){
					ans = min(ans, ai*mi);
				}
			}
			if(a[i]<0){
				ll ai = -a[i];
				if(mi == -1){
					mi = ai;
				}else if(mi > ai){
					mi = ai;
				}
			}
		}
		if(ans != LLONG_MAX) cout << ans << endl;
		else cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}