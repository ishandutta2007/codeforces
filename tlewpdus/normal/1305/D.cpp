#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int getl(int u, int v) {
	printf("? %d %d\n",u,v);
	fflush(stdout);
	int w;
	scanf("%d",&w);
	return w;
}

int n;
vector<int> lis[1010];
int sps[1010][1010][12], dep[1010][1010];
int dead[1010];

void dfs(int rt, int here, int p) {
	sps[rt][here][0] = p;
	dep[rt][here] = dep[rt][p]+1;
	for (int i=1;i<11;i++) {
		sps[rt][here][i] = sps[rt][sps[rt][here][i-1]][i-1];
	}
	for (int &there : lis[here]) {
		if (there!=p) dfs(rt,there,here);
	}
}

int lca(int rt, int u, int v) {
	if (dep[rt][u]<dep[rt][v]) swap(u,v);
	int td = dep[rt][u]-dep[rt][v];
	for (int i=0;i<11;i++) {
		if (td>>i&1) u = sps[rt][u][i];
	}
	if (u==v) return u;
	for (int i=10;i>=0;i--) {
		if (sps[rt][u][i]!=sps[rt][v][i]) u =sps[rt][u][i],v=sps[rt][v][i];
	}
	return sps[rt][u][0];
}
int iscon[1010][1010];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n-1;i++) {
		int a, b;
		scanf("%d%d",&a,&b);
		iscon[a][b] = iscon[b][a] = 1;
		lis[a].push_back(b);
		lis[b].push_back(a);
	}
	for (int i=1;i<=n;i++) {
		dfs(i,i,0);
	}
	for (int it=0;it<=n/2;it++) {
		int cnt = 0, t = 1;
		vector<int> vec;
		for (int i=1;i<=n;i++) {
			if (!dead[i]) {
				vec.push_back(i);
				cnt++;
				t = i;
			}
		}
		if (cnt==1) {
			printf("! %d\n",t);
			fflush(stdout);
			return 0;
		}
		if (vec.size()==2) {
			int l = getl(vec[0],vec[1]);
			printf("! %d\n",l);
			fflush(stdout);
			return 0;
		}
		int done = 0;
		for (int i=1;i<vec.size();i++) {
			if (!iscon[vec[0]][vec[i]]) {
				int l = getl(vec[0],vec[i]);
				for (int j=1;j<=n;j++) {
					if (!dead[j]&&lca(j,vec[0],vec[i])!=l) {
						dead[j] = 1;
					}
				}
				done = 1;
				break;
			}
		}
		if (!done) {
			int l = getl(vec[1],vec[2]);
			for (int j=1;j<=n;j++) {
				if (!dead[j]&&lca(j,vec[1],vec[2])!=l) {
					dead[j] = 1;
				}
			}
		}
	}

	return 0;
}