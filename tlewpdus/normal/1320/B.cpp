#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int n,m,k;
int route[200100];
vector<int> lis[200100], ris[200100];
int dis[200100];

void bfs(int st) {
	queue<int> q;
	memset(dis,-1,sizeof(dis));
	dis[st] = 0;
	q.push(st);
	while(!q.empty()) {
		int here = q.front(); q.pop();
		for (int &there : ris[here]) {
			if (~dis[there]) continue;
			dis[there] = dis[here]+1;
			q.push(there);
		}
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int a, b;
		scanf("%d%d",&a,&b);
		lis[a].push_back(b);
		ris[b].push_back(a);
	}
	scanf("%d",&k);
	for (int i=0;i<k;i++) scanf("%d",&route[i]);
	bfs(route[k-1]);
	int mini = 0, maxi = 0;
	for (int i=0;i<k-1;i++) {
		if (k-1-i>dis[route[i]]) {
			int cnt = 0;
			for (int &t : lis[route[i]]) {
				if (t!=route[i+1]&&dis[t]+1==dis[route[i]]) cnt++;
			}
			mini++;
			if (cnt) maxi++;
			if (dis[route[i+1]]+1==dis[route[i]]) mini--;
			continue;
		}
		int cnt = 0;
		for (int &t : lis[route[i]]) {
			if (t!=route[i+1]&&dis[t]+1==dis[route[i]]) cnt++;
		}
		if (cnt) maxi++;
	}
	printf("%d %d\n",mini,maxi);

	return 0;
}