#include<climits>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 105;
int n, m, s[N];

int f[1 << 20], cnt[1 << 20], l[1 << 20];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", s + i);
	}
	scanf("%d", &m);
	vector<pair<char, int> > op;
	for (int i = 0; i < m; ++i) {
		char ch[2];
		int t;
		scanf("%s%d", ch, &t);
		op.push_back(make_pair(ch[0], t));
	}
	sort(s, s + n);
	reverse(s, s + n);
	cnt[0] = 0;
	for (int st = 0; st < (1 << m); ++st) {
		cnt[st] = cnt[st >> 1] + (st & 1);
	}
	for (int i = 0; i < m; ++i) {
		l[1 << i] = i;
	}
	f[(1 << m) - 1] = 0;
	for (int st = (1 << m) - 2; st >= 0; --st) {
		int c = cnt[st];
		char ch = op[c].first;
		int team = op[c].second;
		f[st] = team == 1 ? INT_MIN : INT_MAX;
		if (ch == 'p') {
			int cp = ~st & ((1 << m) - 1);	
			while (cp) {
				int lb = cp & -cp;
				cp -= lb;
				int ll = l[lb];
				f[st] = team == 1 ? max(f[st], f[st ^ lb] + s[ll]) : min(f[st], f[st ^ lb] - s[ll]);
			}
		} else {
			int cp = ~st & ((1 << m) - 1);	
			while (cp) {
				int lb = cp & -cp;
				cp -= lb;
				int ll = l[lb];
				f[st] = team == 1 ? max(f[st], f[st ^ lb]) : min(f[st], f[st ^ lb]);
			}
		}
	}
	printf("%d\n", f[0]);
	return 0;
}