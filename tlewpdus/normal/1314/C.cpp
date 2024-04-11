#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;

int n, m;
ll k;
char str[1010];

int ran[1010];
ll D[1010][1010], S[1010][1010];
bool ok(int s, int e) {
	for (int i=0;i<n;i++) {
		for (int j=0;i+j<=n&&s+j<=e+1;j++) {
			if (i+j==n||s+j==e+1||str[i+j]!=str[s+j]) {
				if (s+j==e+1) ran[i] = i+j;
				else if (i+j==n) ran[i] = n+1;
				else if (str[i+j]>str[s+j]) ran[i] = i+j+1;
				else ran[i] = n+1;
				break;
			}
		}
	}
	D[0][n] = 1;
	for (int i=0;i<=n;i++) S[0][i] = 1;
	for (int j=1;j<=m;j++) {
		for (int i = n - 1; i >= 0; i--) {
			D[j][i] = S[j-1][ran[i]];
			S[j][i] = S[j][i+1]+D[j][i];
			if (D[j][i]>k) D[j][i] = k;
			if (S[j][i]>k) S[j][i] = k;
		}
	}
	return D[m][0] >= k;
}

int nxt[600100][26];
int loc[1010][1010];
int ord[600100];
vector<pii> sun;
int tp = 1, op;

void trav(int cur) {
	ord[cur] = op++;
	for (int i=0;i<26;i++) {
		if (~nxt[cur][i]) trav(nxt[cur][i]);
	}
}

void insert() {
	memset(nxt,-1,sizeof(nxt));
	for (int i=0;i<n;i++) {
		int cur = 0;
		for (int j=i;j<n;j++) {
			if (nxt[cur][str[j]-'a']<0) nxt[cur][str[j]-'a'] = tp++;
			cur = nxt[cur][str[j]-'a'];
			loc[i][j] = cur;
		}
	}
	trav(0);
	for (int i=0;i<n;i++) {
		for (int j=i;j<n;j++) {
			sun.push_back({i,j});
			loc[i][j] = ord[loc[i][j]];
		}
	}
	sort(sun.begin(),sun.end(),[](pii &A, pii &B) {
		return loc[A.first][A.second]<loc[B.first][B.second];
	});
}

int main() {
	scanf("%d%d%lld",&n,&m,&k);
	scanf("%s",str);
	insert();
	int s = 0, e = (int)sun.size()-1;
	while(s<=e) {
		int m = (s+e)/2;
		if (ok(sun[m].first,sun[m].second)) s = m+1;
		else e = m-1;
	}
	for (int i=sun[e].first;i<=sun[e].second;i++) printf("%c",str[i]);
	puts("");

	return 0;
}