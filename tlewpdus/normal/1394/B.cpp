#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int n, m, k;
vector<pii> lis[200100];
vector<pii> ban[200100];

vector<pii> mak[10][10];
int mang[10][10];

int ans;
void bt(int i) {
	if (i==k+1) {
		ans++;
		return;
	}
	for (int j=1;j<=i;j++) {
		if (mang[i][j]) continue;
		for (pii &e : mak[i][j]) {
			mang[e.first][e.second]++;
		}
		bt(i+1);
		for (pii &e : mak[i][j]) {
			mang[e.first][e.second]--;
		}
	}
}

int main() {
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<m;i++) {
		int u, v, w;
		scanf("%d%d%d",&u,&v,&w); u--;v--;
		lis[u].push_back({w,v});
	}
	for (int i=0;i<n;i++) {
		sort(lis[i].begin(),lis[i].end());
		for (int j=0;j<lis[i].size();j++) {
			ban[lis[i][j].second].push_back({lis[i].size(),j+1});
		}
	}
	for (int i=0;i<n;i++) {
		sort(ban[i].begin(),ban[i].end());
		for (int j=0;j<ban[i].size();j++) {
			if (j && ban[i][j - 1] == ban[i][j]) {
				mang[ban[i][j].first][ban[i][j].second]++;
			}
		}
		ban[i].erase(unique(ban[i].begin(),ban[i].end()),ban[i].end());
		for (int j=0;j<ban[i].size();j++) {
			for (int k=j+1;k<ban[i].size();k++) {
				if (ban[i][j].first != ban[i][k].first) {
					mak[ban[i][j].first][ban[i][j].second].push_back(ban[i][k]);
				}
			}
		}
	}
	for (int i=1;i<=k;i++) {
		for (int j=1;j<=i;j++) {
			sort(mak[i][j].begin(),mak[i][j].end());
			mak[i][j].erase(unique(mak[i][j].begin(),mak[i][j].end()),mak[i][j].end());
//			printf("%d, %d\n",i,j);
//			for (pii &e : mak[i][j]) printf("  %d, %d",e.first,e.second);
//			puts("");
		}
	}
	bt(1);
	printf("%d\n",ans);

	return 0;
}