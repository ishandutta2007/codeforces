#include <bits/stdc++.h>

const int N = 100000;

std::vector<int>v;

void print() {
	printf("%d ", (int)v.size());
	for(auto x : v) printf("%d ", x);
	puts("");
}
void add(int x) {v.push_back(x);}

char a[N + 5], b[N + 5]; int n;

void solve() {
	scanf("%d%s%s", &n, a + 1, b + 1), v.clear();
	
	int l = 2, r = n, p = n, x = a[1]; bool tag = false;
	while( l <= r ) {
		if( tag ) {
			if( a[l] == b[p] ) {
				if( x != b[p] ) add(1);
				add(p), x = a[l], tag ^= 1;
			}
			l++;
		} else {
			if( a[r] != b[p] ) {
				if( x == b[p] ) add(1);
				add(p), x = a[r], tag ^= 1;
			}
			r--;
		}
		p--;
	}
	if( !tag && x != b[1] ) add(1);
	else if( tag && x == b[1] ) add(1);
	
	print();
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}