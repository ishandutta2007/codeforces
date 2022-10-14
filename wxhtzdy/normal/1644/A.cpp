#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
char s[N];

bool solve() {
	scanf("%s", s);
	int n = strlen(s);
	map<char, int> cnt;
	for (int i = 0; i < n; i++) {
		if(isupper(s[i])) {
			if(!cnt[s[i] + 'a' - 'A'])
				return false;
			cnt[s[i] + 'a' - 'A']--;
		}
		else
			cnt[s[i]]++;
	}
	return true;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--) puts(solve() ? "YES" : "NO");
	return 0;
}