#include <cstdio>

const int MAXK = 1000000;
const int MOD = int(1E9) + 7;

inline int add(int x, int y) {return (x + y >= MOD ? x + y - MOD : x + y);}
inline int sub(int x, int y) {return (x - y < 0 ? x - y + MOD : x - y);}
inline int mul(int x, int y) {return 1LL * x * y % MOD;}

int pow_mod(int b, int p) {
	int ret = 1;
	for(int i=p;i;i>>=1,b=mul(b,b))
		if( i & 1 ) ret = mul(ret, b);
	return ret;
}

bool nprm[MAXK + 5];
int sp[MAXK + 5], prm[MAXK + 5], ifct[MAXK + 5], pcnt;
void init(int k) {
	pcnt = 0;
	for(int i=2;i<=k+1;i++) {
		if( !nprm[i] )
			prm[++pcnt] = i, sp[i] = pow_mod(i, k);
		for(int j=1;i*prm[j]<=k;i++) {
			nprm[i*prm[j]] = true;
			sp[i*prm[j]] = mul(sp[i], sp[prm[j]]);
			if( i % prm[j] == 0 ) break;
		}
	}
	sp[1] = 1;
	for(int i=1;i<=k+1;i++)
		sp[i] = add(sp[i], sp[i - 1]);
	
	ifct[k+1] = 1;
	for(int i=1;i<=k+1;i++)
		ifct[k+1] = mul(ifct[k+1], i);
	ifct[k+1] = pow_mod(ifct[k+1], MOD - 2);
	for(int i=k;i>=0;i--)
		ifct[i] = mul(ifct[i+1], i + 1);
}
int a[MAXK + 5], b[MAXK + 5];
int solve(int n, int k) {
	init(k);
	a[0] = sub(n, 0);
	for(int i=1;i<=k+1;i++) a[i] = mul(a[i-1], sub(n, i));
	b[k + 1] = sub(n, k + 1);
	for(int i=k;i>=0;i--) b[i] = mul(b[i+1], sub(n, i));
	
	int ret = 0;
	for(int i=0;i<=k+1;i++) {
		int del = sp[i];
		if( i != 0 )
			del = mul(del, mul(a[i - 1], ifct[i]));
		if( i != k + 1 )
			del = mul(del, mul(b[i + 1], ifct[k + 1 - i]));
		
		ret = ((k + 1 - i) & 1) ? sub(ret, del) : add(ret, del);
	}
	return ret;
}
int main() {
	int n, k; scanf("%d%d", &n, &k);
	printf("%d\n", solve(n, k));
}