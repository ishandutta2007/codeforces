#include <bits/stdc++.h>
using namespace std;

#define a array

const int mxN=2e3;
int n, m, r, c, x, y, ans, nb[4][2]={{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
string g[mxN];
int d[mxN][mxN];
vector<a<int, 2>> tp[2];
bool vis[mxN][mxN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> r >> c >> x >> y, --r, --c;
	for(int i=0; i<n; ++i)
		cin >> g[i];
	memset(d, 1, sizeof(d));
	d[r][c]=0;
	tp[0].push_back({r, c});
	while(tp[0].size()) {
		for(int i=0; i<tp[0].size(); ++i) {
			a<int, 2> u=tp[0][i];
			if(vis[u[0]][u[1]])
				continue;
			vis[u[0]][u[1]]=1;
//			cout << u[0] << " " << u[1] << " " << d[u[0]][u[1]] << endl;
			if(d[u[0]][u[1]]>x||u[1]-c+d[u[0]][u[1]]>y)
				continue;
			++ans;
			for(int j=0; j<4; ++j) {
				int ni=u[0]+nb[j][0], nj=u[1]+nb[j][1], nd=d[u[0]][u[1]]+!j;
				if(ni>=0&&ni<n&&nj>=0&&nj<m&&g[ni][nj]=='.'&&nd<d[ni][nj]) {
					d[ni][nj]=nd;
					tp[!j].push_back({ni, nj});
				}
			}
		}
		tp[0]=tp[1];
		tp[1].clear();
	}
	cout << ans;
}