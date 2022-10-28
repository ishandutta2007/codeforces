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

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n, k; cin >> n >> k;
	int a[n]; rep(i,n) cin >> a[i];
	int b[n]; rep(i,n) cin >> b[i];
	vector <pii> que;
	rep(i,n) que.pb({b[i],a[i]});
	sort(all(que));
	reverse(all(que));
	bool c[k+1]; rep(i,k+1) c[i] = false;
	vi se;
	trav(it,que){
		if(c[it.second] == false){
			c[it.second] = true;
		}else{
			se.pb(it.first);
		}
	}
	ll ans = 0;
	sort(all(se));
	auto it = se.begin();
	repA(i,1,k){
		if(!c[i]) {ans += *it; it++;}
	}
	cout << ans << endl;	
	return 0;
}