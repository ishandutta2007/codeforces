#include<bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; ++ i)
#define rev_rep(i, a, n) for(int i = (int) n - 1; i >= a; -- i)
#define clr(a, h) memset(a, (h), sizeof(a))
#define transfer(a, h) memcpy(a, (h), sizeof (a))
#define foreach(e, x) for(__typeof(x.begin()) e = x.begin(); e != x.end(); ++ e)
#define all(x) x.begin(), x.end()
#define SZ(x) (int(x.size()))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define de(x) cerr << #x << "=" << x << endl
#define two(x) (1 << (x))
#define twoL(x) (1ll << (x))
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pi;
typedef pair< int , pi> pii;

const int INF = ~0U >> 1;
const int Mod = int(1e9) + 7;

inline void addMod(int &x, int y){
	x += y;
	if (x >= Mod) x -= Mod;
}

inline int powMod(int a, int x){
	int ret = 1;
	for (; x; x >>= 1, a = 1ll * a * a % Mod)
		if (x & 1) ret = 1ll * ret * a % Mod;
	return ret;
}

const int N = 100010;

int n, a[N], q, x;

int main(){
	scanf("%d", &n);
	rep(i, 0, n) scanf("%d", a + i);
	sort(a, a + n);
	scanf("%d", &q);
	rep(i, 0, q){
		scanf("%d", &x);
		printf("%d\n", upper_bound(a, a + n, x) - a);
	}
}