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

int n, h; 
int a[2000]; 

int main() {
	scanf( "%d%d", &n, &h ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &a[i] ); 
	int ans = 0; 
	for (int k = 1; k <= n; ++k) {
		sort(a+1,a+k+1);
		bool flag = true; 
		ll s = 0; 
		for (int i = k; i >= 1; i -= 2) 
			s += a[i]; 
		//cout<<k<<' '<<s<<endl; 
		if (s <= (ll)h) 
			ans = k; 
	}
	cout<<ans<<endl; 
}