#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int maxn = 100; 

struct data {
	db a, b; 
	data() {a = 0, b = 0;}
	data(db a, db b):a(a),b(b) {}
	data operator+(data p) const {
		return {a+p.a, b+p.b}; 
	}
	data operator*(db p) const {
		return {a*p, b*p}; 
	}
}; 

int n, R; 
int f[maxn], s[maxn]; 
db p[maxn]; 
data dp[maxn][20000]; 
db x; 

data Judge(data u) {
	if (u.a * x + u.b <= x) return u; 
	return {1,0}; 
}

int main() {
	scanf( "%d%d", &n, &R ); 
	db sf = 0; 
	for (int i = 1; i <= n; ++i) {
		db P; 
		scanf( "%d%d%lf", &f[i], &s[i], &P ); 
		p[i] = db(P)/100; 
		sf += f[i]; 
	}
	db l = sf, r = 1e9; 
	for (int _ = 0; _ < 60; _++) {
		x = (l + r) / 2; 
		memset(dp, 0, sizeof(dp)); 
		for (int i = n-1; i >= 0; --i) 
			for (int j = 0; j <= R; ++j) {
				data tmp;
				//cout<<i<<' '<<j<<endl;  
				if (j + f[i+1] <= R) tmp = tmp + (dp[i+1][j+f[i+1]] + data(0,f[i+1])) * p[i+1]; 
				else tmp = tmp + data(1,f[i+1]) * p[i+1]; 
				if (j + s[i+1] <= R) tmp = tmp + (dp[i+1][j+s[i+1]] + data(0,s[i+1])) * (1-p[i+1]); 
				else tmp = tmp + data(1,s[i+1]) * (1-p[i+1]); 
				dp[i][j] = Judge(tmp); 
			}
		data tmp = dp[0][0]; 
		//db y = tmp.b / (1-tmp.a); 
		//cout<<x<<' '<<y<<endl; 
		if (abs(1-tmp.a) < 1e-9) l = x; else r = x; 
	}
	printf( "%.12f\n", l ); 
}