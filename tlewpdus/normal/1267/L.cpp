#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n, l, k;
char In[1000010];
int cnt[30];
char ans[1010][1010];

void Do(int x, int idx) {
	if(idx > l) return;
	int t = k - x + 1;
	int f = -1;
	for(int a=0;a<26;a++) if(cnt[a]) { f = a; break; }
	if(cnt[f] >= t) {
		for(int i=x;i<=k;i++) {
			ans[i][idx] = 'a' + f;
			cnt[f]--;
		}
		Do(x, idx + 1);
	}
	else {
		int nx = x + cnt[f];
		for(int i=x;i<nx;i++) {
			ans[i][idx] = 'a' + f;
			cnt[f]--;
		}
		Do(nx, idx);
	}
}

int main() {
	scanf("%d%d%d", &n, &l, &k);
	scanf("%s", In+1);
	for(int i=1;i<=n*l;i++) cnt[In[i] - 'a']++;
	Do(1, 1);
	int c = 0;
	for(int i=1;i<=n;i++) for(int j=1;j<=l;j++) if(ans[i][j] == 0) {
		while(cnt[c] == 0) ++c;
		ans[i][j] = 'a' + c;
		--cnt[c];
	}
	for(int i=1;i<=n;i++) printf("%s\n", ans[i] + 1);
	return 0;
}