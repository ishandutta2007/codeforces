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

int b[2000000]; 
vi q; 

int main() {
	int n, m, k; 
	scanf( "%d%d%d", &n, &m, &k ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &b[i] ); 
	for (int i = 1; i < n; ++i) q.pb(b[i+1]-b[i]-1); 
	sort(q.begin(), q.end()); 
	int ans = n; 
	for (int i = n; i > k; --i) ans += q[n-i]; 
	printf( "%d\n", ans ); 
}