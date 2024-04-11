#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 100005;

int n, m, tt, num[2][N], my = 0, you = 1, mysize, yousize;
vector<int> v[2], tmps;

int cal(const int tar) {
	int ret = 0;
	int mins = v[you][0], maxs = v[you][v[you].size() - 1];
	int starts = 0, ends = v[my].size() - 1, l1, r1, m1;
	l1 = 0; r1 = v[my].size() - 1;
	while (r1 - l1 > 1) {
	  m1 = (r1 + l1) / 2;
	  if (v[my][m1] + maxs < tar) l1 = m1; else r1 = m1;
	}
	starts = l1;
	l1 = 0; r1 = v[my].size() - 1;
	while (r1 - l1 > 1) {
	  m1 = (r1 + l1) / 2;
	  if (v[my][m1] + mins > m + tar) r1 = m1; else l1 = m1;
	}
	ends = r1;
	//cout << endl;
	//cout << tar << ' ' << ends - starts << ' ' << mysize << ' ' << yousize << endl;
	for (int i = starts; i <= ends; ++i) {
		int t1 = v[my][i], t2 = tar - v[my][i];
		if (num[my][t1] == 0) continue;
	  if (t2 < 0) t2 += m;
	  int tmp = min(num[my][t1], num[you][t2]);
	  if (tmp != 0) {
	    ret += tmp;
	    num[you][t2] -= tmp;
	    num[my][t1] -= tmp;
	    if (num[you][t2] == 0) --yousize;
	    if (num[my][t1] == 0) --mysize;
		}
	}
	if (mysize + mysize / 2 < v[my].size() || mysize > yousize) {
	  tmps.clear();
	  for (int i = 0; i < v[my].size(); ++i) {
	    if (num[my][v[my][i]]) {
	      tmps.push_back(v[my][i]);
			}
		}
		v[my] = tmps;
	}
	if (mysize > yousize) {
	  tmps.clear();
	  for (int i = 0; i < v[you].size(); ++i) {
	    if (num[you][v[you][i]]) {
	      tmps.push_back(v[you][i]);
			}
		}
		v[you] = tmps;
		swap(my, you);
		mysize = v[my].size();
		yousize = v[you].size();
	}
	return ret;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
	  scanf("%d", &tt);
	  num[0][tt]++;
	}
	for (int j = 1; j <= n; ++j) {
	  scanf("%d", &tt);
	  num[1][tt]++;
	}
	for (int i = 0; i < m; ++i) {
	  if (num[0][i] != 0) {
			v[0].push_back(i);
		}
		if (num[1][i] != 0) {
			v[1].push_back(i);
		}
	}
	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());
	mysize = v[my].size();
	yousize = v[you].size();
	bool flag = false;
	for (int i = m - 1; i >= 0; --i) {
	  int k = cal(i);
	  while (k--) {
	  	if (flag) printf(" "); else flag = true;
	  	printf("%d", i);
	  }
	}
	printf("\n");
	return 0;
}