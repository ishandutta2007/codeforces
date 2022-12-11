#include <iostream>

using namespace std;

const int INF = 10000;

int a[16];
int n, m, mini = INF;
bool light[15][110];
int lft[15], rght[15];
int maxlvl;

int go() {
	int ans = 0;
	int pos = 0;
	//cout << "//";
	for (int i = 0; i <= maxlvl; i ++) {
		if (lft[i] == -1) {
			if (i != maxlvl) {
				ans ++;
				continue;
			}
			break;
		}
		if (pos == 0) {
			ans += rght[i];
			if (i != maxlvl) {
				ans += abs(rght[i] - a[i]) + 1;
			}
		}
		else {
			ans += pos - lft[i];
			if (i != maxlvl) {
				ans += abs(lft[i] - a[i]) + 1;
			}
		}
		pos = a[i];
		//cout << ans << ' ';
	}
	//cout << endl;
	return ans;
}

void gen(int x) {
	if (x == n - 1) {
		int aa = go();
		//cout << "(" << aa << ")" << endl;
		if (aa < mini) {
			mini = aa;
		}
		return;
	}
	a[x] = 0;
	gen(x + 1);
	a[x] = m + 1;
	gen(x + 1);
}



int main () {
	cin >> n >> m;
	char nw;
	for (int i = n - 1; i >= 0; i --) {
		rght[i] = -1;
		lft[i] = -1;
		for (int j = 0; j < m + 2; j ++) {
			cin >> nw;
			if (nw == '1') {
				light[i][j] = 1;
			}
			else {
				light[i][j] = 0;
			}
			//cout << i << ' ' <<  j << ' ' << light[i][j] << endl;
			if (light[i][j] && lft[i] == -1) {
				lft[i] = j;
			}
			if (light[i][j]) {
				rght[i] = j;
			}
		}
	}
	maxlvl = n - 1;
	while (lft[maxlvl] == -1) {
		maxlvl --;
	}
	gen(0);
	cout << mini << endl;
	return 0;
}