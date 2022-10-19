#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, col[N], who[N];
bool vis[N];

// 0 more impos

int Q(int a, int b, int c) {
	printf("? %d %d %d\n", a, b, c);
	fflush(stdout);
	scanf("%d", &a);
	return a;
}

void rmain() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i += 3) {
		who[i / 3 + 1] = Q(i, i + 1, i + 2);
	}
	
	for(int i = 1; i <= n; ++ i) col[i] = -1;
	
	int now = -1;
	
	for(int i = 1; i < n / 3; ++ i) {
		if(who[i] != who[i + 1]) {
			now = i; break;
		}
	}
	
	// (now - 1) * 3 + 1, now * 3
	
	int a = Q(now * 3 - 1, now * 3, now * 3 + 1), b = Q(now * 3, now * 3 + 1, now * 3 + 2);
	
	int tmp[2] = {0, 0};
	
	if(a != who[now]) {
		col[now * 3 - 2] = who[now];
		col[now * 3 + 1] = 1 - who[now];
		tmp[who[now]] = now * 3 - 2;
		tmp[who[now] ^ 1] = now * 3 + 1;
	} else if(b != who[now]) {
		col[now * 3 - 1] = who[now];
		col[now * 3 + 2] = 1 - who[now];
		tmp[who[now]] = now * 3 - 1;
		tmp[who[now] ^ 1] = now * 3 + 2;		
	} else {
		col[now * 3] = who[now];
		col[now * 3 + 3] = 1 - who[now];
		tmp[who[now]] = now * 3;
		tmp[who[now] ^ 1] = now * 3 + 3;
	}
	
	for(int i = now * 3 - 2; i <= (now + 1) * 3; ++ i) {
		if(col[i] == -1) {
			col[i] = Q(tmp[0], tmp[1], i);
		}
	}
	
	for(int i = 1; i <= n / 3; ++ i) {
		if(i == now || i == now + 1) continue;
		int l = Q(tmp[who[i] ^ 1], i * 3 - 2, i * 3 - 1), r = Q(tmp[who[i] ^ 1], i * 3 - 1, i * 3);
		col[i * 3 - 2] = col[i * 3 - 1] = col[i * 3] = who[i];
		if(l == who[i] && r == who[i]) {
		} else {
			if(l != who[i] && r != who[i]) col[i * 3 - 1] = 1 - who[i];
			else if(l == who[i] && r != who[i]) col[i * 3] = 1 - who[i];
			else col[i * 3 - 2] = 1 - who[i];
		}
	}
	printf("! ");
	int k = 0;
	for(int i = 1; i <= n; ++ i) if(!col[i]) ++ k;
	printf("%d ", k);
	for(int i = 1; i <= n; ++ i) if(!col[i]) printf("%d ", i);
	puts("");
	fflush(stdout);
}

int main() {
	int t; for(cin >> t; t --;) rmain();
}