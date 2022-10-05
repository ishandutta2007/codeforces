#include<bits/stdc++.h>

int query(int i, int j){
	printf("? %d %d\n", i, j);
	fflush(stdout);
	int ret;
	scanf("%d", &ret);
	return ret;
}

const int N = 10010;

int qa[N], qb[N], p[N], test[N];
int ans[N], cnt[N], b[N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		qa[i] = query(i, i);
		qb[i] = query(i, (i + 1) % n);
	}
	for (int i = 0; i < n; ++ i){
		test[i] = qa[i] ^ qb[(i - 1 + n) % n];
	}
	int anscnt = 0;
	memset(ans, -1, sizeof(ans));
	for (int i = 0; i < n; ++ i){
		p[n - 1] = i;
		for (int j = n - 2; j >= 0; -- j){
			p[j] = p[j + 1] ^ test[j + 1];
		}
		if ((p[0] ^ p[n - 1]) != test[0]) continue;
		memset(cnt, 0, sizeof(cnt));
		for (int j = 0; j < n; ++ j){
			++ cnt[p[j]];
		}
		bool flag = true;
		for (int j = 0; j < n; ++ j){
			if (cnt[j] != 1){
				flag = false;
				break;
			}
		}
		for (int i = 0; i < n; ++ i){
			b[p[i]] = i;
		}
		for (int i = 0; i < n; ++ i){
			if ((p[i] ^ b[i]) != qa[i]){
				flag = false;
				break;
			}
		}
		for (int i = 0; i < n; ++ i){
			if ((p[i] ^ b[(i + 1) % n]) != qb[i]){
				flag = false;
				break;
			}
		}
		if (!flag) continue;
		++ anscnt;
		if (!~ans[0]){
			for (int j = 0; j < n; ++ j){
				ans[j] = p[j];
			}
		}
	}
	printf("!\n%d\n", anscnt);
	for (int i = 0; i < n; ++ i){
		printf("%d%c", ans[i], " \n"[i == n - 1]);
	}
	return 0;
}