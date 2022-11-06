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
const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;

int to[MAXN], len[MAXN], col[MAXN];
vector<int> v;

void solve(){
	int n;
	scanf("%d", &n);
	REPN(i, 1, n){
		scanf("%d", &to[i]);
	}
	int mn = n + 1, mini = 0, cl = 0;
	REPN(i, 1, n){
		if (!col[i]){
			cl++;
			col[i] = cl;
			int cur_len = 0, j;
			for(j = to[i]; !col[j]; j = to[j]){
				cur_len++;
				len[j] = cur_len;
				col[j] = cl;
			}
			if (col[j] == cl){
				if (cur_len - len[j] < mn){
					mn = cur_len - len[j];
					mini = j;					
				}
				v.pb(j);
			}
		}
	}
	int ans = 0;
	REP(i, 0, SZ(v)){
		if (to[v[i]] != mini){
			to[v[i]] = mini;
			ans++;
		}		
	}
	printf("%d\n" ,ans);
	REPN(i, 1, n){
		printf("%d ", to[i]);
	}
	putchar('\n');
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