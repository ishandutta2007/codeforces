#include<algorithm>
#include<cstdio>
#include<vector>
#include<iostream>
#include<set>
using namespace std;
typedef long long ll;
const ll INF = 0x7fffffffffffffff;
const int maxn = 2e5;
struct edge {
	bool operator < (const edge& rhs)const {
		return weight < rhs.weight;
	}
	int from, to;
	ll weight;
}e[2 * maxn + 5];
ll weight[maxn + 5], res, min_res = INF;
int ufs[maxn + 5], n, m, pos;
int find(int x) {
	return x == ufs[x] ? x : ufs[x] = find(ufs[x]);
}
bool unite(int x, int y) {
	int a = find(x), b = find(y);
	if (a == b)return false;
	ufs[a] = b;
	return true;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> weight[i];
		if (weight[i] < min_res) {
			pos = i;
			min_res = weight[i];
		}
		ufs[i] = i;
	}
	for (int i = 1; i <= m; ++i)cin >> e[i].from >> e[i].to >> e[i].weight;
	for (int i = 1; i <= n; ++i) {
		if (pos != i) {
			e[++m].from = pos;
			e[m].to = i;
			e[m].weight = weight[i] + weight[pos];
		}
	}
	sort(e + 1, e + 1 + m);
	for (int i = 1; i <= m; ++i) {
		if (unite(e[i].from, e[i].to))res += e[i].weight;
	}
	cout << res << endl;
	return 0;
}