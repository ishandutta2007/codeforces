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

const int maxn = 400006; 

int n, I; 
map<int,int> S; 
int sum[maxn], val[maxn]; 

int main() {
	scanf( "%d%d", &n, &I ); 
	int h = I * 8 / n; 
	int x; 
	if (h >= 20) x = n; 
	else x = (1<<h); 
	for (int i = 1; i <= n; ++i) {
		int a; 
		scanf( "%d", &a ); 
		S[a] += 1; 
	}
	sum[0] = 0; 
	int tot = 0; 
	for (auto p : S) {
		val[++tot] = p.fir; 
		sum[tot] = sum[tot-1] + p.sec; 
	}
	int ans = 0;
	for (int i = 1; i+x-1 <= tot; ++i) 
		ans = max(ans, sum[i+x-1] - sum[i-1]); 
	if (tot <= x) ans = max(ans, n); 
	printf( "%d\n", n-ans ); 
}