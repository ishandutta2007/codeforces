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

int n, q; 
deque<int> a; 
pii ans[200006]; 

int main() {
	scanf( "%d%d", &n, &q ); 
	int maxa = -1;
	for (int i = 1; i <= n; ++i) {
		int x; scanf( "%d", &x ); 
		a.pb(x); 
		maxa = max(maxa, x); 
	}
	int T = 2 * n; 
	for (int i = 1; i <= T; ++i) {
		int A = a.front(); a.pop_front();  
		int B = a.front(); a.pop_front(); 
		ans[i] = {A, B};
		if (A < B) swap(A, B); 
		a.push_front(A); 
		a.pb(B); 
	}
	for (int i = 1; i <= q; ++i) {
		ll x; 
		scanf( "%lld", &x ); 
		if (x <= T) printf( "%d %d\n", ans[x].fir, ans[x].sec ); 
		else {
			int t = (x-T-1) % (n-1) + 1; 
			printf( "%d %d\n", maxa, a[t]); 
		}
	}
}