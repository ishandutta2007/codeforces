#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int maxn = 200006; 

struct data {
	int a, b, w; 
}q[maxn]; 

int f[maxn], s[maxn]; 
int n, m; 

bool cmp(data x, data y) {
	return x.w > y.w; 
}

int getf(int v) {
	if (f[v] == v) return v; 
	f[v] = getf(f[v]); 
	return f[v]; 
}

int main() {
	scanf( "%d%d", &n, &m ); 
	for (int i = 1; i <= m; ++i) scanf( "%d%d%d", &q[i].a, &q[i].b, &q[i].w ); 
	sort(q+1, q+m+1, cmp); 
	for (int i = 1; i <= n; ++i) {
		f[i] = i; 
		s[i] = 1; 
	}
	ll ans = 0; 
	for (int i = 1; i <= m; ++i) {
		int fa = getf(q[i].a); 
		int fb = getf(q[i].b); 
		if (fa == fb) {
			if (s[fa] == 1) {
				s[fa]--; 
				ans += q[i].w; 
			}
		}
		else if (s[fa] + s[fb] > 0) {
			s[fb] = s[fa] + s[fb] - 1; 
			f[fa] = fb; 
			ans += q[i].w; 
		}		
	}
	cout<<ans<<endl; 
}