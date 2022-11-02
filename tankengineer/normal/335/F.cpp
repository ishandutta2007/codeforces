#include<map>
#include<set>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	long long sum = 0;
	scanf("%d", &n);
	map<int, int> items;
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		++items[a];
		sum += a;
	}
	int total = 0;
	multiset<int> bargins;
	for (map<int, int>::reverse_iterator it = items.rbegin(); it != items.rend(); ++it) {
		int v = it->first, c = it->second;
		int max_free = total < c ? total : (total + c) / 2;
		int num = min(max_free, c);
		int offset = max_free - (int)bargins.size();
		multiset<int>::iterator pos = bargins.begin();
		for (int i = 0; i < num - offset; ++i) {
			++pos;
		}
		vector<int> ori(bargins.begin(), pos);
		reverse(ori.begin(), ori.end());
		bargins.erase(bargins.begin(), pos);
		vector<int> add;
		add.assign(num, v);
		if (total + min(total, c) & 1) {
			add.push_back(0);
		}
		for (int i = 0; i < (int)ori.size(); ++i) {
			if (ori[i] > add[i]) {
				add[i] = ori[i];
				add[(int)add.size() - 1 - i] -= ori[i] - v;
			}
		}
		while (add.size() && add.back() <= 0) {
			add.pop_back();
		}
		bargins.insert(add.begin(), add.end());
		total += c;
	}
	for (multiset<int>::iterator it = bargins.begin(); it != bargins.end(); ++it) {
		sum -= *it;
	}
	cout << sum << endl;
	return 0;
}