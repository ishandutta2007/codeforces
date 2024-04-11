#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int n, m;
int arr[10100];
ll dis[11001000];
int g, r;

void bfs() {
	deque<pii> dq;
	for (int i=0;i<m*(g+1);i++) dis[i] = LINF;
	dis[g] = 0;
	dq.push_back({g,0});
	while(!dq.empty()) {
		pii tmp = dq.front(); dq.pop_front();
		int i = tmp.first/(g+1);
		int t = tmp.first%(g+1);
		int d = tmp.second;
		if (dis[tmp.first]!=d) continue;
		if (i>0&&(arr[i]-arr[i-1])<=t) {
			int ni = i-1;
			int nt = t-(arr[i]-arr[i-1]);
			int nn = ni*(g+1)+nt;
			if (dis[nn]>d) {
				dis[nn]=d;
				dq.emplace_front(nn,d);
			}
		}
		if (i<m-1&&(arr[i+1]-arr[i])<=t) {
			int ni = i+1;
			int nt = t-(arr[i+1]-arr[i]);
			int nn = ni*(g+1)+nt;
			if (dis[nn]>d) {
				dis[nn]=d;
				dq.emplace_front(nn,d);
			}
		}
		if (t==0) {
			int ni = i;
			int nt = g;
			int nn = ni*(g+1)+nt;
			if (dis[nn]>d+1) {
				dis[nn]=d+1;
				dq.emplace_back(nn,d+1);
			}
		}
	}
	ll mini = LINF;
	for (int i=0;i<m;i++) {
		//printf("%d : %lld\n",i,dis[i*(g+1)+g]);
		if (dis[i*(g+1)+g]<LINF/2&&arr[m-1]-arr[i]<=g) {
			mini = min(mini,dis[i*(g+1)+g]*(g+r)+arr[m-1]-arr[i]);
		}
	}
	if (mini>LINF/2) {
		puts("-1");
	}
	else {
		printf("%lld\n",mini);
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) scanf("%d",&arr[i]);
	sort(arr,arr+m);
	scanf("%d%d",&g,&r);
	bfs();

	return 0;
}