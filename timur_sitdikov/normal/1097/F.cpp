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

const int MAXN = 1e5 + 5;
const int MAXB = 7000;
const int MAXBITS = 16;
const int MAXSZ = (MAXB + 1 + MAXBITS - 1) / MAXBITS;
const int MAXQ = 1e6 + 5;

int bit_cnt[1 << MAXBITS];

void calc_bit_cnt() {
	REP(i, 1, 1 << MAXBITS) {
		bit_cnt[i] = bit_cnt[i >> 1] + (i & 1);
	}
}

struct my_bitset {
	unsigned short v[MAXSZ];
	
	void set_zero() {
		REP(i, 0, MAXSZ) {
			v[i] = 0;
		}
	}
	
	int get_cnt() {
		int ans = 0;
		REP(i, 0, MAXSZ) {
			ans += bit_cnt[v[i]];
		}
		return ans;
	}
	
	void set_bit(int b) {
		v[b / MAXBITS] |= (1 << (b % MAXBITS));
	}
	
	int get_bit(int b) {
		int c = v[b / MAXBITS] & (1 << (b % MAXBITS));
		return c ? 1 : 0;
	}
};

void my_xor(my_bitset &a, my_bitset &b, my_bitset &c) {
	REP(i, 0, MAXSZ) {
		c.v[i] = (a.v[i] ^ b.v[i]);
	}
}

void my_and(my_bitset &a, my_bitset &b, my_bitset &c) {
	REP(i, 0, MAXSZ) {
		c.v[i] = (a.v[i] & b.v[i]);
	}
}

my_bitset qq[MAXN];
my_bitset divs[MAXB + 1];
my_bitset multiples[MAXB + 1];
my_bitset tmp_b;
int _legendre[MAXB + 1];

char ans[MAXQ];
int top_ans;

int get_ans(int ind, int v) {
	
}

void solve(){
	calc_bit_cnt();
	REPN(i, 2, MAXB) {
		for(int j = i * i; j <= MAXB; j += i * i) {
			_legendre[j] = 1;
		}
	}
	REPN(i, 1, MAXB) {
		for(int j = i; j <= MAXB; j += i) {
			divs[j].set_bit(i);
			if (!_legendre[j / i]) {
				multiples[i].set_bit(j);
			}
		}
	}
	
	int n, q;
	scanf("%d%d", &n, &q);
	//printf("%d\n", n);
	REP(i, 0, q) {
		int t, x, y, z, v;
		scanf("%d", &t);
		//printf("%d\n", t);
		if (t == 1) {
			scanf("%d%d", &x, &v);
			qq[x] = divs[v];
		} else if (t == 2) {
			scanf("%d%d%d", &x, &y, &z);
			my_xor(qq[y], qq[z], qq[x]);
		} else if (t == 3) {
			scanf("%d%d%d", &x, &y, &z);
			my_and(qq[y], qq[z], qq[x]);
		} else if (t == 4) {
			scanf("%d%d", &x, &v);
			my_and(qq[x], multiples[v], tmp_b);
			int c = (tmp_b.get_cnt() & 1);
			ans[top_ans++] = '0' + c;
			
			
			/*for(int i = 1; i < 100; i++) {
				printf("%d", qq[x].get_bit(i));
			}
			putchar('\n');*/
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