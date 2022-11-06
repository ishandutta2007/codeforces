#include <bits/stdc++.h>
using namespace std;

#define point complex<double>
#define xx real()
#define yy imag()

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define REP(i, a, b) for((i) = (int)(a); (i) < (int)(b); (i)++)
#define REPN(i, a, b) for((i) = (int)(a); (i) <= (int)(b); (i)++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 1e5 + 5, MAXLOG = 18;
const ll MOD = 1e9 + 7;

int cnt[200];

void solve(){
	int n, i, j, k, l, cnt_odd = 0, len = 0;
	cin >> n;
	REP(i, 0, n){
		cin >> cnt[i];
		len += cnt[i];
		cnt_odd += cnt[i] % 2;
	}
	if (cnt_odd > 1){
		printf("0\n");	
		REP(i, 0, n){
			REP(j, 0, cnt[i]){
				putchar(i + 'a');
			}
		}
		putchar('\n');
		return;
	}
	if (cnt_odd == 0){
		for(i = len; ; i--){
			if (i % 2 == 0 && len % i == 0){
				int fl = 0;
				REP(j, 0, n){
					if (cnt[j] % i){
						fl = 1;
						break;
					}
				}
				if (!fl){
					printf("%d\n", i);
					for(j = 0; j < i / 2; j++){
						for(k = 0; k < n; k++){
							for(l = 0; l < cnt[k] / i; l++){
								putchar(k + 'a');
							}
						}
						for(k = n - 1; k >= 0; k--){
							for(l = 0; l < cnt[k] / i; l++){
								putchar(k + 'a');
							}
						}
					}
					putchar('\n');
					return;
				}
			}		
		}
	}
	// cnt_odd == 1
	int ind = 0;
	REP(ind, 0, n){
		if (cnt[ind] % 2){
			break;
		}
	}
	for(i = len * 2; ; i--){
		if (i % 2 == 0 && len % (i / 2) == 0){
			int fl = 0;
			REP(j, 0, n){
				if (j != ind && cnt[j] % i){
					fl = 1;
					break;
				}
				if (j == ind && (cnt[j] - (i / 2)) % i){
					fl = 1;
					break;
				}
			}
			if (!fl){
				printf("%d\n", i / 2);
				for(j = 0; j < i / 2; j++){					
					for(k = 0; k < n; k++){
						for(l = 0; l < cnt[k] / i; l++){
							putchar(k + 'a');
						}
					}
					putchar(ind + 'a');
					for(k = n - 1; k >= 0; k--){
						for(l = 0; l < cnt[k] / i; l++){
							putchar(k + 'a');
						}
					}					
				}
				putchar('\n');
				return;
			}
		}		
	}
}	

int main(){
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();	
	}
}