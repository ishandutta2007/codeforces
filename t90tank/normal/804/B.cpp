#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using db = double;
#define pb push_back
int len; 
char a[2000000]; 
const ll mod = (ll)1e9+7; 

int main() {
	ll ans = 0; 
	ll sum = 0; 
	scanf( "%s", a ); 
	len = strlen(a); 
	for (int i = len-1; i >= 0; --i) 
		if (a[i] == 'a') {
			ans = (ans + sum) % mod; 
			sum = sum * 2 % mod; 
		}
		else sum = (sum + 1) % mod; 
	cout<<ans<<endl; 
}