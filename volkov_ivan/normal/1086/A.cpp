#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector <pair <int, int>> best;

set <pair <int, int>> gen_path(pair <int, int> a, pair <int, int> b) {
	set <pair <int, int>> ans;
	ans.insert(a);
	while (a.first != b.first) {
		if (b.first > a.first) a.first++;
		else a.first--;
		ans.insert(a);
	}
	while (a.second != b.second) {
		if (a.second > b.second) a.second--;
		else a.second++;
		ans.insert(a);
	}
	return ans;
}

set <pair <int, int>> intersec(set <pair <int, int>> a, set <pair <int, int>> b) {
	set <pair <int, int>> ans;
	for (pair <int, int> elem : a) ans.insert(elem);
	for (pair <int, int> elem : b) ans.insert(elem);
	return ans;
}

int main() {
	vector <pair <int, int>> p;
	p.resize(3);
	for (int i = 0; i < 3; i++) {
		cin >> p[i].first >> p[i].second;
	}
	sort(p.begin(), p.end());
	set <pair <int, int>> now, now2, now3, ans1, ans2, ans3;
	now = gen_path(p[0], p[1]);
	now2 = gen_path(p[1], p[2]);	
	ans1 = intersec(now, now2);
	pair <int, int> p1 = make_pair(p[1].first, p[0].second), p2 = make_pair(p[1].first, p[2].second);
	ans2 = intersec(intersec(gen_path(p[0], p1), gen_path(p[1], p1)), gen_path(p[2], p1));
	ans3 = intersec(intersec(gen_path(p[0], p2), gen_path(p[1], p2)), gen_path(p[2], p2));
	set <pair <int, int>> ans = ans1;
	if (ans2.size() < ans.size()) ans = ans2;
	if (ans3.size() < ans.size()) ans = ans3;
	cout << ans.size() << endl;
	for (pair <int, int> elem : ans) {
		cout << elem.first << ' ' << elem.second << '\n';
	}
	return 0;
}