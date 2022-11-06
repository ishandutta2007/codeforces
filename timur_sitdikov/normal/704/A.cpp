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
const int MAXN = 3e5 + 5;
const ll MOD = 1e9 + 7;

int mes_ind[MAXN], used[MAXN];
vi vv[MAXN];
int cnt = 0, top = 0, cur = 0, rr = 0;

void solve(){
	int n, q, t, x;
	scanf("%d%d", &n, &q);
	REP(i, 0, q){
		scanf("%d%d", &t, &x);
		if (t == 1){
			mes_ind[top] = x;
			vv[x].pb(top);
			top++;
		} else if (t == 2){
			for(int i = SZ(vv[x]) - 1; i >= 0 && !used[vv[x][i]]; i--){
				rr++;
				used[vv[x][i]] = 1;
			}
		} else if (t == 3){
			for(; cur < x; cur++){
				if (!used[cur]){
					used[cur] = 1;
					rr++;
				}
			}			
		}
		printf("%d\n", top - rr);
	}
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