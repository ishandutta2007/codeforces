#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;

multiset<pair<int, int> > se;

int inf = 2e9 + 5;
long long ans[N];


int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<pair<int, pair<int, int> > > ev;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		ev.pb(mp(x - k + 1, mp(y - k + 1, 1)));
		ev.pb(mp(x - k + 1, mp(y + 1, -1)));
		ev.pb(mp(x + 1, mp(y - k + 1, -1)));
		ev.pb(mp(x + 1, mp(y + 1, 1)));
	}
	sort(ev.begin(), ev.end());
	
	for (int i = 0; i < ev.size(); i++) {
		pair<int, int> t = ev[i].S;
		pair<int, int> ne = mp(t.F, -t.S);

		auto it = se.find(ne);
		if (it != se.end()) {
			se.erase(it);
		} else se.insert(t);

		int mul = 0;
		if (i + 1< ev.size()) mul = ev[i + 1].F - ev[i].F;
		if (mul > 0) {
			int bal = 0;

			int prev = -inf;
			for (auto it = se.begin(); it != se.end(); ++it) {
				if (prev > -inf) ans[bal] += ((it -> F) - prev) * 1ll * mul;
				bal += (it -> S);
				prev = (it -> F);
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";

	return 0;
}