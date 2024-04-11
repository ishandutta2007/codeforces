#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MOD = 31607;

int ipow(int a, int n) {
	if (!n) return 1;
	int t = ipow(a,n/2);
	return t*t%MOD*(n%2?a:1)%MOD;
}

int N;
int P[25][25];
int PS[2100000][25];
int PG[2100000];
int PGG[25];
int lo[2100000];
int pcnt[2100000];

int getv() {
	for (int j=0;j<N;j++) PS[0][j] = 1;
	for (int i=1;i<(1<<N);i++) {
		for (int j=0;j<N;j++) PS[i][j] = PS[i&(i-1)][j] * P[lo[i&-i]][j] % MOD;
	}
	for (int i=0;i<N;i++) {
		PGG[i] = 1;
		for (int j=0;j<N;j++) PGG[i] = PGG[i]*P[i][j]%MOD;
	}
	PG[0] = 1;
	for (int i=1;i<(1<<N);i++) {
		PG[i] = PG[i&(i-1)] * PGG[lo[i&-i]] % MOD;
	}
	int ans = 0;
	for (int S=0;S<(1<<N);S++) {
		int tmp = 1;
		for (int j=0;j<N;j++) tmp = tmp*(1-PS[((1<<N)-1)^S][j])%MOD;
		tmp = (pcnt[S]%2?-1:1)*tmp%MOD;
		ans = (ans + tmp * PG[S])%MOD;
	}
	ans = 1-ans;
	return (ans%MOD+MOD)%MOD;
}

int Q[25][25];
int main() {
	scanf("%d",&N);
	int minv = ipow(10000,MOD-2);
	for (int i=0;i<N;i++) {
		for (int j=0;j<N;j++) {
			scanf("%d", &P[i][j]);
			P[i][j] = P[i][j] * minv % MOD;
			Q[i][j] = P[i][j];
		}
	}
	for (int j=0;j<N;j++) lo[1<<j] = j;
	pcnt[0] = 0;
	for (int j=1;j<(1<<N);j++) pcnt[j] = pcnt[j&(j-1)]+1;
	int t1 = getv();
	for (int i=0;i<N;i++) P[i][i] = 1;
	int t2 = getv();
	for (int i=0;i<N;i++) P[i][i] = Q[i][i];
	for (int i=0;i<N;i++) P[i][N-1-i] = 1;
	int t3 = getv();
	for (int i=0;i<N;i++) P[i][i] = 1;
	int t4 = getv();

	int p2 = 1;
	for (int i=0;i<N;i++) p2 = p2 * Q[i][i]%MOD;
	int p3 = 1;
	for (int i=0;i<N;i++) p3 = p3 * Q[i][N-1-i]%MOD;
	int p4 = 1;
	for (int i=0;i<N;i++) for (int j=0;j<N;j++) {
		if (i==j||i+j==N-1) p4 = p4 * Q[i][j]%MOD;
	}
	ll ans = t1 + p2 * (1-t2) %MOD + p3 * (1-t3) %MOD - p4 * (1-t4) %MOD;
	printf("%lld\n",(ans%MOD+MOD)%MOD);

	return 0;
}