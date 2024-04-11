#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int T, n, w, h, l, r, k, Len[N], upt[N];
long long Num[N];
long long x;
char s[N];

int main() {
	for(cin >> T; T --;) {		
		scanf("%d%d%lld", &n, &k, &x);
		scanf("%s", s + 1);
		s[++ n] = 'a';
		for(int i = 1; i <= n; ++ i) Len[i] = upt[i] = 0;
		int cnt = 0;
		vector <int> All;
		for(int i = 1; i <= n; ++ i) {
			if(s[i] == '*') cnt += k;
			else {
				Len[i] = cnt + 1; cnt = 0;
				All.push_back(i);
			}
		}
		
		long long cur = 1, fuck = 0;
		for(int i = All.size() - 1; i >= 0; -- i) {
			if(cur >= (x - 1) / Len[All[i]] + 1) {
				fuck = i;  break;
			} else {
				if(i == All.size() - 1) Num[All[i]] = Len[All[i]];
				else Num[All[i]] = Num[All[i + 1]] * Len[All[i]];
				cur = cur * Len[All[i]];
			}
		}
		
		-- x;
		
		for(int i = fuck; i < All.size(); ++ i) {
			long long now = (i == All.size() - 1) ? 1 : Num[All[i + 1]];
			upt[All[i]] = x / now;
			x %= now;
		}
		for(int i = 0; i < (int) All.size(); ++ i) {
			for(int j = 0; j < upt[All[i]]; ++ j ) putchar('b');
			if(i != All.size() - 1) putchar('a');
		}
		puts("");
	}
}