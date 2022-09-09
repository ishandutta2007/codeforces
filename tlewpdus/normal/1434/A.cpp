#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

struct idxtree {
	ll tree[270000];
	const int key = 131072;
	void init() {
		for (int i=0;i<key*2;i++) tree[i] = -LINF;
	}
	void upd(int idx, ll val) {
//		printf("%d : %lld\n",idx,val);
		idx+=key;
		tree[idx] = val;
		idx/=2;
		while(idx) {
			tree[idx] = max(tree[idx*2],tree[idx*2+1]);
			idx/=2;
		}
	}
} it;

int N;
int A[6], B[100100];
int loc[100100];

int main() {
	for (int i=0;i<6;i++) scanf("%d",&A[i]), A[i] = -A[i];
	sort(A,A+6);
	scanf("%d",&N);
	for (int i=0;i<N;i++) scanf("%d",&B[i]);
	sort(B,B+N);
	it.init();
	vector<pii> vec;
	for (int i=0;i<N;i++) {
		for (int j=0;j<6;j++) {
			vec.push_back({B[i]+A[j],i});
		}
		it.upd(i,B[i]+A[0]);
	}
	sort(vec.begin(),vec.end());
	ll mini = LINF;
	for (pii &e : vec) {
		int i = e.second;
		mini = min(mini,it.tree[1]-e.first);
		loc[i]++;
		if (loc[i]<6) it.upd(i,B[i]+A[loc[i]]);
		else it.upd(i,LINF);
	}
	printf("%lld\n",mini);

	return 0;
}