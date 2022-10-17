#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

bool row[100000];
bool col[100000];
int main() {
	long long int n, m, x, y;
	cin >> n >> m;
	// bool* col = new bool[n];
	long long int coln = n;
	// bool* row = new bool[n];
	long long int rown = n;
	memset(col, false, sizeof(col));
	memset(row, false, sizeof(row));
	for (long long int i = 0; i < m; ++i) {
		cin >> x >> y;
		if (!col[x - 1]) {
			col[x - 1] = true;
			coln--;
		}
		if (!row[y - 1]) {
			row[y - 1] = true;
			rown--;
		}
		cout << coln * rown << ' ';
	}
	// delete row;
	// delete col;
	return 0;
}