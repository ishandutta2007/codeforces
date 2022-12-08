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

int main() {
	int b, k; 
	scanf( "%d%d", &b, &k ); 
	int ans = 0; 
	for (int i = 1; i <= k; ++i) {
		int a; 
		scanf( "%d", &a ); 
		if (i==k) ans ^= (a&1); 
		else if (b % 2 == 1) ans ^= (a&1);
	}
	if (ans % 2 == 0) puts( "even" ); 
	else puts( "odd" ); 
}