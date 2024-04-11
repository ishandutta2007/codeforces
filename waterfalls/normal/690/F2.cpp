#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+123;
const int BASE = 1e9+9;

int add(int a, int b) { return a+b-(a+b>=MOD)*MOD; }
int sub(int a, int b) { return a-b+(a-b<0)*MOD; }
int mult(int a, int b) { return (1LL*a*b)%MOD; }

int collapse(vector<int> has) {
	sort(has.begin(),has.end());
	int res = 0;
	for (int i: has) res = add(mult(res,BASE),i);
	return res;
}

int n;
vector<vector<int> > adj;
int s[113];
bool vis[113];

void setup(int x, int p=0) {
	vis[x] = 1;
	s[x] = 1;
	for (int i: adj[x]) if (i!=p) {
		setup(i,x);
		s[x]+=s[i];
	}
}

void look(int x, int p, int tot, vector<int>& centroids) {
	bool ok = 1;
	for (int i: adj[x]) if (i!=p) {
		if (s[i]>tot/2) ok = 0;
		look(i,x,tot,centroids);
	}
	if (tot-s[x]>tot/2) ok = 0;
	if (ok) centroids.push_back(x);
}

int process(int x, int p=0) {
	vector<int> res;
	res.push_back(1);
	for (int i: adj[x]) if (i!=p) {
		res.push_back(mult(2,process(i,x)));
	}
	return collapse(res);
}

int idTree(int x) {
	setup(x);
	vector<int> centroids;
	look(x,0,s[x],centroids);
	int res = 0;
	for (int c: centroids) {
		res = max(res,process(c));
	}
	return res;
}

int idForest() {
	memset(vis,0,sizeof vis);
	vector<int> res;
	for (int i=1;i<=n;i++) if (!vis[i]) {
		res.push_back(idTree(i));
	}
	return collapse(res);
}

vector<vector<int> > drawing[113];

bool test(int i, int a, int b, int id) {
	vector<int> res;
	for (int r=1;r<=n;r++) {
		adj.clear();
		adj.resize(n+1);
		for (int j=1;j<=n;j++) {
			for (int k: drawing[i][j]) {
				if (j!=r && k!=r) {
					adj[j].push_back(k);
				}
			}
		}
		if (a!=r && b!=r) {
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		res.push_back(idForest());
	}
	return collapse(res)==id;
}

void solve() {
	scanf("%d%*d",&n);
	for (int i=0;i<n;i++) {
		drawing[i].clear();
		drawing[i].resize(n+1);
	}
	for (int i=0;i<n;i++) {
		int m;
		scanf("%d",&m);
		for (int j=0;j<m;j++) {
			int a,b;
			scanf("%d%d",&a,&b);
			drawing[i][a].push_back(b);
			drawing[i][b].push_back(a);
		}
	}
	vector<int> res;
	for (int i=0;i<n;i++) {
		adj = drawing[i];
		res.push_back(idForest());
	}
	int id = collapse(res);
	for (int i=0;i<n;i++) {
		adj = drawing[i];
		int on = 1;
		while (on<n && !adj[on].size()) on+=1;
		memset(vis,0,sizeof vis);
		setup(on);
		int num = accumulate(vis,vis+n+1,0);
		if (num==n-1) {
			num = 1;
			while (vis[num]) num+=1;
			for (int j=1;j<=n;j++) {
                if (j!=num && test(i,num,j,id)) {
					printf("YES\n");
					for (int a=1;a<=n;a++) {
						for (int b: drawing[i][a]) {
							if (b>a) printf("%d %d\n",a,b);
						}
					}
					printf("%d %d\n",num,j);
					return;
                }
			}
			printf("NO\n");
			return;
		}
	}
	printf("NO\n");
}

int main() {
	int T;
	scanf("%d",&T);
	while (T--) solve();

	return 0;
}