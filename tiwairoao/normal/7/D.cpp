#include<cstdio>
#include<cstring>
typedef unsigned long long ull;
const int MAXN = 5000000;
const int MOD = 19260817;
ull pw[MAXN + 5][2];
ull ph[MAXN + 5][2], sh[MAXN + 5][2];
void Init() {
	pw[0][0] = pw[0][1] = 1;
	for(int i=1;i<=MAXN;i++) {
		pw[i][0] = pw[i-1][0] * 131;
		pw[i][1] = pw[i-1][1] * 131 % MOD;
	}
}
void CalHash(char *S, int lenS) {
	ph[1][0] = ph[1][1] = S[1];
	for(int i=2;i<=lenS;i++) {
		ph[i][0] = ph[i-1][0] * 131 + S[i];
		ph[i][1] = (ph[i-1][1] * 131 + S[i]) % MOD;
	}
	sh[lenS][0] = sh[lenS][1] = S[lenS];
	for(int i=lenS-1;i>=1;i--) {
		sh[i][0] = sh[i+1][0] * 131 + S[i];
		sh[i][1] = (sh[i+1][1] * 131 + S[i]) % MOD;
	}
}
ull GetHashP(int l, int r, int t) {
	if( t == 1 ) return (ph[r][t]+MOD-ph[l-1][t]*pw[r-l+1][t]%MOD+MOD) % MOD;
	else return ph[r][t] - ph[l-1][t]*pw[r-l+1][t];
}
ull GetHashS(int l, int r, int t) {
	if( t == 1 ) return (sh[l][t]+MOD-sh[r+1][t]*pw[r-l+1][t]%MOD+MOD) % MOD;
	else return sh[l][t] - sh[r+1][t]*pw[r-l+1][t];
}
char S[MAXN + 5];
int deg[MAXN + 5];
int main() {
	scanf("%s", S+1);
	int lenS = strlen(S+1);
	Init(); CalHash(S, lenS);
	ull ans = 0;
	for(int i=1;i<=lenS;i++) {
		if( GetHashP(1, i/2, 0) == GetHashS((i+3)/2, i, 0) ) {
			if( GetHashP(1, i/2, 1) == GetHashS((i+3)/2, i, 1) ) {
				deg[i] = deg[i/2] + 1;
				ans += deg[i];
			}
		}
	}
	printf("%I64d\n", ans);
}