#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void solve() 
{
	int n;
	scanf("%d", &n);
	vector<vector<int> > seg(n - 1);
	vector<vector<int> > el(n);
	
	int k;
	for (int i = 0; i < n - 1; ++i) {
		scanf("%d", &k);
		seg[i].resize(k);
		for (int j = 0; j < k; ++j) {
			scanf("%d", &seg[i][j]);
			--seg[i][j];
			el[seg[i][j]].push_back(i);
		}
	}
	
	for (int fi = 0; fi < n - 1; ++fi) {
		if (seg[fi].size() == 2) {
			for (int P = 0; P < 2; ++P) {
				bool ok = true;
				swap(seg[fi][0], seg[fi][1]);
				vector<int> amt(n - 1);
				vector<bool> used(n - 1);
				vector<bool> inserted(n);
				vector<int> p(n);
				p[0] = seg[fi][0];
				p[1] = seg[fi][1];
				for (int i = 0; i < el[p[0]].size(); ++i) ++amt[el[p[0]][i]];
				for (int i = 0; i < el[p[1]].size(); ++i) ++amt[el[p[1]][i]];
				inserted[p[0]] = true;
				inserted[p[1]] = true;
				used[fi] = true;
				int i;
				for (i = 2; i < n; ++i) {
					int ind = -1;
					int j;
					for (j = 0; j < n - 1; ++j) if (!used[j] && seg[j].size() - amt[j] == 1) ind = j;
					if (ind == -1) ok = false;
					if (!ok) break;
					used[ind] = true;
					for (j = 0; j < seg[ind].size() && inserted[seg[ind][j]]; ++j);
					p[i] = seg[ind][j];
					inserted[p[i]] = true;
					for (int j = 0; j < el[p[i]].size(); ++j) ++amt[el[p[i]][j]];
				}
				if (!ok) continue;
				vector<int> pos(n);
				for (int i = 0; i < n; ++i) pos[p[i]] = i;
				vector<vector<int> > segcpy = seg;
				for (int i = 0; i < n - 1; ++i) {
					for (int j = 0; j < segcpy[i].size(); ++j) segcpy[i][j] = pos[segcpy[i][j]];
					sort(segcpy[i].begin(), segcpy[i].end());
				}
				vector<bool> right(n);
				for (int i = 0; i < n - 1 && ok; ++i) {
					for (int j = 1; j < segcpy[i].size() && ok; ++j) 
						if (segcpy[i][j] - segcpy[i][j - 1] != 1) ok = false;
					right[*(segcpy[i].end() - 1)] = 1;
				}
				if (right[0]) ok = false;
				for (int i = 1; i < n; ++i) if (!right[i]) ok = false;
				if (!ok) continue;
				for (int i = 0; i < n; ++i) printf("%d ", p[i] + 1);
				printf("\n");
				return;
			}
		}
		swap(seg[fi][0], seg[fi][1]);
	}
}

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}