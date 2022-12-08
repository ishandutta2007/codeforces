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
	int q; 
	scanf( "%d", &q ); 
	while (q--) {
		int a; 
		scanf( "%d", &a ); 
		int i; 
		for (i = 1; i-1 < a; i*=2); 
		if (i-1 == a) {
			int ans = 1; 
			for (int j = 2; j*j <= a; j++) 
				if (a % j == 0) ans = max(ans, a/j); 
			printf( "%d\n", ans ); 
		}
		else printf( "%d\n", i-1 ); 
	}
}