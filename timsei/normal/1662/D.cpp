#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

char s[N], t[N];
int tt;

vector < char > solve(char *s) {
	int l = strlen(s + 1);
	bool ok = 0;
	vector < char > ret;
	for(int i = 1; i <= l; ++ i) {
		if(s[i] == 'B') {
			ok ^= 1; continue;
		} else {
			ret.push_back(s[i]);
			if(ret.size() >= 2) {
				if(ret.back() == ret[ret.size() - 2]) {
					ret.pop_back(); ret.pop_back();
				}
			}
		}
	}
	if(ok)
	ret.push_back('B');
	return ret;
}

void rmain() {
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	vector < char > l = solve(s), r = solve(t);
	if(l == r) {
		puts("YES");
	}  else puts("NO");
}

int main() {
	for(cin >> tt; tt --;) {
		rmain();
	}
}