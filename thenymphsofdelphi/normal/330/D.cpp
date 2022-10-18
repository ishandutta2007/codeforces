#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
char board[N + 1][N + 1];
int level[N + 1][N + 1];
bool ck[N + 1][N + 1];
int n, m, ans = 0, ex, ey, sx, sy;
string inp;

bool valid_square(int x, int y){
	if (x < 1 || x > N || y < 1 || y > N){
		return false;
	}
	if (board[x][y] >= '0' && board[x][y] <= '9'){
		return true;
	}
	if (board[x][y] == 'S' || board[x][y] == 'E'){
		return true;
	}
	if (board[x][y] == 'T'){
	    return false;
	}
	return false;
}

void bfs(int x, int y){
	queue < pair <int, int> > q;
	q.push(make_pair(x, y));
	pair <int, int> temp;
	level[x][y] = 0;
	ck[x][y] = true;
	while (!q.empty()){
		temp = q.front();
		q.pop();
		if (valid_square(temp.first - 1, temp.second) == true && ck[temp.first - 1][temp.second] == false){
			level[temp.first - 1][temp.second] = level[temp.first][temp.second] + 1;
			q.push(make_pair(temp.first - 1, temp.second));
			ck[temp.first - 1][temp.second] = true;
		}
		if (valid_square(temp.first, temp.second - 1) == true && ck[temp.first][temp.second - 1] == false){
			level[temp.first][temp.second - 1] = level[temp.first][temp.second] + 1;
			q.push(make_pair(temp.first, temp.second - 1));
			ck[temp.first][temp.second - 1] = true;
		}
		if (valid_square(temp.first, temp.second + 1) == true && ck[temp.first][temp.second + 1] == false){
			level[temp.first][temp.second + 1] = level[temp.first][temp.second] + 1;
			q.push(make_pair(temp.first, temp.second + 1));
			ck[temp.first][temp.second + 1] = true;
		}
		if (valid_square(temp.first + 1, temp.second) == true && ck[temp.first + 1][temp.second] == false){
			level[temp.first + 1][temp.second] = level[temp.first][temp.second] + 1;
			q.push(make_pair(temp.first + 1, temp.second));
			ck[temp.first + 1][temp.second] = true;
		}
	}
}

int main(){
	memset(ck, 0, sizeof(ck));
	memset(level, -1, sizeof(level));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
	    cin >> inp;
		for (int j = 1; j <= m; j++){
		    board[i][j] = inp[j - 1];
			if (board[i][j] == 'E'){
				ex = i;
				ey = j;
			}
			else if (board[i][j] == 'S'){
				sx = i;
				sy = j;
			}
			//printf("%c", board[i][j]);
		}
		//printf("\n");
	}
	bfs(ex, ey);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (board[i][j] >= '0' && board[i][j] <= '9'){
				if (level[i][j] <= level[sx][sy] && level[i][j] != -1){
					ans += (board[i][j] - '0');
				}
			}
			//printf("%d ", level[i][j]);
		}
		//printf("\n");
	}
	printf("%d", ans);
}