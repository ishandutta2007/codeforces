#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 

map<ll,int> S;
int t;

int main() {
	scanf( "%d", &t ); 
	while (t--) {
		char st[5]; 
		ll a; 
		scanf( "%s%I64d", st, &a ); 
		ll b = 0, tmp = a, p = 1;  
		while ( tmp > 0 ) {
			if ( (tmp % 10) % 2 == 1 ) b += p; 
			tmp /= 10; 
			p *= 10; 
		}
		if (st[0] == '+') S[b]++; 
		else if ( st[0] == '-' ) S[b]--; 
		else printf( "%d\n", S[a] ); 
	}
}