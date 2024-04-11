#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
const int maxn = 50006; 
#define fir first
#define sec second 

int n, m; 
int T; 
int b[maxn]; 
vi e_[maxn]; 
vi e[2000000]; 
int d[2000000]; 
int x[200000], y[200000]; 

int main() {
	scanf( "%d%d", &n, &m); 
	T = 0; 
	for (int i = 1; i <= m; ++i) {
		scanf( "%d%d", &x[i], &y[i] ); 
		e_[x[i]].pb(y[i]); 
		e_[y[i]].pb(x[i]); 
	}
	for (int i = 1; i <= n; ++i) {
		int l; b[i] = 0; 
		scanf( "%d", &l ); 
		map<int,int> S; 
		int t[30]; 
		for (int j = l; j >= 1; --j) {
			scanf( "%d", &t[j] ); 
			T = max(T, t[j]); 
			S[t[j]] = 0; 
		}
		for (auto j : e_[i]) 
			if (j < i && S.count(b[j]) > 0) 
				S[b[j]]++; 
		pair<int,int> best = *S.begin(); 
		for (auto p : S) 
			if (p.sec < best.sec) best = p; 
		b[i] = best.fir; 
		//cout<<best.sec<<endl; 
	}
	for (int i = 1; i <= n; ++i) printf( "%d ", b[i] ); puts(""); 
	for (int i = 1; i <= m; ++i) {
		int X = b[x[i]], Y = b[y[i]]; 
		if (X < Y) swap(X, Y); 
		if (X != Y) e[X].pb(Y); 
		//cout<<X<<' '<<Y<<endl; 
	}
	for (int i = 1; i <= T; ++i) {
		int s[2]; 
		s[0] = s[1] = 0; 
		for (auto j : e[i]) 
			s[d[j]]++; 
		if (s[0] > s[1]) d[i] = 1; else d[i] = 0; 
		printf( "%d ", d[i]+1 ); 
	}
	puts(""); 
}