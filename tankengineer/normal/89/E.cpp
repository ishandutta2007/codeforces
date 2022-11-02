#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1005;
int n, p[N], pos;
string ans;

void goRight(int l = 1) {
	for (int i = 0; i < l; ++i) {
		ans += 'A';
		ans += 'R';
		++pos;
	}
}

void goLeft(int l = 1) {
	for (int i = 0; i < l; ++i) {
		ans += 'L';
		--pos;
	}
}

void perform(int l, int r) {
	goRight(r - pos);
	ans += 'A';
	goLeft(pos - l + 1);
	ans += 'A';
	for (int i = l; i <= r; ++i) {
		--p[i];
	}
}

void solve(int l, int r) {
	while (p[l] <= 1 && l <= r) {
		++l;
	}
	if (l > r) {
		return;
	}
	while (p[l] > 1) {
		int cos = l;
		while (p[cos + 1] > 1) {
			++cos;
		}
		perform(l, cos);
	}
	solve(l + 1, r);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", p + i);
	}
	while (!p[n - 1]) {
		--n;
	}
	ans = "";
	pos = -1;
	for (int i = 0; i < n; ++i) {
		goRight();
		if (p[i]) {
			break;
		}
	}
	int lef = pos;
	for (int i = pos; i < n; ++i) {
		while (!p[i]) {
			++i;
		}
		int j = i;
		while (j + 1 < n && p[j + 1]) {
			++j;
		}
		solve(i, j);
		//cleared to 1 = lef - j
		if (lef == -1) {
			lef = i;
		}
		if (j != n - 1) {
			int empty = 0;
			while (p[j + empty + 1] == 0) {
				++empty;
			}
			if (empty > (j - lef + 1) + 3) {
				perform(lef, j);
				lef = -1;
			}
		} else {
			perform(lef, n - 1);
		}
		i = j;	
	}
	printf("%s\n", ans.c_str());
	return 0;
}