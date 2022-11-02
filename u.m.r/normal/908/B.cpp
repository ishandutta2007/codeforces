#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){

}

int dir[10];
char s[1000][1000];
char t[1001];

int sx, sy, ex, ey;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int gao(){
	int o = strlen(t);
	int x = sx, y = sy;
	for (int i = 0; i < o; i++){
		int d = dir[t[i] - '0'];
		x += dx[d];
		y += dy[d];
		if (!(x >= 1 && x <= n && y >= 1 && y <= m)) return 0;
		if (s[x][y] == '#') return 0;
		if (s[x][y] == 'E') return 1;
	}
	return 0;
}

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%s", s[i] + 1);
		for (int j = 1; j <= m; j++)
			if (s[i][j] == 'S'){
				sx = i, sy = j;
			}
			else if (s[i][j] == 'E'){
				ex = i, ey = j;
			}
	}
	scanf("%s", t);
	for (int i = 0; i < 4; i++)
		dir[i] = i;
	int ans = 0;
	do{
		ans += gao();
	}while(next_permutation(dir, dir + 4));
	printf("%d\n", ans);
}

void printans(){

}


int main(){
//	std::ios::sync_with_stdio(false);
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}