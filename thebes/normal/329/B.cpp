#include <bits/stdc++.h>
#define gl(x) getline(cin,x)
#define gc(x) cin.get(x)
#define sz(x) (int)(x.size())
#define al(x) (x).begin(), (x).end()
#define ms(a, b) memset(a,b,sizeof(a))
#define sp ' '
#define nl '\n'
#define fi first
#define se second
#define lsb(x) ((x)&(-x))
using namespace std;
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t, A...a){cout<<t,pr(a...);}
typedef long long ll;
typedef pair<int, int> pi;

int dr[] = {-1, 0, 0, 1}, dc[] = {0, -1, 1, 0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int r, c; sc(r, c);
	char a[r][c];
	int sr = -1, sc = -1, pr = -1, pc = -1;
	for(int i = 0; i < r; i++) {
		gc();
		for(int j = 0; j < c; j++) {
			gc(a[i][j]);
			if(a[i][j] == 'E') sr = i, sc = j;
			else if(a[i][j] == 'S') pr = i, pc = j;
		}
	}
	int dist[r][c]; ms(dist, 0x3f);
	dist[sr][sc] = 0;
	queue<pi> q;
	q.emplace(sr, sc);
	while(!q.empty()) {
		int rr, cc; tie(rr, cc) = q.front();
		q.pop();
		for(int i = 0; i < 4; i++) {
			int nr = rr + dr[i], nc = cc + dc[i];
			if(nr >= 0 && nc >= 0 && nr < r && nc < c && a[nr][nc] != 'T' && dist[nr][nc] == 0x3f3f3f3f) {
				dist[nr][nc] = dist[rr][cc] + 1;
				q.emplace(nr, nc);
			}
		}
	}
	int need = dist[pr][pc], ans = 0;
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(a[i][j] >= '0' && a[i][j] <= '9' && dist[i][j] <= need) {
				ans += a[i][j] - '0';
			}
		}
	}
	cout << ans << endl;
}