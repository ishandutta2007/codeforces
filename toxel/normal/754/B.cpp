#include<bits/stdc++.h>

const int N = 10;

char s[N][N];

bool check(int x, int y){
	if (s[x][y] == 'x' && s[x][y + 1] == 'x' && s[x][y + 2] == 'x'){
		return true;
	}
	if (s[x][y] == 'x' && s[x + 1][y] == 'x' && s[x + 2][y] == 'x'){
		return true;
	}
	if (s[x][y] == 'x' && s[x + 1][y + 1] == 'x' && s[x + 2][y + 2] == 'x'){
		return true;
	}
	if (s[x][y] == 'x' && s[x + 1][y - 1] == 'x' && s[x + 2][y - 2] == 'x'){
		return true;
	}
	return false;
}

int main(){
	for (int i = 0; i < 4; ++ i){
		scanf("%s", s[i]);
	}
	for (int i = 0; i < 4; ++ i){
		for (int j = 0; j < 4; ++ j){
			if (s[i][j] == '.'){
				s[i][j] = 'x';
				for (int ii = 0; ii < 4; ++ ii){
					for (int jj = 0; jj < 4; ++ jj){
						if (check(ii, jj)){
							return printf("YES\n"), 0;
						}
					}
				}
				s[i][j] = '.';
			}
		}
	}
	return printf("NO\n"), 0;
}