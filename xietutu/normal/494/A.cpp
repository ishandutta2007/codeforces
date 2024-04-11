#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
const int maxn = 100005;
char s[maxn];
bool bo;
int n,l,last,lastl,more,ans[maxn];
bool p[maxn];
std::stack<int> S;
int main() {
	scanf("%s",s + 1);
	n = strlen(s + 1);
	for (int i = n; i >= 1; --i)
		if (s[i] == '#') {
			last = i; break;
		}
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '(') ++l;
		else if (s[i] == ')') --l;
		else if (s[i] = '#') {
			ans[i] = 1;
			--l;
			if (i == last) lastl = l;
		}
		if (l < 0) bo = true;
	}
	more = l;
	if (lastl < more) bo = true;
	if (!bo && l > 0) {
		l = lastl - more;
		ans[last] += more;
		for (int i = last + 1; i <= n; ++i) {
			if (s[i] == '(') ++l;
			else if (s[i] == ')') --l;	
			if (l < 0) bo = true;
		}
	}
	if (bo) printf("-1\n");
	else {
		for (int i = 1; i <= n; ++i)
			if (s[i] == '#') printf("%d\n",ans[i]);
	}
}