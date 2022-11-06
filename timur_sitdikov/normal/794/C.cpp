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

#define x1 gray_cat_x1
#define y1 gray_cat_y1

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 3e5 + 5;

int cnt[2][200];

int tot[2], full[2];

char cc[2][MAXN];

char ans[MAXN];

void solve(){
	int n;
	scanf("%s%s", &cc[0][0], &cc[1][0]);
	n = strlen(cc[0]);
	
	REP(i, 0, 2){
		REP(j, 0, n){
			cnt[i][cc[i][j]]++;
		}
	}
	
	tot[1] = n / 2;
	tot[0] = n - tot[1];
	full[0] = full[1] = n;
	
	while(full[0] > tot[0]){
		for(int i = 'z'; ; i--){
			if (cnt[0][i]){
				cnt[0][i]--;
				full[0]--;
				break;
			}
		}
	}
	
	while(full[1] > tot[1]){
		for(int i = 'a'; ; i++){
			if (cnt[1][i]){
				cnt[1][i]--;
				full[1]--;
				break;
			}
		}
	}
	
	int l = 0, r = n - 1;
	REP(k, 0, n){
		int mn[2], mx[2];
		mn[0] = mn[1] = 'z';
		mx[0] = mx[1] = 'a';
		REP(j, 0, 2){
			REPN(i, 'a', 'z'){
				if (cnt[j][i]){
					mn[j] = min(mn[j] , i);
				}
				if (cnt[j][i]){
					mx[j] = max(mx[j], i);
				}
			}
		}
		if (k % 2 == 0){
			if (mn[0] < mx[1]){
				ans[l++] = mn[0];
				cnt[0][mn[0]]--;
			} else {
				ans[r--] = mx[0];
				cnt[0][mx[0]]--;
			}
		} else {
			if (mn[0] < mx[1]){
				ans[l++] = mx[1];
				cnt[1][mx[1]]--;
			} else {
				ans[r--] = mn[1];
				cnt[1][mn[1]]--;
			}
		}
	}
	printf("%s\n", ans);
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