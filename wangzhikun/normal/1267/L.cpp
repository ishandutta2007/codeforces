/*
 * Author       : YangDavid
 * Created Time : 20191201  152134
 */

#include<bits/stdc++.h>
#define rep(i, n) for(int i = 1; i <= n; ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 2333;
string s[maxn], TT;
int n, k, l, cnt[maxn];

int ptr = 0, ptr2 = 25;
char small() {
	while(cnt[ptr] == 0) ptr++;
	cnt[ptr]--;
	return 'a' + ptr;
}
char big() {
	while(cnt[ptr2] == 0) ptr2--;
	cnt[ptr2]--;
	return 'a' + ptr2;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> l >> k >> TT;
	for(auto ch : TT) {
		cnt[ch - 'a']++;
	}
	int common = k;
	for(int i = 0; i < l; ++i) {
		for(int j = k-common+1; j <= k; ++j)
			s[j] += small();
		int ncommon = k;
		for(int j = k-1; j > k-common; --j) if(s[j].back()==s[k].back())
			ncommon = j;
		for(int j = n; j > k; --j)
			s[j] += big();
		for(int j = k-common; j > 0; --j)
			s[j] += big();
		common = k - ncommon + 1;
	}
	for(int i = 1; i <= n; ++i)
		cout << s[i] << '\n';

    return 0;
}