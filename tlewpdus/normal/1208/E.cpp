#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 0x3f3f3f3f;

int n, w;

struct idxtree {
	int tree[2100000];
	const int key = 1048576;
	void init() {
		for (int i=0;i<key*2;i++) tree[i] = -INF;
	}
	void upd(int idx, int val) {
		idx += key;
		tree[idx] = val;
		idx/=2;
		while(idx) {
			tree[idx] = max(tree[idx*2],tree[idx*2+1]);
			idx/=2;
		}
	}
	int getv(int s, int e) {
		s += key; e+=key;
		int res= -INF;
		while(s<=e) {
			if (s&1) res = max(res,tree[s++]);
			if (~e&1) res = max(res,tree[e--]);
			s/=2; e/=2;
		}
		return res;
	}
} it;

ll ans[1000100];

int main() {
	scanf("%d%d",&n,&w);
	for (int i=0;i<n;i++) {
		int a;
		scanf("%d",&a);
		vector<int> lis;
		for (int j=0;j<a;j++) {
			int b;
			scanf("%d",&b);
			lis.push_back(b);
			it.upd(j,b);
		}
		if (a*2<=w) {
			for (int j=0;j<a-1;j++) {
				int v = max(it.getv(0,j),0);
				ans[j] += v;
				ans[j+1]-=v;
			}
			int v = max(it.getv(0,a-1),0);
			ans[a-1]+=v;
			ans[w-a+1]-=v;
			for (int j=1;j<a;j++) {
				int v = max(it.getv(j,a-1),0);
				ans[w-a+j]+=v;
				ans[w-a+j+1]-=v;
			}
		}
		else {
			for (int j=0;j<w;j++) {
				int v = it.getv(max(j-w+a,0),min(j,a-1));
				if (j<w-a||j>=a) v = max(v,0);
				ans[j]+=v;
				ans[j+1]-=v;
			}
		}
	}
	ll c = 0;
	for (int i=0;i<w;i++) {
		c += ans[i];
		printf("%lld ",c);
	}
	printf("\n");

	return 0;
}