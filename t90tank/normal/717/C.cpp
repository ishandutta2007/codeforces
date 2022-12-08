#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back

int n; 
int a[2000000]; 

int main() {
	scanf( "%d", &n ); 
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]); 
	sort(a, a+n); 
	ll ans = 0; 
	for (int i = 0; i < n; ++i) 
		ans = (ans + ll(a[i]) * a[n-1-i]) % 10007; 
	cout<<ans<<endl; 
}