#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

struct elem {
	int key;
	int pos;
	elem(int key, int pos): key(key), pos(pos) {}
};

const int MAXN = 100010;
int v[MAXN];
int sum[MAXN];
int res[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	vector <elem> st;
	st.push_back(elem(v[0], n));
	vector <int> seg;
	seg.push_back(n - 1);
	for (int i = 1; i < n; i++) {
		int pos = -1;
		while (!st.empty() && v[i] > st.back().key) {
			pos = st.back().pos;
			st.pop_back();
		}
		pos++;
		if (!st.empty() && st.back().pos == pos) {
			st.pop_back();
		}
		st.push_back(elem(v[i], pos));
		seg.push_back(pos);
	}
	for (int i = 0; i < (int)seg.size(); i++) {
		sum[0]++;
		sum[seg[i] + 1]--;
	}
	res[0] = sum[0];
	for (int i = 1; i < n; i++) {
		res[i] = res[i - 1] + sum[i];
	}
	int ans = 0;
	for (int i = 0; i < n - 1; i ++) {
		if (res[i] > res[i + 1]) {
			ans++;
		} else {
			break;
		}
	}
	printf("%d", ans);
	return 0;
}