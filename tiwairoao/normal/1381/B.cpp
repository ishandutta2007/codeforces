#include <bits/stdc++.h>

std::bitset<5000>b; int n;

void solve() {
	scanf("%d", &n), b = 0, b[0] = 1;
	for(int i=1,mx=0,t=0,x;i<=(n<<1);i++) {
		scanf("%d", &x);
		if( x > mx ) {
			if( t ) b |= (b << t);
			t = 1, mx = x;
		} else t++;
	}
	puts(b[n] ? "YES" : "NO");
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}