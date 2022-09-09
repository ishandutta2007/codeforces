#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define pli pair<long long,int>

#define Fi first
#define Se second
int save[220][220];

bool cmp(int x, int y) {
	if(save[x][y] != -1) return save[x][y];
	printf("? %d %d\n", x, y);
	fflush(stdout);
	char ch[4];
	scanf("%s", ch);
	return save[x][y] = (ch[0] == '<');
}

int main() {
	int T; scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		memset(save, -1, sizeof save);
		pii A[110];
		int n; scanf("%d", &n);
		for(int i=1;i<=n;i++) A[i] = pii(2*i-1, 2*i);
		for(int i=1;i<=n;i++) {
			if(!cmp(A[i].Fi, A[i].Se)) swap(A[i].Fi, A[i].Se);
		}
		sort(A+1, A+1+n, [&](pii a, pii b) {
			return cmp(a.Fi, b.Fi);
		});
		int chk[110] = {};
		int a = 1;
		for(int i=2;i<=n;i++) {
			vector <int> w;
			for(int j=1;j<=a;j++) if(chk[j] == 0) w.pb(A[j].Se);
			if(w.empty()) {
				++a; continue;
			}
			int v = *min_element(w.begin(), w.end(), cmp);
			if(cmp(A[a+1].Fi, v)) {
				++a;
			}
			else {
				for(int j=1;j<=a;j++) if(A[j].Se == v) chk[j] = 1;
			}
		}
		printf("!\n");
		fflush(stdout);
	}
}