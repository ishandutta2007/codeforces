#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m, r, c;
		cin >> n >> m >> r >> c;
		--r; --c;
		vector<string> a(n);
		bool foundB = false;
		bool foundInColumn = false;
		for (string &row : a) {
			cin >> row;
			if (row.find('B') != -1) {
				foundB = true;
			}
			if (row[c] == 'B') {
				foundInColumn = true;
			}
		}
		bool foindInRow = a[r].find('B') != -1;
		if (a[r][c] == 'B') {
			cout << "0\n";
		} else if (foindInRow || foundInColumn) {
			cout << "1\n";
		} else if (foundB) {
			cout << "2\n";
		} else {
			cout << "-1\n";
		}
	}
	return 0;
}