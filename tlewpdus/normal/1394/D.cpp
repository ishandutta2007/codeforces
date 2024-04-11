#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int n;
ll T[200100], H[200100];
ll D[200100][3];
vector<int> lis[200100];

void dfs(int here, int p) {
	ll X = 0, tsum = 0;
	vector<int> cand;
	for (int &there : lis[here]) {
		if (there==p) continue;
		dfs(there,here);
		if (H[there]>H[here]) {
			X--;
			tsum += D[there][0];
		}
		else if (H[there]<H[here]) {
			X++;
			tsum += D[there][1];
		}
		else {
			cand.push_back(there);
		}
	}
	sort(cand.begin(),cand.end(),[](int a, int b){return D[a][1]-D[a][0]<D[b][1]-D[b][0];});
	vector<ll> pre(cand.size()+1,0);
	for (int i=1;i<=cand.size();i++) {
		pre[i] = pre[i-1] + D[cand[i-1]][1];
	}
	ll suf = 0, cur = X+(int)cand.size();
	D[here][0] = D[here][1] = D[here][2] = LINF;
	for (int i=cand.size();i>=0;i--) {
		D[here][0] = min(D[here][0],pre[i]+suf+T[here]*abs(cur+1));
		D[here][1] = min(D[here][1],pre[i]+suf+T[here]*abs(cur-1));
		D[here][2] = min(D[here][2],pre[i]+suf+T[here]*abs(cur));
		if (i) suf += D[cand[i-1]][0];
		cur -=2;
	}
	D[here][0] += tsum;
	D[here][1] += tsum;
	D[here][2] += tsum;
}

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%lld",&T[i]);
	for (int i=0;i<n;i++) scanf("%lld",&H[i]);
	ll sum = 0;
	for (int i=0;i<n-1;i++) {
		int a, b;
		scanf("%d%d",&a,&b); --a; --b;
		lis[a].push_back(b);
		lis[b].push_back(a);
		sum += T[a]+T[b];
	}
	dfs(0,-1);
	printf("%lld\n",(sum+D[0][2])/2);

	return 0;
}