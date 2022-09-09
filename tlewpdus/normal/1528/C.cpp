#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
vector<int> lis1[300100], lis2[300100];
int st[300100], en[300100];

int tim;
void idfs(int here) {
	st[here] = tim++;
	for (int &there : lis2[here]) {
		idfs(there);
	}
	en[here] = tim-1;
}

set<pii> se;
int ans;
void tdfs(int here) {
	pii tmp = {-1,-1};
	pii cur = {st[here],en[here]};
	auto it = se.lower_bound(cur);
	bool inserted = true;
//	printf("%d : %d %d\n",here,cur);
	if (it!=se.begin() && ((*prev(it)).first <= cur.first && cur.second <= (*prev(it)).second)) {
		tmp = (*prev(it));
		se.erase(prev(it));
		se.insert(cur);
//		printf("- %d %d\n",*prev(it));
//		printf("+ %d %d\n",cur);
	}
	else if (it != se.end() && cur.first <= (*it).first && (*it).second <= cur.second) {
		inserted = false;
	}
	else {
		se.insert(cur);
//		printf("+ %d %d\n",cur);
	}
	ans = max(ans, (int)se.size());
	for (int &there : lis1[here]) {
		tdfs(there);
	}
	if (inserted) {
		se.erase(cur);
		if (tmp.first!=-1) se.insert(tmp);
	}
}

int main () {
	int tt;
	scanf("%d",&tt);
	while(tt--) {
		tim = 0; ans = 1;
		scanf("%d",&N);
		for (int i=1;i<N;i++) {
			int a;
			scanf("%d",&a); --a;
			lis1[a].push_back(i);
		}
		for (int i=1;i<N;i++) {
			int a;
			scanf("%d",&a); --a;
			lis2[a].push_back(i);
		}
		idfs(0);
		se.clear();
		tdfs(0);
		printf("%d\n",ans);
		for (int i=0;i<N;i++) {
			lis1[i].clear();
			lis2[i].clear();
		}
	}

	return 0;
}