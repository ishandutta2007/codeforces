#include <cstdio>
#include <string>
#include <algorithm>

const int N = 200005;
int t, p[N];
char buf[N];
bool u[N];
std::string s;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%s", buf);
		s = std::string(buf);
		int qm = 0, b = 0;
		for (int i = 0; s[i]; ++i) {
			u[i] = 0;
			if (s[i] == '?') ++qm;
			if (s[i] == '(') ++b;
			if (s[i] == ')') --b;
		}
		qm = std::max(-b, 0) + (qm - abs(b)) / 2;
		for (int i = 0; s[i]; ++i) {
			if (s[i] == '?') {
				u[i] = 1;
				if (qm) {
					--qm;
					s[i] = '(';
				} else s[i] = ')';
			}
			p[i + 1] = p[i] + (s[i] == '(' ? 1 : -1);
		}
		bool ok = 1;
		int cnt = 0;
		for (int i = 0, j = 0; i < s.size(); ++i) {
			while (j < s.size() && (j <= i || !u[j] || s[j] != ')')) {
				cnt += p[j + 1] < 2;
				++j;
			}
			if (u[i] && s[i] == '(' && j < s.size() && !cnt) ok = 0;
			cnt -= p[i + 1] < 2;
		}
		printf("%s\n", ok ? "YES" : "NO");
	}
	return 0;
}