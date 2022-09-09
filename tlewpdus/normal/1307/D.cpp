#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;

int n, m, k;
int arr[200100];
vector<int> lis[200100];
int dis[2][200100];
int pre[200100], suf[200100];

void bfs(int st, int dis[]) {
	queue<int> q;
	q.push(st);
	for (int i=0;i<n;i++) dis[i] = -1;
	dis[st] = 0;
	while(!q.empty()) {
		int here = q.front(); q.pop();
		for (int &there : lis[here]) {
			if (~dis[there]) continue;
			dis[there]=dis[here]+1;
			q.push(there);
		}
	}
}

int main() {
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<k;i++) scanf("%d",&arr[i]), --arr[i];
	for (int i=0;i<m;i++) {
		int a, b;
		scanf("%d%d",&a,&b); --a; --b;
		lis[a].push_back(b);
		lis[b].push_back(a);
	}
	bfs(0,dis[0]);
	bfs(n-1,dis[1]);
	int td = dis[0][n-1];
	sort(arr,arr+k,[](int a, int b){
		return dis[0][a]<dis[0][b]||(dis[0][a]==dis[0][b]&&dis[1][a]<dis[1][b]);
	});
	int ans = 0;
	vector<int> st;
	for (int i=0;i<k;i++) {
		int A = dis[1][arr[i]], B = dis[0][arr[i]];
		int s = 0, e = (int)st.size()-1;
		while(s<=e) {
			int m = (s+e)/2;
			if (dis[0][st[m]]-dis[1][st[m]]<=B-A) s = m+1;
			else e = m-1;
		}
		int val = 0;
		if (e>=0&&e<st.size()) val = max(val,min(A+dis[0][st[e]],B+dis[1][st[e]])+1);
		if (s>=0&&s<st.size()) val = max(val,min(A+dis[0][st[s]],B+dis[1][st[s]])+1);
		ans = max(ans,min(val,td));
		while(!st.empty()&&dis[1][st.back()]<dis[1][arr[i]]) st.pop_back();
		st.push_back(arr[i]);
	}
	printf("%d\n",ans);

	return 0;
}