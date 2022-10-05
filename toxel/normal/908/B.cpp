#include<bits/stdc++.h>

const int N = 120;

char s[N][N];
int a[N];
char dir[N];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++ i){
		scanf("%s", s[i]);
	}
	scanf("%s", dir);
	int x0, y0;
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < m; ++ j){
			if (s[i][j] == 'S'){
				x0 = i, y0 = j;
			}
		}
	}
	for (int i = 0; i < 4; ++ i){
		a[i] = i;
	}
	int cnt = 0;
	int len = strlen(dir);
	do{
		int nowx = x0, nowy = y0;
		bool flag = true;
		for (int i = 0; i < len; ++ i){
			int x = a[dir[i] - '0'];
			switch (x){
				case 0 : ++ nowx; break;
				case 1 : -- nowx; break;
				case 2 : ++ nowy; break;
				case 3 : -- nowy; break;
			}
			if (nowx < 0 || nowx >= n || nowy < 0 || nowy >= m || s[nowx][nowy] == '#'){
				flag = false;
				break;
			}
			if (s[nowx][nowy] == 'E'){
				break;
			}
		}
		cnt += flag && s[nowx][nowy] == 'E';
	}
	while (std::next_permutation(a, a + 4));
	printf("%d\n", cnt);
	return 0;
}