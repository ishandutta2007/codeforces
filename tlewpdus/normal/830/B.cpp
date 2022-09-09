#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;

struct idxtree{
	ll tree[270000];
	int key = 131072;
	idxtree() {
		int i;
		for (i=0;i<key*2;i++) tree[i] = 1234567;
	}
	void upd(int idx, ll val) {
		idx += key;
		tree[idx] = val; idx>>=1;
		while(idx>0) {
			tree[idx] = min(tree[idx*2],tree[idx*2+1]);
			idx>>=1;
		}
	}
	ll getv(int s, int e) {
		s+=key;
		e+=key;
		ll res = 1234567;
		while(s<=e) {
			if (s&1) res = min(res,tree[s++]);
			if (~e&1) res = min(res,tree[e--]);
			s>>=1;e>>=1;
		}
		return res;
	}
	ll que(int s, int e) {
		if (e>=n) return min(getv(s,n-1),getv(0,e-n));
		return getv(s,e);
	}
} it;

struct idxtree2{
	ll tree[270000];
	int key = 131072;
	idxtree2() {
		int i;
		for (i=0;i<key*2;i++) tree[i] = 0;
	}
	void upd(int idx, ll val) {
		idx += key;
		while(idx>0) {
			tree[idx] += val;
			idx>>=1;
		}
	}
	ll getv(int s, int e) {
		s+=key;
		e+=key;
		int res = 0;
		while(s<=e) {
			if (s&1) res += tree[s++];
			if (~e&1) res += tree[e--];
			s>>=1;e>>=1;
		}
		return res;
	}
	ll que(int s, int e) {
		if (e>=n) return getv(s,n-1)+getv(0,e-n);
		return getv(s,e);
	}
} it2;

ll arr[100100], brr[100100];
ll res;

int main() {
    int i;

	scanf("%d",&n);
	for (i=0;i<n;i++) {
		scanf("%lld",&arr[i]);
		brr[i] = arr[i];
	}
	for (i=0;i<n;i++) it.upd(i,arr[i]);
	sort(brr,brr+n);
	int cur = 0;
	for (i=0;i<n;i++) {
		ll s = cur, e = cur+n-1;
		while(s<=e) {
			int m = (s+e)>>1;
			if (it.que(s,m)==brr[i]) e = m-1;
			else s = m+1;
		}
		res = res+s-cur+1-it2.que(cur,s);
		cur = (s+1)%n;
		it.upd(s%n,1234567); it2.upd(s%n,1);
	}
	printf("%lld\n",res);

    return 0;
}