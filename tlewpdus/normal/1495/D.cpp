#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, M;
vector<int> lis[410];
int mat[410][410];
ll ans[410][410];

int main() {
	scanf("%d%d",&N,&M);
	memset(mat,0x3f,sizeof(mat));
	for (int i=0;i<M;i++) {
		int a, b;
		scanf("%d%d",&a,&b); --a; --b;
		lis[a].push_back(b);
		lis[b].push_back(a);
		mat[a][b] = mat[b][a] = 1;
	}
	for (int i=0;i<N;i++) mat[i][i] = 0;
	for (int k=0;k<N;k++) {
		for (int i=0;i<N;i++) {
			for (int j=0;j<N;j++) {
				if (mat[i][j] > mat[i][k]+mat[k][j]) {
					mat[i][j] = mat[i][k]+mat[k][j];
				}
			}
		}
	}
	for (int i=0;i<N;i++) {
		ll res = 1;
		for (int j=0;j<N;j++) {
			if (j==i) continue;
			int c = 0;
			for (int &k : lis[j]) {
				if (mat[i][k]+1==mat[i][j]) c++;
			}
			res = res*c%MOD;
		}
		ans[i][i] = res;
	}
	for (int i=0;i<N;i++) {
		for (int j=i+1;j<N;j++) {
			int c = 0;
			for (int k=0;k<N;k++) {
				if (mat[i][k]+mat[k][j]==mat[i][j]) c++;
			}
			if (c!=mat[i][j]+1) continue;
			ll res = 1;
			for (int k=0;k<N;k++) {
				int d = 0;
				if (mat[i][k]+mat[k][j]==mat[i][j]) continue;
				int dd = mat[i][k]-mat[j][k];
				int ds = mat[i][k]+mat[j][k];
				for (int &l : lis[k]) {
					if (mat[i][l]-mat[j][l]==dd && mat[i][l]+mat[j][l]+2==ds) d++;
				}
				res = res*d%MOD;
			}
			ans[i][j] = ans[j][i] = res;
		}
	}
	for (int i=0;i<N;i++) {
		for (int j=0;j<N;j++) printf("%lld ",ans[i][j]);
		puts("");
	}

	return 0;
}