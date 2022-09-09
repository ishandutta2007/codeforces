#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;

int n, k;
int mat[100][100];
pii minl[100][100][5];

int sel[5];
int chk[100];
int dab = INF;
void Do() {
	int ans = 0;
	for (int i=0;i<k/2;i++) chk[sel[i]] = 1;
	for (int i=0;i<k/2;i++) {
		int c = sel[i], p = sel[(i+1)%(k/2)];
		for (int j=0;j<5;j++) {
			if (minl[c][p][j].second<0) break;
			if (!chk[minl[c][p][j].second]) {
				ans += minl[c][p][j].first;
				break;
			}
		}
	}
	for (int i=0;i<k/2;i++) chk[sel[i]] = 0;
	dab = min(dab,ans);
}
void bt(int idx) {
	if (idx==k/2) {
		Do();
		return;
	}
	for (int i=0;i<n;i++) {
		sel[idx] = i;
		bt(idx+1);
	}
}

int main() {
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) scanf("%d",&mat[i][j]);
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			vector<pii> vec;
			for (int k=1;k<n;k++) {
				if (k==i||k==j) continue;
				vec.push_back({mat[i][k]+mat[k][j],k});
			}
			sort(vec.begin(),vec.end());
			for (int l=0;l<vec.size()&&l<5;l++) minl[i][j][l] = vec[l];
			for (int l=vec.size();l<5;l++) minl[i][j][l] = pii(-1,-1);
		}
	}
	bt(1);
	printf("%d\n",dab);

	return 0;
}