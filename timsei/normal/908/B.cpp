#include <bits/stdc++.h>
using namespace std;

const int  N = 505;

char s[N][N] , t[N];
int x , y , n , m  , ans , f[4];

int dx[] = {0 , 0 , 1 , -1};
int dy[] = {-1 , 1 , 0 , 0};

int main(void) {
	scanf("%d%d" , &n , &m);
	for(int i = 1;i <= n;++ i) scanf("%s" ,s[i] + 1);
	for(int i = 0;i < 4;++ i) f[i] = i;
	scanf("%s" , t + 1);
	int len = strlen(t + 1);
	for(int i = 1;i <= len;++ i) t[i] -= '0';
	int sx , sy , tx , ty;
	for(int i = 1;i <= n;++ i) {
		for(int j = 1;j <= m;++ j) {
			if(s[i][j] == 'S') {
				sx = i; sy = j;
			}
			if(s[i][j] == 'E') {
				tx = i; ty = j;
			}
		}
	}
	do {
		x = sx; y = sy;
		++ ans;
		for(int i = 1;i <= len;++ i) {
			x += dx[f[t[i]]]; y += dy[f[t[i]]];
			if(x > n || y > m || x <= 0 || y <= 0 || s[x][y] == '#') {
				break;
			}
			if(x == tx && y == ty) break;
		}
		if(x != tx || y != ty) ans --;
	}while(next_permutation(f , f + 4));
	cout << ans << endl;
}