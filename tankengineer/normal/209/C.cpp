#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 1000005;

int n, m, t1, t2, fa[N], size[N], dgr[N], cnt, tmp, f[2][N], anst;
vector<int> ans;

int find(const int i) {return fa[i] == i ? i : fa[i] = find(fa[i]);}
void merge(const int i, const int j) {
  if (size[i] >= size[j]) {
	  fa[j] = i;
	  size[i] += size[j];
	} else {
	  fa[i] = j;
	  size[j] += size[i];
	}
}

int main() {
	scanf("%d %d", &n, &m);
	if (m == 0) {
		printf("0\n");
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
	  fa[i] = i;
	  size[i] = 1;
	  dgr[i] = 0;
	}
	for (int i = 1; i <= m; ++i) {
	  scanf("%d %d", &t1, &t2);
	  ++dgr[t1]; ++dgr[t2];
	  if (find(t1) != find(t2)) merge(find(t1), find(t2));
	}
	for (int i = 1; i <= n; ++i) if (dgr[i]) f[dgr[i] % 2][find(i)]++;
	for (int i = 1; i <= n; ++i) if (find(i) == i && dgr[i]) ans.push_back(f[1][i]);
	if (dgr[1] == 0) ans.push_back(0);
  sort(ans.begin(), ans.end());
  tmp = ans[ans.size() - 1];
	for (int i = ans.size() - 2; i >= 0; --i) {
    if (tmp < ans[i]) swap(tmp, ans[i]);
	  if (ans[i] == 0 && tmp == 0) {
		  ++anst;
		  tmp += 2;
		} else if (ans[i] == 0 && tmp != 0) {
			++anst;
		} else {
			++anst;
			tmp += ans[i] - 2;
		}
	}
	anst += tmp / 2;
	printf("%d\n", anst);
	return 0;
}