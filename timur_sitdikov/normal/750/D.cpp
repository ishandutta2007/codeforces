#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
#define xx real()
#define yy imag()

#define REP(i, a, b) for(int i = (a); i < (int)(b); i++)
#define REPN(i, a, b) for(int i = (a); i <= (int)(b); i++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))
#define _1 first
#define _2 second

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 640, MAXMOVE = 6;
const int OFFSET = 320;

int di[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dj[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int used[MAXN][MAXN], used1[MAXN][MAXN];

int len[MAXN], n;

void solve(){
	scanf("%d", &n);
	REP(i, 0, n){
		scanf("%d", &len[i]);
	}
	int i0 = OFFSET, j0 = OFFSET, k0 = 1 - (n % 2);
	used[i0][j0] = 1;
	
	len[0]--;
	
	//printf("%d %d %d\n", i0, j0, k0);
	
	for(int l = n - 1; l >= 0; l--){
		REPN(a, 1, len[l]){
			used[i0 - di[k0] * a][j0 - dj[k0] * a] = 1;
		}
		i0 = i0 - di[k0] * len[l];
		j0 = j0 - dj[k0] * len[l];
		
		k0 = (k0 + 7) % 8;
		
		//printf("%d %d %d\n", i0, j0, k0);
		
		REP(i, 0, MAXN){
			REP(j, 0, MAXN){
				used1[i][j] = 0;
			}
		}
		
		if (l == 0){
			break;
		}
		
		
		
		REP(i, 0, MAXN){
			REP(j, 0, MAXN){
				if (used[i][j]){
					used1[i][j] = 1;
					int i1, j1;
					if (k0 == 2 || k0 == 6){
						i1 = 2 * i0 - i;
						j1 = j;
					} else if (k0 == 0 || k0 == 4){
						i1 = i;
						j1 = 2 * j0 - j;
					} else if (k0 == 1 || k0 == 5){
						i1 = i0 - j0 + j;
						j1 = i + j - i1;
					} else if (k0 == 3 || k0 == 7){
						i1 = i0 + j0 - j;
						j1 = i1 - i + j;
					}
					//printf("%d %d %d %d %d %d %d\n", k0, i0, j0, i, j, i1, j1);
					if (i1 >= 0 && i1 < MAXN && j1 >= 0 && j1 < MAXN){
						used1[i1][j1] = 1;
					}
				}
			}
		}
		
		REP(i, 0, MAXN){
			REP(j, 0, MAXN){
				used[i][j] = used1[i][j];
			}
		}
	}
	
	int ans = 0;
	REP(i, 0, MAXN){
		REP(j, 0, MAXN){
			//printf("%d", used[i][j]);
			ans += used[i][j];
		}
		//putchar('\n');
	}
	cout << ans << endl;
}   

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}