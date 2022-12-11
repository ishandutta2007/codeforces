#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_set <long long> visited;
vector <long long> ans;
long long a, b;

bool DFS(long long x) {
	if (x == b) {
		ans.push_back(x);
		return true;
	}
	visited.insert(x);
	if (10 * x + 1 <= b && visited.find(10 * x + 1) == visited.end() && DFS(10 * x + 1)) {
		ans.push_back(x);
		return true;
	}
	if (2 * x <= b && visited.find(2 * x) == visited.end() && DFS(2 * x)) {
		ans.push_back(x);
		return true;
	}
	return false;
}

int main() {
	cin >> a >> b;
	if (DFS(a)) {
		cout << "YES" << endl;
		cout << ans.size() << endl;
		for (int i = ans.size() - 1; i >= 0; i --) {
			cout << ans[i] << ' ';
		}
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}