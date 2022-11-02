#include<set>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n;

int main() {
	set<int> cur, vis;
	vector<int> ans;
	int last = 0;
	bool valid = true;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int id;
		scanf("%d", &id);
		if (id > 0) {
			if (cur.count(id) || vis.count(id)) {
				valid = false;
			}
			cur.insert(id);
			vis.insert(id);
		} else {
			id = -id;
			if (!cur.count(id)) {
				valid = false;
			}
			cur.erase(id);
		}
		last++;
		if (cur.size() == 0) {
			ans.push_back(last);
			vis.clear();
			last = 0;
		}
	}
	if (last != 0) {
		valid = false;
	}
	if (!valid) {
		printf("-1\n");
	} else {
		printf("%d\n", (int)ans.size());
		for (int i = 0; i < (int)ans.size(); ++i) {
			printf("%d%c", ans[i], i == (int)ans.size() - 1 ? '\n' : ' ');
		}
	}
	return 0;
}