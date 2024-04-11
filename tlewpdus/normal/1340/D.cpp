#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int n, D;
vector<int> lis[100100];
vector<pii> his;

void dfs(int here, int stv, int p) {
	int cur = stv, d = lis[here].size();
	his.push_back({here,cur});
	for (int &there : lis[here]) {
		if (there==p) continue;
		if (cur==D) {
			his.push_back({here,cur-d});
			cur-=d;
		}
		dfs(there,cur+1,here);
		cur++;
		his.push_back({here,cur});
	}
	if (cur!=stv-1&&here) {
		his.push_back({here,stv-1});
	}
}

int main() {
	scanf("%d",&n);
	for (int i=0;i<n-1;i++) {
		int a, b;
		scanf("%d%d",&a,&b); --a; --b;
		lis[a].push_back(b);
		lis[b].push_back(a);
	}
	for (int i=0;i<n;i++) D = max(D,(int)lis[i].size());
	dfs(0,0,-1);
	printf("%d\n",his.size());
	for (pii &v: his) printf("%d %d\n",v.first+1,v.second);

	return 0;
}