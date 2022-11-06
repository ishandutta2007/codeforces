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

const int MAXN = 1e5 + 5;

void solve(){
	int n, cur, d, lim = 1e4;
	char c[10];
	scanf("%d", &n);
	cur = lim;
	REP(i, 0, n){
		scanf("%d%s", &d, &c[0]);
		if (cur == lim || cur == -lim){
			if (c[0] == 'W' || c[0] == 'E'){
				
				printf("NO\n");
				return;
			}
		}
		int dif = 0;
		if (c[0] == 'N'){
			dif = d;
		} else if (c[0] == 'S'){
			dif = -d;
		}
		cur += dif;
		if (abs(cur) > lim){
			//printf("%d %s %d %d\n", d, c, dif, cur);
			printf("NO\n");
			return;
		}
	}
	if (cur != lim){
		
		printf("NO\n");
		return;
	}
	printf("YES\n");
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