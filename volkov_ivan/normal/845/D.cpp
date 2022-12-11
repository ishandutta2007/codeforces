#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, speed, red = 0, cnt = 0, t, s;
	cin >> n;
	vector <int> st;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t == 1) {
			cin >> s;
			speed = s;
			while (!st.empty() && st.back() < s) {
				st.pop_back();
				cnt++;
			}
			continue;
		}
		if (t == 2) {
			cnt += red;
			red = 0;
			continue;
		}
		if (t == 3) {
			cin >> s;
			if (speed > s) {
				cnt++;
			} else {
				st.push_back(s);
			}
			//cout << cnt << endl;
			continue;
		}
		if (t == 4) {
			red = 0;
			continue;
		}
		if (t == 5) {
			st.clear();
			continue;
		}
		red++;
	}
	cout << cnt << endl;
	return 0;
}