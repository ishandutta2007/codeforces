#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;
typedef long long llong;
typedef pair<int, int> pi;

int stoi(char * s) {
	int ret = 0;
	if (*s == '0') return -1;
	while (*s) {
		if (*s < '0' | '9' < *s) return -1;
		ret = ret * 10 + *s - '0';
		++s;
	}
	return ret;
}

int n;
char str[100000][10];
int exs[100000];
bool check[100001];
int ex, re;
set<int> explace, repla, exfill, refill;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> str[i] >> exs[i];
		if (exs[i]) ++ex;
		else ++re;
	}
	for (int i = 1; i <= ex; ++i) {
		explace.insert(i);
	}
	for (int i = ex + 1; i <= n; ++i) {
		repla.insert(i);
	}
	bool easy = false;
	int tmp = -1;
	for (int i = 0; i < n; ++i) {
		int ret = stoi(str[i]);
		if (ret == -1 || ret > n) {
			easy = true;
			continue;
		}
		if (ret <= ex) {
			if (!exs[i]) {
				exfill.insert(ret);
				tmp = i;
			}
			explace.erase(ret);
		}
		else {
			if (exs[i]) {
				refill.insert(ret);
				tmp = i;
			}
			repla.erase(ret);
		}
	}

	if (!easy && tmp == -1) {
		printf("0\n");
		return 0;
	}
	printf("%d\n", explace.size() + repla.size() + exfill.size() + refill.size() + (1 - easy));
	
	if (!easy) {
		printf("move %s a\n", str[tmp]);
		int x = stoi(str[tmp]);
		if (x <= ex) {
			if (!exs[tmp]) exfill.erase(x);
			explace.insert(x);
		}
		else {
			if (exs[tmp]) refill.erase(x);
			repla.insert(x);
		}
		str[tmp][0] = 'a'; str[tmp][1] = '\0';
	}
	while (exfill.size() + refill.size()) {
			while (explace.size() && refill.size()) {
				printf("move %d %d\n", *refill.begin(), *explace.begin());
				repla.insert(*refill.begin());
				refill.erase(refill.begin());
				explace.erase(explace.begin());
			}
			while (repla.size() && exfill.size()) {
				printf("move %d %d\n", *exfill.begin(), *repla.begin());
				explace.insert(*exfill.begin());
				exfill.erase(exfill.begin());
				repla.erase(repla.begin());
			}
		}
		for (int i = 0; i < n; ++i) {
			int ret = stoi(str[i]);
			if (ret == -1 || ret > n) {
				if (exs[i]) {
					printf("move %s %d\n", str[i], *explace.begin());
					explace.erase(explace.begin());
				}
				else {
					printf("move %s %d\n", str[i], *repla.begin());
					repla.erase(repla.begin());
				}
			}
		}
		return 0;
}