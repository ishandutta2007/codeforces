#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int ans, anst;

void update(int a, int b) {
	if (a > ans || a == ans && anst > b) {
		ans = a, anst = b;
	}
}

const int INF = 1000000007;

int n, f, d, s;

int main() {
	scanf("%d%d%d", &n, &d, &s);
	ans = 0, anst = 0;
	vector<int> leaf, node;
	int dgrsum = 0, scnt = 0;
	for (int i = 0; i < n; ++i) {
		int c, f, l;
		scanf("%d%d%d", &c, &f, &l);
		f = l < d ? INF : f;
		if (c == 0) {
			leaf.push_back(f);
		} else {
			node.push_back(f);
			dgrsum += c;
			scnt += 1;
		}
	}
	sort(leaf.begin(), leaf.end());
	sort(node.begin(), node.end());
	//use only leaf
	int s0 = s, c0 = 0;
	for (int i = 0; i < (int)leaf.size(); ++i) {
		if (s0 >= leaf[i]) {
			s0 -= leaf[i];
			c0++;
		}
	}
	update(c0, s - s0);
	//
	if (node.size() > 0 && node[0] <= s) {
		int s1 = s - node[0], c1 = scnt;
		while (leaf.size() && c1 < dgrsum + 1) {
			c1 += 1;
			leaf.pop_back();
		}
		int i = 0, j = 1;
		while (i < leaf.size()) {
			if (j < (int)node.size() && node[j] < leaf[i]) {
				if (s1 >= node[j]) {
					s1 -= node[j];
					c1++;
					leaf.pop_back();
				}
				++j;
			} else {
				if (s1 >= leaf[i]) {
					s1 -= leaf[i];
					c1++;
				}
				++i;
			}
		}
		update(c1, s - s1);
	}
	printf("%d %d\n", ans, anst);
	return 0;
}