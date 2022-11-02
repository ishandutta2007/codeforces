#include <bits/stdc++.h>

const int N = 100000;

std::vector<int>ans;
void print() {
	printf("%d", (int)ans.size());
	for(auto x : ans) printf(" %d", x);
	puts("");
}

bool tag[N + 5]; int nxt[N + 5], lst[N + 5], a[N + 5], n;
void erase(int x) {tag[x] = true, nxt[lst[x]] = nxt[x], lst[nxt[x]] = lst[x];}

int gcd(int x, int y) {return y == 0 ? x : gcd(y, x % y);}
void solve() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	for(int i=1;i<=n;i++) tag[i] = false, lst[i] = i - 1, nxt[i] = i + 1;
	lst[1] = n, nxt[n] = 1;
	
	std::queue<int>que; ans.clear();
	for(int i=1;i<=n;i++) if( gcd(a[i], a[nxt[i]]) == 1 ) que.push(i);
	while( !que.empty() ) {
		int x = que.front(); que.pop();
		if( tag[x] ) continue;
		
		ans.push_back(nxt[x]);
		if( nxt[x] == x ) {
			break;
		} else {
			erase(nxt[x]);
			if( gcd(a[x], a[nxt[x]]) == 1 ) que.push(x);
		}
	}
	print();
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}