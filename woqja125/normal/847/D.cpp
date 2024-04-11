#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define one first
#define two second

const int INF = 0x3f2f1f0f;

typedef long long ll;
typedef pair<int, ll> pil;
typedef pair<string, string> pss;

const int MAX_N = 2e5 + 100;

int N, Nr[MAX_N], T;
map<int, vector<int>> Mp;
vector<int> List;


struct NODE {
	int l, r, cnt;
	NODE *lp, *rp;
	NODE() : l(0), r(0), cnt(0), lp(NULL), rp(NULL) {}
	NODE(int a, int b) : l(a), r(b), cnt(0), lp(NULL), rp(NULL) {
		if(a == b) return;
		int m = (a+b) >> 1;
		lp = new NODE(a, m);
		rp = new NODE(m+1, b);
	}
	~NODE() {
		if(lp != NULL) delete lp;
		if(rp != NULL) delete rp;
	}
	NODE* add(int val) {
		if(l > val || r < val) return this;
		NODE *res = new NODE(); res->l=l; res->r=r;
		int m = (l+r) >> 1;
		if(l != r) {
			res->lp = lp->add(val);
			res->rp = rp->add(val);
		}
		res->cnt = cnt + 1;
		return res;
	}
	int getCnt(int a, int b) {
		if(l > b || r < a) return 0;
		if(a <= l && r <= b) return cnt;
		return lp->getCnt(a, b) + rp->getCnt(a, b);
	}
};
NODE *root[MAX_N];

int main() {
	cin >> N >> T;
	for(int i=1; i<=N; i++) {
		scanf("%d", &Nr[i]);
		Nr[i] = max(i, Nr[i]) - i;
		Mp[Nr[i]].push_back(i);
		List.push_back(Nr[i]);
	}
	sort(ALL(List)); List.erase(unique(ALL(List)), List.end());

	root[0] = new NODE(0, SZ(List)-1);
	for(int i=1; i<=N; i++) {
		Nr[i] = lower_bound(ALL(List), Nr[i]) - List.begin();
		root[i] = root[i-1]->add(Nr[i]);
	}
	int ans = 0;
	for(int k=0; k<SZ(List); k++) {
		int x = List[k];
		int i = min(N, T - x - 1);
		if(i <= 0) continue;
		int now = root[i]->getCnt(0, k);
		ans = max(ans, now);
	}
	printf("%d\n", ans);
	return 0;
}