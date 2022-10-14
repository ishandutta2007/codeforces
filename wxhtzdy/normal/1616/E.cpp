#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;

int n, ptr[26];
char s[200005], t[200005];
vector<int> pos[26];

struct fenw
{
	int dat[200005];
	
	void init(int n) { rep(i, n + 1) dat[i] = 0; }
	
	void add(int id, int val) {
		for(; id <= n; id += id & -id) dat[id] += val;
	}
	
	int query(int id) {
		int ret = 0;
		for(; id > 0; id -= id & -id) ret += dat[id];
		return ret;
	}
	
	int query(int l, int r) {
		return query(r) - query(l - 1);
	}
} tre;

void solve()
{
	scanf("%d", &n);
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	rep(i, 26) pos[i].clear(), ptr[i] = 0;	
	tre.init(n);

	rep1(i, n) pos[s[i] - 'a'].push_back(i);
	LL ans = INF, cur = 0;
	rep1(i, n) {
		int cs = (int)(s[i] - 'a');
		int ct = (int)(t[i] - 'a');
		rep(j, ct) if(ptr[j] < pos[j].size()) ans = min(ans, cur + pos[j][ptr[j]] + tre.query(pos[j][ptr[j]], n) - i);
		if(ptr[ct] == pos[ct].size()) break;
		cur += pos[ct][ptr[ct]] + tre.query(pos[ct][ptr[ct]], n) - i; 
		tre.add(pos[ct][ptr[ct]], 1);
		ptr[ct] ++;
	}
	if(ans != INF) printf("%lld\n", ans); else printf("-1\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();	
	return 0;
}