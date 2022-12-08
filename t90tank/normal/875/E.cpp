#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int maxn = 100006; 
const int D = 22; 

int n, s1, s2; 
int x[maxn]; 
set<int> S; 
int no[maxn]; 
int p[maxn]; 
int a[D][maxn]; 
int f[maxn]; 

int Abs(int x) {
	return max(x, -x); 
}

void Init(int dist) {
	S.clear(); 
	for (int i = 1; i <= n; ++i) S.insert(i); 
	S.insert(n+1); 
	int L = 1; 
	int R = 1; 
	S.erase(no[1]); 
	//for (int i = 1; i <= n; ++i) cout<<no[i]<<' '; puts( "" ); 
	for (int i = 1; i <= n; ++i) {
		while (Abs(x[no[L]]-x[no[i]]) > dist) {
			S.insert(no[L]); 
			L++; 
		}
		while (R < n && Abs(x[no[R+1]]-x[no[i]]) <= dist) {
			R++; 
			S.erase(no[R]); 
		}
		//cout<<L<<','<<R<<endl; 
		auto r = S.lower_bound(no[i]); 
		p[no[i]] = *r; 
	}
	//cout<<dist<<endl;
	//for (int i = 1; i <= n; ++i) cout<<p[i]<<' '; puts( "" ); 
}

int Maxint(int l, int r) {
	if (l > r) return 0;
	int k = 31 - __builtin_clz(r+1-l); 
	return max(a[k][l], a[k][r-(1<<k)+1]); 
}

bool cmp(int a, int b) {
	return x[a] < x[b]; 
}

int main() {
	scanf( "%d%d%d", &n, &s1, &s2 ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &x[i] ); 
	for (int i = 1; i <= n; ++i) no[i] = i; 
	sort(no+1, no+n+1, cmp); 
	int l = Abs(s1-s2)-1, r = 1000000007; 
	while (l + 1 < r) {
		int m = (l + r) / 2; 
		Init(m); 
		f[n] = n; 
		for (int i = 0; i < D; ++i) a[i][n] = n; 
		for (int i = n-1; i >= 1; --i) {
			f[i] = Maxint(i+1, p[i]-1); 
			a[0][i] = f[i]; 
			for (int k = 1; i+(1<<k)-1 <= n; ++k) 
				a[k][i] = max(a[k-1][i], a[k-1][i+(1<<(k-1))]); 
		}
		//for (int i = 1; i <= n; ++i) cout<<f[i]<<' '; puts( "" ); 
		int ans = 0; 
		for (int i = 1; i <= n && Abs(x[i]-s1) <= m; ++i) ans = max(ans, f[i]); 
		for (int i = 1; i <= n && Abs(x[i]-s2) <= m; ++i) ans = max(ans, f[i]); 
		if (ans == n) r = m; 
		else l = m; 
	}
	cout<<r<<endl; 
}