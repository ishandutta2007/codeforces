#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 100001;

int main () {
	int n, x1, y1, x2, y2;
	cin >> n;
	cin >> x1 >> y1 >> x2 >> y2;
	pair < pair <int, int>, pair <int, int> > mice[n];
	for (int i = 0; i < n; i ++) {
		cin >> mice[i].first.first >> mice[i].first.second >> mice[i].second.first >> mice[i].second.second;
	}
	pair <double, char> smth[2 * n];
	pair <double, bool> times[4];
	double beg, fin;
	bool zero, one, op, was;
	for (int i = 0; i < n; i ++) {
		//cout << (x1 - mice[i].first.first) / mice[i].second.first << endl;
		if (mice[i].second.first != 0) {
			times[0] = pair <double, bool> (double(x1 - mice[i].first.first) / mice[i].second.first, 0);
			times[1] = pair <double, bool> (double(x2 - mice[i].first.first) / mice[i].second.first, 0);
		}
		else {
			if (mice[i].first.first <= x1 || mice[i].first.first >= x2) {
				cout << -1 << endl;
				return 0;
			}
			times[0] = pair <double, bool> (-INF, 0);
			times[1] = pair <double, bool> (INF, 0);

		}
		if (mice[i].second.second != 0) {
			times[2] = pair <double, bool> (double(y1 - mice[i].first.second) / mice[i].second.second, 1);
			times[3] = pair <double, bool> (double(y2 - mice[i].first.second) / mice[i].second.second, 1);
		}
		else {
			if (mice[i].first.second <= y1 || mice[i].first.second >= y2) {
				cout << -1 << endl;
				return 0;
			}
			times[2] = pair <double, bool> (-INF, 1);
			times[3] = pair <double, bool> (INF, 1);
		}
		//cout << times[0].first << ' ' << times[1].first << ' ' << times[2].first << times[3].first << endl;
		sort(times, times + 4);
		zero = 0;
		one = 0;
		op = 0;
		was = 0;
		for (int j = 0; j < 4; j ++) {
			if (times[j].second == 0) {
				zero = (! zero);
			}
			else {
				one = (! one);
			}
			if (zero && one && (! op)) {
				was = 1;
				op = 1;
				beg = times[j].first;
			}
			if (((! zero) || (! one)) && op) {
				op = 0;
				fin = times[j].first;
			}
		}
		//cout << beg << ' ' << fin << endl;
		if ((! was) || fin < 0) {
			cout << -1 << endl;
			return 0;
		}
		if (beg < 0) {
			beg = 0.0;
		}
		smth[2 * i] = pair <double, char> (beg, ')');
		smth[2 * i + 1] =  pair <double, char> (fin, '(');
	}
	//cout << endl << endl;
	sort(smth, smth + 2 * n);
	cout.precision(10);
	int cnt = 0;
	for (int i = 0; i < 2 * n; i ++) {
		//cout << smth[i].first << ' ' << smth[i].second << endl;
		if (smth[i].second == '(') {
			cnt --;
		}
		else {
			cnt ++;
		}
		if (cnt == n) {
			cout << fixed << smth[i].first << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}