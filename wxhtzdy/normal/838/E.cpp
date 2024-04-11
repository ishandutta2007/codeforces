#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 2500 + 5;
int n;
double sd[N][N][4];
LL px[N], py[N];
double dis(int i, int j){
	return sqrt((px[i] - px[j])*(px[i] - px[j]) + (py[i] - py[j])*(py[i] - py[j]));
}
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++ i){
		scanf("%I64d%I64d", &px[i], &py[i]);
	}
	for(int i = 2; i <= n; ++ i){
		for(int j = 0; j < n; ++ j){
			sd[j][i][0] = dis(j, (j+1)%n) + max(sd[(j+1)%n][i-1][0], sd[(j+1)%n][i-1][1]);
			sd[j][i][1] = dis(j, (j+i-1)%n) + max(sd[(j+i-1)%n][i-1][2], sd[(j+i-1)%n][i-1][3]);
			sd[j][i][2] = dis(j, (j-1+n)%n) + max(sd[(j-1+n)%n][i-1][2], sd[(j-1+n)%n][i-1][3]);
			sd[j][i][3] = dis(j, (j-i+1+n)%n) + max(sd[(j-i+1+n)%n][i-1][0], sd[(j-i+1+n)%n][i-1][1]);
		}
	}
	double ans = 0;
	for(int i = 0; i < n; ++ i){
		ans = max(ans, sd[i][n][0]);
		ans = max(ans, sd[i][n][1]);
		ans = max(ans, sd[i][n][2]);
		ans = max(ans, sd[i][n][3]);
	}
	printf("%.10f\n", ans);
}