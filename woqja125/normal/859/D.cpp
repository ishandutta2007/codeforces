#include<stdio.h>
int in[65][65];
long double p[10][70];
long double e[10][70];
int w[10][70];
void fill(int r, int u, int v, int x){
	for(int i=u; i<u+x; i++){
		for(int j=v; j<v+x; j++){
			p[r][i] += p[r-1][j] * in[i][j] / 100.0;
		}
		p[r][i] *= p[r-1][i];
		e[r][i] = e[r-1][i] + p[r][i] * (1<<(r-1));
	}
	for(int i=v; i<v+x; i++){
		for(int j=u; j<u+x; j++){
			p[r][i] += p[r-1][j] * in[i][j] / 100.0;
		}
		p[r][i] *= p[r-1][i];
		e[r][i] = e[r-1][i] + p[r][i] * (1<<(r-1));
	}
	long double mu=0, mv=0;
	for(int i=u; i<u+x; i++){
		if(mu < e[r-1][i]) mu = e[r-1][i];
	}
	for(int i=v; i<v+x; i++){
		if(mv < e[r-1][i]) mv = e[r-1][i];
	}
	for(int i=u; i<u+x; i++) e[r][i] += mv;
	for(int i=v; i<v+x; i++) e[r][i] += mu;
}
int main(){
	int n, N;
	scanf("%d", &n);
	N = 1<<n;
	for(int i=1; i<=N; i++)for(int j=1; j<=N; j++)scanf("%d", &in[i][j]);
	for(int i=1; i<=N; i++) p[0][i] = 1, w[0][i] = i;
	double ans = 0;
	for(int i=1; i<=n; i++){
		int x = 1<<(i-1);
		for(int j=1; j<=N; j+=2*x){
			int u = j;
			int v = j + x;
			fill(i, u, v, x);
			int a = w[i-1][u];
			int b = w[i-1][v];
			if(p[i][a] > p[i][b]) w[i][u] = a;
			else w[i][u] = b;
		}
	}
	for(int i=1; i<=N; i++) if(ans < e[n][i]) ans = e[n][i];
	printf("%.15lf\n", ans);
	return 0;
}