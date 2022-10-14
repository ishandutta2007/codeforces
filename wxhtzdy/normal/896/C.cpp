#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1000000007;

int n, m, seed, vmax, a[100005];

int rnd()
{
	int ret = seed;
	seed = (1LL * seed * 7 + 13) % MOD;
	return ret;
}

LL power(LL x, LL t, LL m)
{
	x %= m;
	LL ret = 1;
	while(t > 0) {
		if(t & 1) ret = 1LL * ret * x % m;
		x = (1LL * x * x) % m;
		t >>= 1;
	}
	return ret;
}

map<int, LL> col;
void cut(int i) 
{
	if(col.find(i) == col.end()) col[i] = prev(col.lower_bound(i))->second;
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &seed, &vmax);
	rep1(i, n) {
		a[i] = (rnd() % vmax) + 1;
		col[i] = a[i];
	}
	col[n + 1] = 0;
	
	while(m --) {
		int op = (rnd() % 4) + 1;
		int l = (rnd() % n) + 1;
		int r = (rnd() % n) + 1;
		if(l > r) swap(l, r);
		int x;
		if(op == 3) x = (rnd() % (r - l + 1)) + 1;
		else x = (rnd() % vmax) + 1;
		
		//printf("%d %d %d %d\n", op, l, r, x);
		cut(l); cut(r + 1);
		if(op == 1) {
			map<int, LL>::iterator it = col.find(l);
			while(it->first <= r) {
				col[it->first] += x;
				it = next(it);
			}
		} else if(op == 2) {
			map<int, LL>::iterator it = col.find(l);
			while(it->first <= r) {
				it = col.erase(it);
			}
			col[l] = x;
		} else if(op == 3) {
			vector<pair<LL, int>> v;
			map<int, LL>::iterator it = col.find(l);
			while(it->first <= r) {
				int L = it->first;
				int R = next(it)->first;
				v.push_back(MP(it->second, R - L));
				it = next(it);
			}
			sort(v.begin(), v.end());
			int i = 0;
			while(i < v.size()) {
				x -= v[i].second;
				if(x <= 0) break;
				i ++;
			}
			printf("%lld\n", v[i].first);
		} else {
			LL y = (rnd() % vmax) + 1;
			map<int, LL>::iterator it = col.find(l);
			LL ans = 0;
			while(it->first <= r) {
				int L = it->first;
				int R = min(r + 1, next(it)->first);
				ans += 1LL * power(it->second, x, y) * 1LL * (R - L) % y;
				ans %= y;
				it = next(it);
			}
			printf("%lld\n", ans);
		}
	}	
	return 0;
}