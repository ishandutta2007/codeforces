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
ll p[100009],dp[100009];
int a[100009];
int c,n;
struct Tree {
		typedef int T;
			const T LOW = 1234567890;
				T f(T a, T b) { return min(a, b); }

					int n;
						vi s;
							Tree() {}
								Tree(int m, T def=0) { init(m, def); }
									void init(int m, T def) {
												n = 1; while (n < m) n *= 2;
														s.assign(n + m, def);
																s.resize(2 * n, LOW);
																		for (int i = n; i --> 1; )
																						s[i] = f(s[i * 2], s[i*2 + 1]);
																			}
										void update(int pos, T val) {
													pos += n;
															s[pos] = val;
																	for (pos /= 2; pos >= 1; pos /= 2)
																					s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
																		}
											T query(int l, int r) { return que(1, l, r, 0, n); }
												T que(int pos, int l, int r, int lo, int hi) {
															if (r <= lo || hi <= l) return LOW;
																	if (l <= lo && hi <= r) return s[pos];
																			int m = (lo + hi) / 2;
																					return f(que(2 * pos, l, r, lo, m),
																											que(2 * pos + 1, l, r, m, hi));
																						}
};
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n>>c;
	Tree t(100009);
	repA(i,1,n){
		int x;cin>>x;
		p[i]=p[i-1]+x;
		a[i]=x;
		t.update(i,a[i]);
	}
	repA(i,1,n){
		dp[i] = dp[i-1]+a[i];
		if(i>=c){
			dp[i] = min(dp[i],dp[i-c]+p[i]-p[i-c]-t.query(i-c+1,i+1));
		}
	}
	cout<<dp[n];
	
	
	return 0;
}