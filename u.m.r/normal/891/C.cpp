#include<bits/stdc++.h>
#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int MM = 1e9 + 7;
const int MAXN = 5e5 + 10;

namespace DSU2 {
  const static int MAXN = 1000000 + 10;
  int fa[MAXN], ds[MAXN], rk[MAXN];
  int S[MAXN], top;
  void init(int n) {
    for (int i = 1; i <= n; ++ i) {
      fa[i] = i, rk[i] = ds[i] = 0;
    }
    top = 0;
  }
  int dis(int x) {
    int r(0);
    for (; x != fa[x]; x = fa[x]) r ^= ds[x];
    return r;
  }
  int get(int x) {
    while (x != fa[x]) x = fa[x];
    return fa[x];
  }
  void merge(int x, int y, int d) {
    x = get(x); y = get(y);
    if (x == y) return;
    if (rk[x] > rk[y]) std::swap(x, y);
    if (rk[x] == rk[y]) ++ rk[y], S[++ top] = -y;
    fa[x] = y; ds[x] = d; S[++ top] = x;
  }
  void restore(int ed) {
    for (; top > ed; -- top) {
      if (S[top] < 0) -- rk[-S[top]];
      else fa[S[top]] = S[top], ds[S[top]] = 0;
    }
  }
}

int n, m;
int Q;
struct edge{
	int x, y, z, num;
} e[MAXN];

vector<int> H[MAXN];
int lab[MAXN];
int ans[MAXN];
vector<int> tmp[MAXN];

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		//E[x].push_back(PII(y, z));
		//E[y].push_back(PII(x, z));
		e[i].x = x, e[i].y = y, e[i].z = z;
		e[i].num = i;
	}
	scanf("%d", &Q);
	for (int i = 1; i <= Q; i++){
		int x, y;
		scanf("%d", &x);
		for (int j = 1; j <= x; j++){
			scanf("%d", &y);
			//F[i].push_back(y);
			H[y].push_back(i);
		}
		ans[i] = 1;
	}
	sort(e + 1, e + m + 1, [](const edge&a, const edge&b){
		return a.z < b.z;
	});
	e[m + 1].z = e[m].z + 1;
	DSU2::init(n);
	for (int i = 1, nico = 1; i <= m; nico++){
		int l = i;
		while (e[i].z == e[l].z) i++;
		int r = i;
		vector<int> qqq;
		for (int j = l; j < r; j++){
			int en = e[j].num;
			for (auto &x : H[en]){
				if (lab[x] != nico){
					lab[x] = nico;
					tmp[x].clear();
					qqq.push_back(x);
				}
				tmp[x].push_back(j);
			}
		}
		for (auto &q : qqq){
			int nowed = DSU2::top;
			int flag = 1;
			for (auto &edg : tmp[q]){
				int u = DSU2::get(e[edg].x), v = DSU2::get(e[edg].y);
				if (u == v){
					flag = 0;
					break;
				}
				DSU2::merge(e[edg].x, e[edg].y, 1);
			}
			if (flag == 0){
				ans[q] = 0;
			}
			DSU2::restore(nowed);
		}
		for (int j = l; j < r; j++){
			DSU2::merge(e[j].x, e[j].y, 1);
		}
	}
	for (int i = 1; i <= Q; i++)
		puts(ans[i] ? "YES" : "NO");
	return 0;
}