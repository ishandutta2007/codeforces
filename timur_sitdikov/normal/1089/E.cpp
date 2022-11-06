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

const int MAXN = 10;

vi v[8];

int r[164], c[164];


void solve(){
	v[0] = {0, 1, 2, 3, 4, 5, 6, 7};
	v[1] = {15, 14, 13, 12, 11, 10, 9, 8};
	v[2] = {16, 17, 18, 19, 20, 21, 22, 23};
	v[3] = {31, 30, 29, 28, 27, 26, 25, 24};
	v[4] = {32, 33, 34, 35, 36, 37, 38, 39};
	v[5] = {47, 46, 45, 44, 43, 42, 41, 40};
	v[6] = {48, 55, 54, 53, 52, 51, 50, 49};
	v[7] = {57, 56, 58, 59, 60, 61, 62, 63};
	
	int k;
	cin >> k;
	//cout << k << endl;
	if (k == 51) {
		swap(v[6][6], v[6][7]);
	}
	REP(i, 0, 8) {
		REP(j, 0, 8) {
			r[v[i][j]] = i;
			c[v[i][j]] = j;
		}
	}
	REPN(i, 0, k - 2) {
		putchar(r[i] + 'a');
		putchar(c[i] + '1');
		putchar(' ');
	}
	if (c[k - 2] == 7) {
		printf("g8");
	} else if (r[k - 2] == 7) {
		printf("h7");
	} else {
		putchar('h');
		putchar(c[k - 2] + '1');
	}
	printf(" h8\n");
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