#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = int(1E9) + 7;
const int MAXA = 1000000;
const int MAXN = 100000;

inline int add(int x, int y) {x += y; return x >= MOD ? x - MOD : x;}
inline int sub(int x, int y) {x -= y; return x < 0 ? x + MOD : x;}
inline int mul(int x, int y) {return (int) (1LL * x * y % MOD);}

int pow_mod(int b, int p) {
	int ret = 1;
	for(int i=p;i;i>>=1,b=mul(b,b))
		if( i & 1 ) ret = mul(ret, b);
	return ret;
}

int fct[MAXA + 5], ifct[MAXA + 5];
int comb(int n, int m) {
	if( m < 0 || n < m ) return 0;
	else return mul(fct[n], mul(ifct[m], ifct[n-m]));
}

bool tag[MAXA + 5], nprm[MAXA + 5];
vector<int>dv[MAXA + 5];
int prm[MAXA + 5], phi[MAXA + 5], pcnt;
void init() {
	for(int i=1;i<=MAXA;i++)
		for(int j=i;j<=MAXA;j+=i)
			if( tag[j] ) dv[j].push_back(i);
	
	phi[1] = 1;
	for(int i=2;i<=MAXA;i++) {
		if( !nprm[i] ) prm[++pcnt] = i, phi[i] = i - 1;
		for(int j=1;i*prm[j]<=MAXA;j++) {
			nprm[i*prm[j]] = true;
			if( i % prm[j] == 0 ) {
				phi[i*prm[j]] = phi[i] * prm[j];
				break;
			} else phi[i*prm[j]] = phi[i] * phi[prm[j]];
		}
	}
	
	fct[0] = 1; for(int i=1;i<=MAXA;i++) fct[i] = mul(fct[i - 1], i);
	ifct[MAXA] = pow_mod(fct[MAXA], MOD - 2);
	for(int i=MAXA-1;i>=0;i--) ifct[i] = mul(ifct[i + 1], i + 1);
}

int sum[MAXA + 5], ans, n, k, q;
int get(int x) {return mul(comb(sum[x], k), phi[x]);}

int a[MAXN + 5], c[MAXN + 5];
int main() {
	scanf("%d%d%d", &n, &k, &q);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]), tag[a[i]] = true;
	for(int j=1;j<=q;j++) scanf("%d", &c[j]), tag[c[j]] = true;
	init();
	
	for(int i=1;i<=n;i++) {
		for(unsigned p=0;p<dv[a[i]].size();p++) {
			int x = dv[a[i]][p];
			ans = sub(ans, get(x)), sum[x]++, ans = add(ans, get(x)); 
		}
	}
	for(int j=1;j<=q;j++) {
		for(unsigned p=0;p<dv[c[j]].size();p++) {
			int x = dv[c[j]][p];
			ans = sub(ans, get(x)), sum[x]++, ans = add(ans, get(x)); 
		}
		printf("%d\n", ans); 
	}
}