#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

const int INF = 1000000666;
int n, m, a_left, a_right;
PII start;
bool blocked[2005][2005], visited[2005][2005];
int val[2005][2005];

PII xy(int a){
	return MP(a>>13, a%(1<<13));
}

int id(int x, int y){
	return (x<<13) + y;
}

void dijkstra(){
	std::priority_queue<PII, std::vector<PII>, std::greater<PII>> queue;
	queue.push(MP(0, id(start.X, start.Y)));
	FOR(i, n) FOR(j, m) val[i][j] = INF;
	val[start.X][start.Y] = 0;
	while(!queue.empty()){
		auto cur = queue.top();
		queue.pop();
		int x = xy(cur.Y).X;
		int y = xy(cur.Y).Y;
		if(x-1 >= 0 && !blocked[x-1][y]){
			if(val[x-1][y] > val[x][y]){
				val[x-1][y] = val[x][y];
				queue.push(MP(val[x-1][y], id(x-1, y)));
			}
		}
		if(x+1 < n && !blocked[x+1][y]){
			if(val[x+1][y] > val[x][y]){
				val[x+1][y] = val[x][y];
				queue.push(MP(val[x+1][y], id(x+1, y)));
			}
		}
		if(y-1 >= 0 && !blocked[x][y-1]){
			if(val[x][y-1] > val[x][y]+1){
				val[x][y-1] = val[x][y]+1;
				queue.push(MP(val[x][y-1], id(x, y-1)));
			}
		}
		if(y+1 < m && !blocked[x][y+1]){
			if(val[x][y+1] > val[x][y]+1){
				val[x][y+1] = val[x][y]+1;
				queue.push(MP(val[x][y+1], id(x, y+1)));
			}
		}
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m >> start.X >> start.Y >> a_left >> a_right;
	start.X--;
	start.Y--;
	FOR(i, n) FOR(j, m){
		char ch;
		std::cin >> ch;
		if(ch == '*') blocked[i][j] = true; 
	}
	dijkstra();
	int ans = 0;
	// FOR(i, n){
	// 	FOR(j, m){
	// 		std::cout << val[i][j] << " ";
	// 	}
	// 	std::cout << "\n";
	// }
	// std::cout << "\n\n";
	FOR(i, n) FOR(j, m){
		if(!blocked[i][j] && val[i][j] < INF){
			int roz = start.Y - j;
			int right = (val[i][j]-roz)/2;
			int left = val[i][j] - right;
			if(left <= a_left && right <= a_right){
				ans++;
				// std::cout << "Good " << i+1 << " " << j+1 << "\n";
			}
		}
	}
	std::cout << ans << "\n";
	return 0;
}