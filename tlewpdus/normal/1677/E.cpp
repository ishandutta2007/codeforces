#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, Q;
int P[200100];
int L[200100];

pii ran[200100];

struct Upd {
	int s, e;
	ll a, b;
};

vector<Upd> upds[200100];

vector<pii> rects[200100];

struct Seg {
	ll tree[540000];
	ll rem[540000];
	void pd(int s, int e, int idx) {
		if (rem[idx]) {
			int m = (s+e)/2;
			rem[idx*2] += rem[idx];
			tree[idx*2] += rem[idx]*(m-s+1);
			rem[idx*2+1] += rem[idx];
			tree[idx*2+1] += rem[idx]*(e-m);
			rem[idx] = 0;
		}
	}
	void pu(int idx) {
		tree[idx] = tree[idx*2] + tree[idx*2+1];
	}
	void upd(int S, int E, ll val, int s=0, int e=N, int idx=1) {
		if (E<s||e<S) return;
		if (S<=s&&e<=E) {
			rem[idx] += val;
			tree[idx] += (e-s+1)*val;
			return;
		}
		pd(s,e,idx);
		int m = (s+e)/2;
		upd(S,E,val,s,m,idx*2);
		upd(S,E,val,m+1,e,idx*2+1);
		pu(idx);
	}
	ll getv(int S, int E, int s=0, int e=N, int idx=1) {
		if (E<s||e<S) return 0;
		if (S<=s&&e<=E) {
			return tree[idx];
		}
		pd(s,e,idx);
		int m = (s+e)/2;
		return getv(S,E,s,m,idx*2)+getv(S,E,m+1,e,idx*2+1);
	}
} sega, segb;

vector<pii> querys[200100];

ll ans[1000100];

int main() {
	scanf("%d%d",&N,&Q);
	for (int i=1;i<=N;i++) scanf("%d",&P[i]), L[P[i]] = i;
	set<int> s;
	s.insert(0); s.insert(N+1);
	for (int v=N;v;v--) {
		auto it = s.lower_bound(L[v]);
		ran[v] = {*prev(it)+1,*it-1};
		s.insert(L[v]);
	}
	for (int i=1;i<=N;i++) {
		for (int j=i+1;1LL*i*j<=N;j++) {
			if (ran[i*j].first<=min(L[i],L[j]) && max(L[i],L[j])<=ran[i*j].second) {
				rects[i*j].emplace_back(min({L[i * j], L[i], L[j]}) , max({L[i*j],L[i],L[j]}));
//				{ ran[i * j].first, }
//				{ max({L[i*j],L[i],L[j]}), ran[i*j].second}
			}
		}
	}
	for (int v=1;v<=N;v++) {
//		printf("%d: (%d, %d)\n",v,ran[v].first,ran[v].second);
		sort(rects[v].begin(),rects[v].end());
		reverse(rects[v].begin(),rects[v].end());
		int lasty = ran[v].second;
		for (pii &w : rects[v]) {
//			printf("%d: (%d, %d)\n",v,w.first,w.second);
			if (lasty < w.second) continue;
			upds[w.first].push_back({w.second,lasty, -1, w.first+1});
			upds[ran[v].first-1].push_back({w.second, lasty, 1, -ran[v].first});
//			if (ran[v].first==1) {
////				printf("%d: (%d, %d), (%d, %d)\n",v,ran[v].first,w.first,w.second,lasty);
//			}
			lasty = w.second-1;
		}
	}
	for (int i=0;i<Q;i++) {
		int l, r;
		scanf("%d%d",&l,&r);
		querys[l].emplace_back(r,i);
	}
	for (int i=N;i;i--) {
		for (Upd &u : upds[i]) {
			sega.upd(u.s,u.e,u.a);
			segb.upd(u.s,u.e,u.b);
		}
		for (pii &q : querys[i]) {
			ans[q.second] = sega.getv(i,q.first) * i + segb.getv(i,q.first);
		}
	}
	for (int i=0;i<Q;i++) {
		printf("%lld\n",ans[i]);
	}
//	puts("");

	return 0;
}