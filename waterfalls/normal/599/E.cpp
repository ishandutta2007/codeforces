#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Restrict {
	int type;
	int a,b,c;
};

int n,m,q;
vector<Restrict> bad;

bool ok(int root, int mask1, int child, int mask2) {
	for (auto r: bad) {
		if (!(mask1&(1<<r.a)) || !(mask1&(1<<r.b))) continue;
		if (((mask2&(1<<r.a))>0)==((mask2&(1<<r.b))>0)) continue;
		if (r.type==0) {
			if (r.b==root) swap(r.a,r.b);
			if (r.a!=root || r.b!=child) return false;
		} else if (r.c!=root) return false;
	}
	return true;
}

ll dp[1<<13][13];
ll go(int cur, int on, vector<int>& has, int root, int mask) {
	ll res = 0;
	if (on==has.size()) {
		for (int i=0;i<n;i++) if (cur&(1<<i) && ok(root,mask,i,cur)) {
			res+=dp[mask^cur][root]*dp[cur][i];
		}
	} else {
		res+=go(cur,on+1,has,root,mask);
		res+=go(cur^has[on],on+1,has,root,mask);
	}
	return res;
}

int main() {
	scanf("%d%d%d",&n,&m,&q);
	for (int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		bad.push_back({0,a-1,b-1,0});
	}
	for (int i=0;i<q;i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if (a==b && a!=c) return printf("0\n"), 0;
		bad.push_back({1,a-1,b-1,c-1});
	}
	for (int i=0;i<n;i++) dp[1<<i][i] = 1;
	for (int mask=1;mask<(1<<n);mask++) for (int root=0;root<n;root++) if (mask&(1<<root)) {
		int high = -1;
		for (int i=0;i<n;i++) if ((mask&(1<<i)) && i!=root) high = i;
		if (high==-1) continue;
		vector<int> has;
		for (int i=0;i<n;i++) if ((mask&(1<<i)) && i!=root && i!=high) has.push_back(1<<i);
		dp[mask][root] = go(1<<high,0,has,root,mask);
	}
	printf("%lld\n",dp[(1<<n)-1][0]);

	return 0;
}