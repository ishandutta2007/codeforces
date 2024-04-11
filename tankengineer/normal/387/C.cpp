#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;
int n;
char s[N];

int main() {
	scanf("%s", s);
	n = strlen(s);	
	vector<pair<int, int> > b;
	for (int i = 0; i < n; ++i) {
		int j = i + 1;
		while (j < n && s[j] == '0') {
			++j;
		}
		b.push_back(make_pair(s[i] - '0', j - i));
		i = j - 1;
	}
	int ans = 1;
	int head = b.begin()->first, len = b.begin()->second;
	for (int i = 1; i < (int)b.size(); ++i) {
		if (len < b[i].second || len == b[i].second && head < b[i].first) {
			ans = 1;
		} else {
			++ans;
		}
		len += b[i].second;
	}
	printf("%d\n", ans);
	return 0;
}