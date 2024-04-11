#include<bits/stdc++.h>

typedef std::pair <int, int> pii;
typedef long long ll;
const int N = 110;

pii p[N];
int a[N][N], b[N][N];
ll awin = 0, bwin = 0;

void solve(int a, int b, ll value){
	if (a == b) return;
	if (b % 3 + 1 == a){
		awin += value;
	}
	else{
		bwin += value;
	}
}

int main(){
	int aa, bb;
	ll k;
	scanf("%I64d%d%d", &k, &aa, &bb);
	for (int i = 1; i <= 3; ++ i){
		for (int j = 1; j <= 3; ++ j){
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= 3; ++ i){
		for (int j = 1; j <= 3; ++ j){
			scanf("%d", &b[i][j]);
		}
	}
	p[0] = {aa, bb};
	int i, j;
	for (i = 1; ; ++ i){
		p[i] = {a[p[i - 1].first][p[i - 1].second], b[p[i - 1].first][p[i - 1].second]};
		bool flag = false;
		for (j = 0; j < i; ++ j){
			if (p[i] == p[j]){
				flag = true;
				break;
			}
		}
		if (flag){
			break;
		}
	}
	int period = i - j;
	for (int u = 0; u < j; ++ u){
		if (u < k){
			solve(p[u].first, p[u].second, 1);
		}
	}
	for (int u = j; u < i; ++ u){
		if (u < k){
			solve(p[u].first, p[u].second, (k - u - 1) / period + 1);
		}
	}
	return printf("%I64d %I64d\n", awin, bwin), 0;
}