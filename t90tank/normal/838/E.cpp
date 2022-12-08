#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
using pii = pair<int,int>; 
using db = double; 
using vi = vector<int>; 
#define fir first
#define sec second
#define pb push_back
#define lowbit(x) ((x)&(-(x))) 

const int maxn = 5006; 

int n; 
int x[maxn], y[maxn]; 
db f[2][maxn][2]; 

db sqr(db x) {return x*x;}

db dist(int a, int b) {
	return sqrt(sqr(db(x[a])-db(x[b]))+sqr(db(y[a])-db(y[b]))); 
}

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) scanf("%d%d", &x[i], &y[i]); 
	for (int i = n+1; i <= n*2; ++i) {
		x[i] = x[i-n]; y[i] = y[i-n]; 
	}
	memset(f, 0, sizeof(f)); 
	int t = 0; 
	for (int l = 1; l <= n-1; ++l) {
		memset(f[1-t],0,sizeof(f[1-t])); 
		for (int i = 1; i+l <= n*2; ++i) {
			int j = i+l; 
			f[1-t][i][0] = max(f[t][i+1][0]+dist(i,i+1),f[t][i+1][1]+dist(i,j)); 
			f[1-t][i][1] = max(f[t][i][0]+dist(i,j),f[t][i][1]+dist(j-1,j)); 
		}
		t = 1-t; 
	}
	db ans = 0; 
	for (int i = 1; i <= n; ++i) ans = max(ans, max(f[t][i][0],f[t][i][1])); 
	printf( "%.12f\n", ans ); 
}