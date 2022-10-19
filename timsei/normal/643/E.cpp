
 #include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int n, m, x, y, fa[N], S[N][41], ty, sz, All[N][41];

double dp[N][45];

double get(int x, int y) {
	if(y >= 0) return dp[x][y];
	return 0;
}

double query(int x) {
	double ans = 0;
	for(int i = 0; i <= 40; ++ i)
	ans += 1 - dp[x][i];
	return ans;
}

int who[N];

void add(int x) {
	++ sz;
	fa[sz] = x;
	for(int i = 0; i <= 40; ++ i) dp[sz][i] = 1;
	vector <int> F;
	F.clear();
	int now = sz;
	F.push_back(sz);
	who[sz] = -1;
	for(int i = 0; i <= 40; ++ i) {
		F.push_back(fa[now]);
		who[fa[now]] = i;
		now = fa[now];
		if(!fa[now]) break;
	}
	for(int i = F.size() - 1; i > 1; -- i) {
		dp[F[i]][who[F[i]]] = dp[F[i]][who[F[i]]] / ((1 + get(F[i - 1],who[F[i - 1]])) / 2);
		//cerr << dp[F[i]][who[F[i]]] << endl;
	}
	
	
	for(int i = 1; i < (int) F.size(); ++ i) {
		dp[F[i]][who[F[i]]] = dp[F[i]][who[F[i]]] * ((1 + get(F[i - 1],who[F[i - 1]])) / 2);
	}
	
}

main() {
	add(0);
	int TTT;
	for(scanf("%d", &TTT); TTT --;) {
		scanf("%d%d", &ty, &x);
		if(ty == 1) {
			add(x);
		}
		else printf("%.12lf\n", query(x));
	}
}