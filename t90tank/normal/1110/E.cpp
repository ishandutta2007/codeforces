#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
using pii = pair<int,int>; 
using db = double; 
using vi = vector<int>; 
using vl = vector<ll>; 
#define fir first
#define sec second
#define pb push_back
#define lowbit(x) ((x)&(-(x))) 

const int maxn = 100006; 
int n; 
int c[maxn]; 
int t[maxn]; 
vl a, b;  

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &c[i] ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &t[i] ); 
	for (int i = 1; i < n; ++i) {
		a.pb(c[i+1]-c[i]); 
		b.pb(t[i+1]-t[i]); 
	}
	sort(a.begin(), a.end()); 
	sort(b.begin(), b.end()); 
	if (c[1] != t[1] || c[n] != t[n]) {
		puts( "No" ); 
		return 0; 
	}
	for (int i = 0; i < n-1; ++i) 
		if (a[i] != b[i]) {
			puts( "No" ); 
			return 0; 
		}
	puts( "Yes" ); 
}