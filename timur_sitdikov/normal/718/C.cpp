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
const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;

const int SZ = 2;

struct matrix{
	ll m[SZ][SZ];
	
	matrix(){}
	
	// Get zero matrix
	static matrix get_zero(){
		matrix ans;
		REP(i, 0, SZ){
			REP(j, 0, SZ){
				ans.m[i][j] = 0;
			}
		}
		return ans;
	}

	// Get identity matrix
	static matrix get_one(){
		matrix ans;
		REP(i, 0, SZ){
			REP(j, 0, SZ){
				ans.m[i][j] = (i == j ? 1 : 0);
			}
		}
		return ans;
	}

	// Get 2x2 matrix for Fibonacci calculating
	static matrix get_fib(){
		matrix ans;
		ans.m[0][0] = 0;
		ans.m[0][1] = ans.m[1][0] = ans.m[1][1] = 1;
		return ans;
	}

	matrix& operator = (const matrix &a){
		if (this != &a){
			REP(i, 0, SZ){
				REP(j, 0, SZ){
					this->m[i][j] = a.m[i][j];
				}
			}
		}
		return *this;
	}

	// Matrix addition
	inline matrix operator + (const matrix &b){
		matrix c;
		REP(i, 0, SZ){
			REP(j, 0, SZ){
				c.m[i][j] = (this->m[i][j] + b.m[i][j]) % MOD;
			}
		}
		return c;
	}

	// Matrix multiplication
	inline matrix operator * (const matrix &b){
		matrix c;
		REP(i, 0, SZ){
			REP(j, 0, SZ){
				c.m[i][j] = 0;
				REP(k, 0, SZ){
					c.m[i][j] = (c.m[i][j] + this->m[i][k] * b.m[k][j]) % MOD;
				}			
			}
		}
		return c;
	}

	// Matrix pow_mod
	static matrix pow_mod(const matrix &v, ll st){
		matrix a = v, ans = matrix::get_one();
		for(; st; st /= 2ll){
			if (st & 1){
				ans = ans * a;
			}
			a = a * a;
		}
		return ans;
	}	
};

matrix tt[4 * MAXN], add[4 * MAXN];
int a[MAXN];

void calc(int ind){
	tt[ind] = tt[ind << 1] * add[ind << 1] + tt[(ind << 1) + 1] * add[(ind << 1) + 1];
}

void build(int ind, int tl, int tr){
	add[ind] = matrix::get_one();
	if (tl == tr){
		matrix tmp = matrix::get_fib();
		tt[ind] = matrix::pow_mod(tmp, (ll)a[tl]);		
		return;
	}
	int tm = (tl + tr) >> 1;
	build(ind << 1, tl, tm);
	build((ind << 1) + 1, tm + 1, tr);
	calc(ind);
}

matrix get_val(int ind, int tl, int tr, int l, int r){
	if (l > r){
		return matrix::get_zero();
	}
	if (l == tl && r == tr){
		return tt[ind] * add[ind];
	}
	int tm = (tl + tr) >> 1;
	return (get_val(ind << 1, tl, tm, l, min(r, tm)) + get_val((ind << 1) + 1, tm + 1, tr, max(l, tm + 1), r)) * add[ind];
}

void upd_val(int ind, int tl, int tr, int l, int r, matrix & val){
	if (tl == l && tr == r){		
		add[ind] = add[ind] * val;
		return;
	}
	if (l > r){
		return;
	}
	int tm = (tl + tr) >> 1;
	upd_val(ind << 1, tl, tm, l, min(r, tm), val);
	upd_val((ind << 1) + 1, tm + 1, tr, max(l, tm + 1), r, val);
	calc(ind);
}

void solve(){
	int n, q, t, l, r, x;
	scanf("%d%d", &n, &q);
	REP(i, 0, n){
		scanf("%d", &a[i]);
	}
	build(1, 0, n - 1);
	/*REP(i, 0, 2 * n){
		printf("%d %d %d %lld %lld %lld\n", i, i * 2, i * 2 + 1, tt[i].m[0][1], tt[i * 2].m[0][1], tt[i * 2 + 1].m[0][1]);
	}*/
	REP(i, 0, q){
		scanf("%d%d%d", &t, &l, &r);
		l--;
		r--;
		if (t == 1){
			scanf("%d", &x);
			matrix tmp = matrix::get_fib();
			tmp = matrix::pow_mod(tmp, x);
			upd_val(1, 0, n - 1, l, r, tmp);
		} else if (t == 2){
			matrix tmp = get_val(1, 0, n - 1, l, r);
			printf("%d\n", (int)tmp.m[0][1]);
		}
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