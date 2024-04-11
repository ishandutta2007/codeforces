#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second
const ll oo = 0x3f3f3f3f3f3f3f3f; 

int n, k, p; 
set<int> S; 
int a[3000], b[3000]; 
ll f[3000][3000]; 

ll Abs(ll x) {
	return max(x,-x); 
}

int main() {
	cin>>n>>k>>p; 
	for (int i = 1; i <= n; ++i) scanf( "%d", &a[i] ); 
	for (int i = 1; i <= k; ++i) scanf( "%d", &b[i] ); 
	sort(a+1, a+n+1);
	sort(b+1, b+k+1);
	for (int i = 0; i <= n; ++i) 
		for (int j = 0; j <= k; ++j) 
			f[i][j] = oo; 
	for (int i = 0; i <= k; ++i) f[0][i] = 0;
	
	for (int i = 1; i <= n; ++i) 
		for (int j = i; j <= k; ++j) 
			f[i][j] = min(f[i][j-1], max(f[i-1][j-1],Abs(a[i]-b[j])+Abs(b[j]-p))); 
	cout<<f[n][k]<<endl; 
	return 0;
}