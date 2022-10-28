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

struct FT {
		vector<ll> s;
			FT(int n) : s(n) {}
				void update(int pos, ll dif) { // a[pos] += dif
							for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
								}
					ll query(int pos) { // sum of values in [0, pos)
								ll res = 0;
										for (; pos > 0; pos &= pos - 1) res += s[pos-1];
												return res;
													}
						int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
									// Returns n if no sum is >= sum, or -1 if empty sum is.
									if (sum <= 0) return -1;
											int pos = 0;
													for (int pw = 1 << 25; pw; pw >>= 1) {
																	if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
																						pos += pw, sum -= s[pos-1];
																			}
															return pos;
																}
};
///////
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n,m;cin>>n>>m;
	bool chk[n+1]={false};
	set<int> s[100];
	char c[n+1];
	rep(i,n){
		cin>>c[i+1];
		s[c[i+1]-'0'].insert(i+1);
	}
	FT t(n+1);
	repA(i,1,n) t.update(i,1);
	rep(i,m){
		int l,r;char c;
		cin>>l>>r>>c;
		int z = c-'0';
		l = t.lower_bound(l);
		r = t.lower_bound(r);
		auto it = s[z].lower_bound((l));
		auto it2 = s[z].upper_bound((r));
		auto it3 =it;
		while(it!=it2){
			t.update(*it,-1);chk[*it] = true;it++;
		}
		s[z].erase(it3,it2);
	}
	repA(i,1,n){
		if(!chk[i]) cout<<c[i];
	}
	return 0;
}

//