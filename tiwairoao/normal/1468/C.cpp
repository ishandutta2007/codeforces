#include <bits/stdc++.h>

const int N = int(5E5);

int read() {
	int x = 0, ch = getchar();
	while( ch > '9' || ch < '0' ) ch = getchar();
	while( '0' <= ch && ch <= '9' ) x = 10 * x + ch - '0', ch = getchar();
	return x;
}

struct node{
	int k, p;
	friend bool operator < (const node &a, const node &b) {
		return (a.k == b.k) ? (a.p > b.p) : (a.k < b.k);
	}
};
std::priority_queue<node>que;

bool vis[N + 5]; int cnt;

int main() {
	int q = read(), tim = 0; vis[0] = true;
	for(int i=1;i<=q;i++) {
		int op = read();
		if( op == 1 ) {
			que.push((node){read(), ++cnt});
		} else if( op == 2 ) {
			while( vis[tim] ) tim++;
			vis[tim] = true, printf("%d ", tim);
		} else {
			while( vis[que.top().p] ) que.pop();
			int ans = que.top().p; que.pop();
			vis[ans] = true, printf("%d ", ans);
		}
	}
}