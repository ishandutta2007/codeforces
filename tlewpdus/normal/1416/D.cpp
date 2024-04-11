#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353; // 1000000007

int n, m, q;
int P[200100];
int par[200100];
vector<int> elem[200100];
int deadv[200100];
vector<pii> his;
pii que[500100];
pii edg[300100];
int deade[300100];
int rev[500100];

void init(int n) {
	iota(par,par+n,0);
	for (int i=0;i<n;i++) elem[i].push_back(i);
}
int fin(int a) {
	while(par[a]!=a) a = par[a];
	return a;
}
void uni(int a, int b) {
	a = fin(a), b = fin(b);
	if (a==b) return;
	if (elem[a].size()>elem[b].size()) {
		his.push_back({b,a});
		swap(a,b);
	}
	else {
		his.push_back({a,b});
	}
	for (int &v : elem[a]) elem[b].push_back(v);
	par[a] = b;
}

int main() {
	scanf("%d%d%d",&n,&m,&q);
	for (int i=0;i<n;i++) scanf("%d",&P[i]);
	for (int i=0;i<m;i++) {
		int a, b;
		scanf("%d%d",&a,&b); --a; --b;
		edg[i] = {a,b};
	}
	for (int i=0;i<q;i++) {
		int a, b;
		scanf("%d%d",&a,&b); --b;
		que[i] = {a,b};
		if (a==2) {
			deade[b] = 1;
		}
	}
	init(n);
	for (int i=0;i<m;i++) {
		if (!deade[i]) {
			uni(edg[i].first,edg[i].second);
		}
	}
	his.clear();
	for (int i=q-1;i>=0;i--) {
		int a = que[i].first, b = que[i].second;
		if (a==2) {
			rev[i] = his.size();
			uni(edg[b].first,edg[b].second);
		}
	}
	for (int i=0;i<n;i++) {
		sort(elem[i].begin(),elem[i].end(),[](int a, int b){
			return P[a]<P[b];
		});
	}
	for (int i=0;i<q;i++) {
		int a = que[i].first, b = que[i].second;
		if (a==1) {
			int c = fin(b);
			while(!elem[c].empty() && (deadv[elem[c].back()] || fin(elem[c].back()) != c)) {
				elem[c].pop_back();
			}
			if (elem[c].empty()) {
				puts("0");
			}
			else {
				printf("%d\n",P[elem[c].back()]);
				deadv[elem[c].back()] = 1;
				elem[c].pop_back();
			}
		}
		else  {
			while(rev[i]<his.size()) {
				pii tmp = his.back(); his.pop_back();
				par[tmp.first] = tmp.first;
			}
		}
	}

	return 0;
}