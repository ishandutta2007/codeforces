#include <bits/stdc++.h>
using namespace std;

bool st;

const int S = 452, H = 2000003;

int n, a[200005], ones, b[200005], son[H], vis[H], cnt, nxt[200005], key[200005], val[200005];
char s[200005];
long long ans;

vector <int> one;

bool en;

int gt(int a, int b) {
	return a / b;
}

void mset(int k, int v, int now) {
	int tmp = (k % H + H) % H;
	if (vis[tmp] != now) {
		vis[tmp] = now;
		son[tmp] = 0;
	}
	for (int j = son[tmp]; j; j = nxt[j])
		if (key[j] == k) {
			val[j] = v;
			return;
		}
	nxt[++ cnt] = son[tmp];
	son[tmp] = cnt;
	key[cnt] = k;
	val[cnt] = v;
}

int mget(int k, int now) {
	int tmp = (k % H + H) % H;
	if (vis[tmp] != now) return 0;
	for (int j = son[tmp]; j; j = nxt[j]) {
		if (key[j] == k) return val[j];
	}
	return 0;
}

int main() {
	
//	printf("%lf\n", (double)(&en - &st) / 1024 / 1024);
	
//	freopen("F.in", "r", stdin);
	
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; ++ i) {
		a[i] = s[i] - '0';
		if (a[i]) {
			one.push_back(i);
			++ ones;
		}
	}
	one.push_back(n + 1);
	for (int i = 1; i <= min(S, ones); ++ i) {
		
//		printf("i = %d\n", i);
		
		int t = i - 1;
		for (int j = 1; j <= n; ++ j) {
			// l = j  r in [a[t], a[t + 1])  >= i * S 
			int L = one[t] - j + 1, R = one[t + 1] - j;
			L = max(L, i * S);
			if (L <= R) {
				
//				printf("%d [%d, %d]\n", j, L, R);
				
				ans += (gt(R, i) - gt(L - 1, i));
			}
			if (a[j] == 1) {
				++ t;
				if (t >= ones) break;
			}
		}
	}
	
//	printf("%lld\n", ans);
	
	for (int j = 1; j < S; ++ j) {
		cnt = 0;
		mset(0, 1, j);
		for (int i = 1; i <= n; ++ i) {
			b[i] = b[i - 1] + a[i];
			
	//		printf("(%d %d)\n", i, b[i]);
			
			int key = i - b[i] * j;
			int tmp = mget(key, j);
			ans += tmp;
//			printf("	j = %d %d %lld\n", j, b[i] - j * i, ans);
			mset(key, tmp + 1, j);
		}
	}
	
	printf("%lld\n", ans);	
	
	return 0;
}