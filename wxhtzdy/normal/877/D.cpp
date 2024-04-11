#include <bits/stdc++.h>
#define ff(i,a,b) for(int (i) = (a); i <= (b); ++(i))
#define pii pair<int,int>
#define xx first
#define yy second
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n,m,k;
string s[1005];
int dist[1005][1005];
queue<pii> q;
bool bio[2][1005][1005];

bool valid(int i, int j){
	return i >= 0 && i < n && j >=0 && j < m && s[i][j] != '#';
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> k;
	ff(i,0,n-1)cin >> s[i];

	int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
	--x1;--y1;--x2;--y2;
	q.push({x1,y1});

	ff(i,0,n-1){
		ff(j,0,m-1){
			dist[i][j]=1e9;
			bio[0][i][j] = 0;
			bio[1][i][j] = 0;
		}
	}

	dist[x1][y1] = 0;
	bio[0][x1][y1] = 1;
	bio[1][x1][y1] = 1;
	while(!q.empty()){
		pii x = q.front();
		int i = x.xx, j = x.yy;
//		cout << i << " " << j << endl;
		q.pop();
		ff(dir,0,3){
			ff(len,1,k){
				int ni = i + dx[dir] * len;
				int nj = j + dy[dir] * len;
				if(!valid(ni, nj) || bio[dir&1][ni][nj])break;
				bio[dir&1][ni][nj] = 1;
				if(dist[ni][nj] > dist[i][j] + 1){
					dist[ni][nj] = dist[i][j] + 1;
					q.push({ni, nj});
				}
			}
		}
	}

	if(dist[x2][y2]==1e9)cout << -1;
	else cout << dist[x2][y2];

	return 0;
}