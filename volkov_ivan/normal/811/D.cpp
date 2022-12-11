#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

bool swapUD = 0, swapLR = 0, madeUD = 0, madeLR = 0;
const int MaxN = 1000, MaxM = 1000;
int n, m;
char field[MaxN][MaxM];
bool visited[MaxN][MaxM];
vector < char > goes;


void go(char dir) {
	int a, b;
	if (dir == 'U') {
		cout << (swapUD ? 'D' : 'U') << endl;
		cin >> a >> b;
	}
	if (dir == 'D') {
		if (madeUD) {
			cout << (swapUD ? 'U' : 'D') << endl;
			cin >> a >> b;
		}
		else {
			cout << 'D' << endl;
			cin >> a >> b;
			madeUD = 1;
			if (a == 1) {
				swapUD = 1;
				cout << 'U' << endl;
				cin >> a >> b;
			}
		}
	}
	if (dir == 'L') {
		cout << (swapLR ? 'R' : 'L') << endl;
		cin >> a >> b;
	}
	if (dir == 'R') {
		if (madeLR) {
			cout << (swapLR ? 'L' : 'R') << endl;
			cin >> a >> b;
		}
		else {
			cout << 'R' << endl;
			cin >> a >> b;
			madeLR = 1;
			if (b == 1) {
				swapLR = 1;
				cout << 'L' << endl;
				cin >> a >> b;
			}
		}
	}
}

bool DFS(int i, int j) {
	visited[i][j] = true;
	if (field[i][j] == 'F') {
		return true;
	}
	if (i > 0 && field[i - 1][j] != '*' && (! visited[i - 1][j])) {
		if (DFS(i - 1, j)) {
			goes.push_back('U');
			return true;
		}
	}
	if (i + 1 < n && field[i + 1][j] != '*' && (! visited[i + 1][j])) {
		if (DFS(i + 1, j)) {
			goes.push_back('D');
			return true;
		}
	}
	if (j > 0 && field[i][j - 1] != '*' && (! visited[i][j - 1])) {
		if (DFS(i, j - 1)) {
			goes.push_back('L');
			return true;
		}
	}
	if (j + 1 < m && field[i][j + 1] != '*' && (! visited[i][j + 1])) {
		if (DFS(i, j + 1)) {
			goes.push_back('R');
			return true;
		}
	}
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			cin >> field[i][j];
		}
	}
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			visited[i][j] = false;
		}
	}
	DFS(0, 0);
	for (int i = goes.size() - 1; i >= 0; i --) {
		go(goes[i]);
	}
	return 0;
}