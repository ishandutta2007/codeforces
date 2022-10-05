#include<bits/stdc++.h>

const int N = 1010;

int a[N][N];
int two[N][N], five[N][N], dirtwo[N][N], dirfive[N][N];
char s[N << 1];

void move(int x1, int y1, int x2, int y2){
	for (int i = x1; i < x2; ++ i){
		putchar('D');
	}
	for (int i = y1; i < y2; ++ i){
		putchar('R');
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int zerox = -1, zeroy = -1;
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < n; ++ j){
			scanf("%d", &a[i][j]);
			if (!a[i][j]){
				zerox = i;
				zeroy = j;
			}
		}
	}
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < n; ++ j){
			int two = 0, five = 0;
			if (!a[i][j]){
				two = five = 1;
			}
			else{
				while (a[i][j] % 2 == 0){
					a[i][j] /= 2;
					++ two;
				}
				while (a[i][j] % 5 == 0){
					a[i][j] /= 5;
					++ five;
				}
			}
			if (!i && !j){
				::two[i][j] = two;
				::five[i][j] = five;
			}
			else if (!i){
				::two[i][j] = ::two[i][j - 1] + two;
				::five[i][j] = ::five[i][j - 1] + five;
				dirtwo[i][j] = 0;
				dirfive[i][j] = 0;
			}
			else if (!j){
				::two[i][j] = ::two[i - 1][j] + two;
				::five[i][j] = ::five[i - 1][j] + five;
				dirtwo[i][j] = 1;
				dirfive[i][j] = 1;
			}
			else{
				::two[i][j] = std::min(::two[i - 1][j], ::two[i][j - 1]) + two;
				::five[i][j] = std::min(::five[i - 1][j], ::five[i][j - 1]) + five;
				dirtwo[i][j] = ::two[i - 1][j] < ::two[i][j - 1] ? 1 : 0;
				dirfive[i][j] = ::five[i - 1][j] < ::five[i][j - 1] ? 1 : 0;
			}
		}
	}
	if (~zerox && two[n - 1][n - 1] && five[n - 1][n - 1]){
		printf("1\n");
		move(0, 0, zerox, zeroy);
		move(zerox, zeroy, n - 1, n - 1);
		putchar('\n');
		return 0;
	}
	if (two[n - 1][n - 1] < five[n - 1][n - 1]){
		printf("%d\n", two[n - 1][n - 1]);
		int nowx = n - 1, nowy = n - 1, cnt = 0;
		while (nowx || nowy){
			if (dirtwo[nowx][nowy]){
				s[cnt ++] = 'D';
				-- nowx;
			}
			else{
				s[cnt ++] = 'R';
				-- nowy;
			}
		}
	}
	else{
		printf("%d\n", five[n - 1][n - 1]);
		int nowx = n - 1, nowy = n - 1, cnt = 0;
		while (nowx || nowy){
			if (dirfive[nowx][nowy]){
				s[cnt ++] = 'D';
				-- nowx;
			}
			else{
				s[cnt ++] = 'R';
				-- nowy;
			}
		}
	}
	std::reverse(s, s + 2 * (n - 1));
	puts(s);
	return 0;
}