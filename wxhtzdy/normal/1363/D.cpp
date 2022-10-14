#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, k, ans[1005];
vector<int> a[1005];

int query(vector<int>& ids)
{
	printf("? %d ", ids.size());
	rep(i, ids.size()) printf("%d ", ids[i]);
	printf("\n");
	fflush(stdout);
	int ret;
	scanf("%d", &ret);
	return ret;
}

bool have[1005];
int inv(vector<int>& v)
{
	rep(i, v.size()) have[v[i]] = true;
	vector<int> ret;
	rep1(i, n) if(!have[i]) ret.push_back(i);
	printf("? %d ", ret.size());
	rep(i, ret.size()) printf("%d ", ret[i]);
	printf("\n");
	fflush(stdout);
	int res;
	scanf("%d", &res);
	rep(i, v.size()) have[v[i]] = false;
	return res;
}

void solve()
{
	scanf("%d%d", &n, &k);
	rep(i, k) {
		int c;
		scanf("%d", &c);
		rep(j, c) {
			int x;
			scanf("%d", &x);
			a[i].push_back(x);
		}
	}
	vector<int> ids(n);
	rep(i, n) ids[i] = i + 1;
	int mx = query(ids);
	int l = 1, r = n;
	vector<int> id;
	while(l <= r) {
		if(l == r) break;
		int mid = l + r >> 1;
		id.clear();
		for(int i = l; i <= mid; i ++) id.push_back(i);
		if(query(id) == mx) assert(r != mid), r = mid; else l = mid + 1;
	}
	rep(i, k) {
		bool is = false;
		rep(j, a[i].size()) if(a[i][j] == l) is = true;
		if(is) ans[i] = inv(a[i]); else ans[i] = mx;
	}
	printf("! "); rep(i, k) printf("%d ", ans[i]); printf("\n"); fflush(stdout);
	char ZASTO[10]; scanf("%s", ZASTO);
	rep(i, k) a[i].clear();
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();	
	return 0;
}