#include <bits/stdc++.h>
using namespace std;

const int N = 258;

int cnt[N], t, l;
char s[N];

int main() {
	for(cin >> t; t --;) {
		scanf("%s", s + 1);
		l = strlen(s + 1);
		memset(cnt, 0, sizeof(cnt));
		for(int i = 1; i <= l; ++ i) cnt[s[i]] ++;
		vector <int> All;
		for(int i = 0; i < N; ++ i) {
			if(cnt[i] == 2) All.push_back(i);
		}
		for(int i = 0; i < (int) All.size(); ++ i) putchar((char)All[i]);
		for(int i = 0; i < (int) All.size(); ++ i) putchar((char)All[i]);
		for(int i = 0; i < N; ++ i) if(cnt[i] == 1) putchar((char)i);
		puts("");
	}
}