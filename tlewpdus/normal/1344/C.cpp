#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int n, m;
vector<int> lis[200100];
vector<int> ris[200100];
int deg[200100];
int D[200100], E[200100];

void pung() {
	puts("-1");
	exit(0);
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int a, b;
		scanf("%d%d",&a,&b);
		a--; b--;
		lis[a].push_back(b);
		ris[b].push_back(a);
		deg[b]++;
	}
	queue<int> q;
	for (int i=0;i<n;i++) {
		if (!deg[i]) q.push(i);
	}
	vector<int> wi;
	while(!q.empty()) {
		int here = q.front(); q.pop();
		wi.push_back(here);
		for (int &there : lis[here]) {
			deg[there]--;
			if (deg[there]==0) {
				q.push(there);
			}
		}
	}
	for (int i=0;i<n;i++) {
		if (deg[i]) {
			pung();
		}
	}
	for (int i=0;i<n;i++) D[i] = E[i] = i;
	for (int &v : wi) {
		for (int &w : ris[v]) D[v] = min(D[v],D[w]);
	}
	reverse(wi.begin(),wi.end());
	for (int &v : wi) {
		for (int &w : lis[v]) E[v] = min(E[v],E[w]);
	}
	int cnt = 0;
	for (int i=0;i<n;i++) {
		if (D[i]==i&&E[i]==i) {
			cnt++;
		}
	}
	printf("%d\n",cnt);
	for (int i=0;i<n;i++) {
		if (D[i]==i&&E[i]==i) {
			printf("A");
		}
		else printf("E");
	}puts("");

	return 0;
}