#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
const ll oo = 0x3f3f3f3f3f3f3f3fll; 
const int maxn = 200006; 

int a[maxn]; 
int n; 
ll b[maxn]; 

ll Abs(ll x) { 
	return x>0?x:-x; 
}

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) {
		scanf( "%d", &a[i] ); 
		if (i != 1) b[i-1] = Abs(a[i]-a[i-1]); 
	}
	ll s1 = -oo, s2 = -oo, ans = -oo; 
	for (int i = 1; i <= n; ++i) {
		s1 += b[i]; 
		s2 -= b[i]; 
		swap(s1, s2); 
		s2 = max(s2, b[i]); 
		ans = max(ans, max(s1,s2) ); 
	}
	cout<<ans<<endl; 
	return 0;
}