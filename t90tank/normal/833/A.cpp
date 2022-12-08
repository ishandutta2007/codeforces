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

int n, a, b; 

bool check(ll x) {
	ll d = exp(log(x)/3); 
	for (ll i = d-20; i <= d+20; ++i)
		if (i > 0 && i*i*i == x) return true;
	return false; 
}

int main() {
	scanf( "%d", &n ); 
	while (n--) {
		scanf( "%d%d", &a, &b ); 
		int r = __gcd(a, b);
		int p = a/r, q = b/r; 
		if (r % (p*q) == 0 && check(r/(p*q))) puts( "Yes" ); 
		else puts( "No" ); 
	}
}