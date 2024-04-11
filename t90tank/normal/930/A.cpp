#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
using pii = pair<int,int>;
#define pb push_back
#define fir first
#define sec second

const int maxn = 100006; 

int d[maxn]; 
int n; 
int a[maxn]; 

int main() {
	scanf( "%d", &n ); 
	a[d[0]]++; 
	for (int i = 2; i <= n; ++i) {
		int x; 
		scanf( "%d", &x ); 
		d[i] = d[x] + 1; 
		a[d[i]]++; 
	}
	int ans = 0; 
	for (int i = 0; i <= n; ++i) 
		if (a[i] % 2 == 1) ans++; 
	cout<<ans<<endl; 
	return 0;
}