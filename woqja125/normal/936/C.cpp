#include<cstdio>
#include<vector>
using namespace std;
char in[2010];
char dst[2010];
char tmp[2010];
int cnt[30];
int n;
int f, r;
vector<int> ans;
void chg(int &l, int x) {
	if (l < n - x) l += x;
	else l = n - l - 1;
}
void op(int x) {
	//if (x == 0) return;
	ans.push_back(x);
	for (int i = 0; i < x; i++) {
		tmp[i] = in[n - 1 - i];
	}
	for (int i = x; i < n; i++) {
		tmp[i] = in[i-x];
	}
	for (int i = 0; i < n; i++) in[i] = tmp[i];
	chg(f, x); chg(r, x);
}

int main() {
	scanf("%d%s%s", &n, in, dst);
	for(int i=0; i<n; i++){
		cnt[in[i] - 'a']++;
		cnt[dst[i] - 'a']--;
	}
	for (int i = 0; i < 26; i++) if (cnt[i] != 0) {
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (in[i] == dst[0]) {
			f = r = i;
			break;
		}
	}
	for (int i = 1; i < n; i++) {
		int j;
		for (j = 0; j < n; j++) {
			if (j >= f && j <= r) continue;
			if (in[j] == dst[i]) break;
		}
		if (j < f) {
			op(n - j - 1);
			op(1);
			op(n - r);
		}
		else if (j > r) {
			op(n - j - 1);
			op(n - f);
			op(n - r);
		}
		r++;
	}
	printf("%d\n", (int)ans.size());
	for (auto x : ans) printf("%d ", x);
	printf("\n");
	return 0;
}