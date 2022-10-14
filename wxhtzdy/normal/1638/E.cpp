/* https://codeforces.com/problemset/problem/444/C */
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, q;
LL tot[1000005];

struct fwt
{
	LL dat[1000005];
	fwt() { rep(i, 1000005) dat[i] = 0; }
	void add(int id, LL val)
	{
		for(; id <= 1000000; id += id & -id) dat[id] += val;
	}
	LL query(int id)
	{
		LL ret = 0;
		for(; id > 0; id -= id & -id) ret += dat[id];
		return ret;
	}
}tre;

map<int, int> col;
void cut(int i)
{
	if(col.find(i) == col.end()) col[i] = prev(col.lower_bound(i))->second;
}
int main()
{
	scanf("%d%d", &n, &q);
	col[1] = 1;
	col[n + 1] = 1;
	while(q --) {
		char op[7];
		scanf("%s", op);
		if(op[0] == 'C') {
			int l, r, c;
			scanf("%d%d%d", &l, &r, &c);
			r ++; cut(l); cut(r);
			auto it = col.find(l);
			while(it->first < r) {
				int L = it->first, R = next(it)->first;
				LL d = tot[it->second] - tot[c];
				tre.add(L, d); tre.add(R, -d);
				it = col.erase(it);
			}
			col[l] = c;
		} else if(op[0] == 'A') {
			int c, x;
			scanf("%d%d", &c, &x);
			tot[c] += x;
		} else {
			int i;
			scanf("%d", &i);
			auto it = (col.find(i) == col.end() ? prev(col.lower_bound(i)) : col.find(i));
			printf("%lld\n", tot[it->second] + tre.query(i));
		}
	}
	return 0;
}