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

const int maxn = 2000000; 
const int oo = 1000000000; 

int n; 
int p[maxn], s[maxn], a[maxn]; 
vi e[maxn]; 

int main() {
	scanf( "%d", &n ); 
	for (int i = 2; i <= n; ++i) {
		scanf( "%d", &p[i] ); 
		e[p[i]].pb(i); 
	}
	for (int i = 1; i <= n; ++i) scanf( "%d", &s[i] ); 
	a[1] = s[1]; 
	for (int i = 2; i <= n; ++i) 
		if (s[i] == -1) {
			a[i] = oo; 
			for (auto j : e[i]) 
				a[i] = min(a[i], s[j]-s[p[i]]); 
			if (e[i].empty()) a[i] = 0; 
			s[i] = s[p[i]] + a[i]; 
		}
		else a[i] = s[i]-s[p[i]]; 
	ll sum = 0; 
	for (int i = 1; i <= n; ++i) 
		if (a[i] < 0) { puts( "-1" ); return 0; }
		else sum += a[i]; 
	printf( "%lld\n", sum ); 
}