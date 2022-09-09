#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int n, m, p;
pll arr[200100], brr[200100];
pll crr[200100];
ll cost[200100];
int ord[200100];

const int MAX = 1000100;

ll bit[MAX];
void upd(int idx, ll val) {
	idx++;
	while(idx<MAX) {
		bit[idx] += val;
		idx += idx&-idx;
	}
}
ll getv(int idx) {
	idx++;
	ll ans = 0;
	while(idx) {
		ans += bit[idx];
		idx&=idx-1;
	}
	return ans;
}

struct segtree {
	ll tree[2100000], rem[2100000];

	void pd(int idx) {
		if (!rem[idx]) return;
		tree[idx*2]+=rem[idx];
		rem[idx*2]+=rem[idx];
		tree[idx*2+1]+=rem[idx];
		rem[idx*2+1]+=rem[idx];
		rem[idx]=0;
	}
	void pu(int idx) {
		tree[idx] = max(tree[idx*2],tree[idx*2+1]);
	}

	void init(ll arr[], int s=0, int e=MAX-1,int idx=1) {
		if (s==e) {
			tree[idx] = arr[s];
			return;
		}
		rem[idx] = 0;
		int m = (s+e)/2;
		init(arr,s,m,idx*2);
		init(arr,m+1,e,idx*2+1);
		pu(idx);
	}

	void upd(int S, int E, ll val, int s=0, int e=MAX-1,int idx=1) {
		if (e<S||E<s) return;
		if (S<=s&&e<=E) {
			tree[idx]+=val;
			rem[idx]+=val;
			return;
		}
		pd(idx);
		int m = (s+e)/2;
		upd(S,E,val,s,m,idx*2);
		upd(S,E,val,m+1,e,idx*2+1);
		pu(idx);
	}

	ll getv(int S, int E, int s=0, int e=MAX-1, int idx=1) {
		if (e<S||E<s) return -LINF;
		if (S<=s&&e<=E) return tree[idx];
		pd(idx);
		int m = (s+e)/2;
		return max(getv(S,E,s,m,idx*2),getv(S,E,m+1,e,idx*2+1));
	}

} seg;

ll ctmp[MAX+10];
int main() {
	scanf("%d%d%d",&n,&m,&p);
	for (int i=0;i<n;i++) scanf("%lld%lld",&arr[i].first,&arr[i].second);
	for (int i=0;i<MAX;i++) ctmp[i] = -LINF;
	for (int i=0;i<m;i++) {
		scanf("%lld%lld",&brr[i].first,&brr[i].second);
		ctmp[brr[i].first] = max(ctmp[brr[i].first],-brr[i].second);
	}
	for (int i=0;i<p;i++) {
		scanf("%lld%lld%lld",&crr[i].first,&crr[i].second,&cost[i]);
		crr[i].first++; crr[i].second++;
	}
	sort(arr,arr+n);
	sort(brr,brr+m);
	seg.init(ctmp);
	iota(ord,ord+p,0);
	sort(ord,ord+p,[](int a, int b){return crr[a]<crr[b];});
	int i = 0, j = 0;
	ll ans = -LINF;
	while(i<n||j<p) {
		if ((i<n&&arr[i].first<crr[ord[j]].first)||j==p) {
			ans = max(ans,seg.getv(0,MAX-1)-arr[i].second);
			i++;
		}
		else {
			seg.upd(crr[ord[j]].second,MAX-1,cost[ord[j]]);
			j++;
		}
	}
	printf("%lld\n",ans);

	return 0;
}