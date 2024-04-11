#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1000000007;

int N;
int D[110][110][110];
vector<int> lis[110];
int vis[110], num[110];
int S[110][110];

bool dfs(int here, int p) {
	vis[here] = 1;
	for (int s=0;s<N;s++) {
		if (D[p][s][here]) {
			if (vis[s]) return false;
			lis[here].push_back(s);
			lis[s].push_back(here);
			if (!dfs(s,here)) return false;
		}
	}
	return true;
}

vector<int> dis[110];
void tdfs(int here, int p, int d) {
	dis[d].push_back(here);
	for (int &there : lis[here]) {
		if (there==p) continue;
		tdfs(there,here,d+1);
	}
}

int par[110], comp;
void init() {
	for (int i=0;i<N;i++) par[i] = i;
	comp = N;
}
int fin(int a) {
	return par[a] = (par[a]==a?a:fin(par[a]));
}
int uni(int a, int b) {
	a = fin(a); b = fin(b);
	if (a==b) return false;
	par[a] = b;
	comp--;
	return true;
}

int main() {
	int T;

	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		for (int i=0;i<N;i++) {
			for (int j=i+1;j<N;j++) {
				for (int k=0;k<N;k++) {
					char c;
					scanf(" %c",&c);
					D[i][j][k] = D[j][i][k] = c-'0';
				}
			}
		}
		int r = -1, maxc = 0;
		bool bad = false;
		for (int k=0;k<N;k++){
			init();
			num[k] = 0;
			for (int i=0;i<N;i++) {
				for (int j=i+1;j<N;j++) {
					if (D[i][j][k]) {
						uni(i,j);
						num[k]++;
					}
				}
			}
			for (int i=0;i<N;i++) {
				for (int j=i+1;j<N;j++) {
					if ((fin(i)==fin(j))!=D[i][j][k]) {
						bad = true;
					}
				}
			}
			if (maxc < comp) {
				maxc = comp;
				r = k;
			}
		}
		if (bad) {
			puts("No");
			continue;
		}
		bool good = false;
		for (int s=0;s<N;s++) {
			if (r==s) continue;
			for (int i=0;i<N;i++) {
				vis[i] = 0;
				lis[i].clear();
			}
			vis[r] = vis[s] = 1;
			lis[r].push_back(s);
			lis[s].push_back(r);
			if (dfs(s,r)) {
				bool mang = false;
				for (int i=0;i<N;i++) {
					if (!vis[i]) mang = true;
				}
				if (!mang) {
					for (int i=0;i<N;i++) {
						for (int j=0;j<N;j++) dis[j].clear();
						tdfs(i,-1, 0);
						int cnum = 0;
						for (int j=0;j<N;j++) {
							cnum += (int)(dis[j].size())*((int)dis[j].size()-1)/2;
							for (int k=0;k+1<dis[j].size();k++) {
								if (!D[dis[j][k]][dis[j][k+1]][i]) mang = true;
							}
						}
						if (cnum!=num[i]) mang = true;
					}
					if (!mang) {
						good = true;
						puts("Yes");
						for (int i=0;i<N;i++) {
							for (int &j : lis[i]) {
								if (i<j) printf("%d %d\n",i+1,j+1);
							}
						}
						break;
					}
				}
			}
		}
//		printf("%d!\n",r);
		if (!good) {
			puts("No");
			continue;
		}
		for (int i=0;i<N;i++) lis[i].clear();
	}

	return 0;
}