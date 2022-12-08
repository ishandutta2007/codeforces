#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

int n; 

int main() {
	cin>>n; 
	vi ans; 
	for (int x = max(1,n-100000); x <= n; ++x) {
		int t = x; 
		int s = x; 
		while (t > 0) {
			s += t % 10; 
			t /= 10; 
		}
		if (s == n) ans.pb(x); 
	}
	printf( "%d\n", (int)ans.size() ); 
	for (int i : ans) printf( "%d ", i ); 
	puts( "" ); 
	return 0;
}