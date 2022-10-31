#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 300000;

int mu[N + 5], prm[N + 5], pcnt;
bool nprm[N + 5];

void init() {	
	mu[1] = 1;
	for(int i=2;i<=N;i++) {
		if( !nprm[i] ) prm[++pcnt] = i, mu[i] = -1;
		for(int j=1;i*prm[j]<=N;j++) {
			nprm[i*prm[j]] = true;
			if( i % prm[j] == 0 ) {
				mu[i*prm[j]] = 0;
				break;
			} else mu[i*prm[j]] = -mu[i];
		}
	}
}

int g[N + 5], f[N + 5], s[N + 5], a[N + 5], n;
int main() {
	scanf("%d", &n), init();
	for(int i=1,x;i<=n;i++)
		scanf("%d", &x), a[x]++;
	
	for(int i=1;i<=N;i++)
		for(int j=i;j<=N;j+=i)
			s[i] += a[j];
	for(int i=1;i<=N;i++)
		for(int j=i;j<=N;j+=i)
			f[j] += mu[i]*s[i];
	
	for(int i=N;i>=1;i--) {
		if( a[i] ) g[i] = 1;
		else {
			g[i] = N + 5;
			for(int j=2*i;j<=N;j+=i)
				if( f[j/i] ) g[i] = min(g[i], g[j] + 1);
		}
	}
	
	if( g[1] == N + 5 ) puts("-1");
	else printf("%d\n", g[1]);
}