#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n, k, ans;
char str[300100];
vector<int> sub[300100];

int NOT(int idx) {
	if (idx<k) return idx+k;
	return idx-k;
}

int par[600100];
int sz[600100];
int sel[600100];

int fin(int a) {
	return par[a] = (par[a]==a?a:fin(par[a]));
}
void uni(int a, int b) {
	a = fin(a), b = fin(b);
	if (a==b) return;
	int na = fin(NOT(a)), nb = fin(NOT(b));
	if (sel[a]&&sel[b]);
	else if (!sel[a]&&!sel[b]) {
		ans -= min(sz[a],sz[na])+min(sz[b],sz[nb]);
		ans += min(sz[a]+sz[b],sz[na]+sz[nb]);
	}
	else {
		if (sel[a]) swap(a,b), swap(na,nb);
		ans -= min(sz[a],sz[na]);
		if (sel[b]==1) ans += sz[a];
		else ans+=sz[na];
	}
	par[a] = b;
	sz[b] += sz[a];
	par[na] = nb;
	sz[nb] += sz[na];
}

int main() {
	scanf("%d%d",&n,&k);
	scanf("%s",str);
	for (int i=0;i<n;i++) str[i]-='0';
	for (int i=0;i<k;i++) {
		int c;
		scanf("%d",&c);
		for (int j=0;j<c;j++) {
			int a;
			scanf("%d",&a); a--;
			sub[a].push_back(i);
		}
	}
	iota(par,par+2*k,0);
	for (int i=0;i<k;i++) sz[i] = 1;
	for (int i=0;i<n;i++) {
		if (sub[i].size()==0) {
			printf("%d\n", ans);
		}
		else if (sub[i].size()==1) {
			int a = fin(sub[i][0]), b = fin(NOT(sub[i][0]));
			if (sel[a]||sel[b]) {
				printf("%d\n",ans);
			}
			else {
				ans -= min(sz[a], sz[b]);
				if (str[i]) {
					sel[b] = 1; sel[a] = -1;
					ans += sz[b];
				}
				else {
					sel[a] = 1; sel[b] = -1;
					ans += sz[a];
				}
				printf("%d\n",ans);
			}
		}
		else {
			if (str[i]) uni(sub[i][0],sub[i][1]);
			else uni(sub[i][0],NOT(sub[i][1]));
			printf("%d\n",ans);
		}
	}

	return 0;
}