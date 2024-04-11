#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int BASE = 1e7+19;

int n,k,q;

int on,counter;
int v[15013], w[15013];
int s[15013], e[15013];
vector<int> has[65536];
int ans[30013];

void insert(vector<int>& dp, int ind) {
	vector<int> next = dp;
	for (int i=w[ind];i<=k;i++) next[i] = max(next[i],dp[i-w[ind]]+v[ind]);
	dp = next;
}

void update(int w, int L, int R, int a, int b, int i) {
	if (b<L || R<a) return;
	if (a<=L && R<=b) has[w].push_back(i);
	else update(w*2,L,(L+R)/2,a,b,i), update(w*2+1,(L+R)/2+1,R,a,b,i);
}

void solve(int w, int L, int R, vector<int> dp = vector<int>(k+1)) {
	for (int i: has[w]) insert(dp,i);
	if (L==R) {
		long long cur = 1;
		int d = 0;
		for (int i=1;i<=k;i++) {
			d = max(d,dp[i]);
			ans[L] = (ans[L]+cur*d)%MOD;
			cur = (cur*BASE)%MOD;
		}
	} else solve(w*2,L,(L+R)/2,dp), solve(w*2+1,(L+R)/2+1,R,dp);
}

int main() {
	memset(s,-1,sizeof s); memset(e,-1,sizeof e);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d%d",&v[i],&w[i]);
	on = n+1; counter = 0;
	scanf("%d",&q);
	for (int i=0;i<q;i++) {
		int type;
		scanf("%d",&type);
		if (type==1) {
			scanf("%d%d",&v[on],&w[on]);
			s[on] = counter+1;
			on+=1;
		} else if (type==2) {
			int x;
			scanf("%d",&x);
			e[x] = counter;
		} else counter+=1;
	}
	for (int i=1;i<on;i++) update(1,1,counter,s[i]!=-1 ? s[i] : 1,e[i]!=-1 ? e[i] : counter,i);
	solve(1,1,counter);
	for (int i=1;i<=counter;i++) printf("%d\n",ans[i]);

	return 0;
}