#include<bits/stdc++.h>

const int N = 8;

int solve[N], value[N] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX, -INT_MAX, -INT_MAX, -INT_MAX, -INT_MAX};
int n, x0, y0;
char s[N];

int main(){
	memset(solve, -1, sizeof(solve));
	scanf("%d%d%d", &n, &x0, &y0);
	for (int i = 0, x, y; i < n; ++ i){
		scanf("%s%d%d", s, &x, &y);
		int type;
		switch (s[0]){
			case 'B' : type = 0; break;
			case 'R' : type = 1; break;
			case 'Q' : type = 2; break;
		}
		if (x == x0){
			if (y > y0){
				if (y < value[0]){
					value[0] = y;
					solve[0] = type;
				}
			}
			else{
				if (y > value[4]){
					value[4] = y;
					solve[4] = type;
				}
			}
		}
		if (y == y0){
			if (x > x0){
				if (x < value[1]){
					value[1] = x;
					solve[1] = type;
				}
			}
			else{
				if (x > value[5]){
					value[5] = x;
					solve[5] = type;
				}
			}
		}
		if (x - y == x0 - y0){
			if (x > x0){
				if (x < value[2]){
					value[2] = x;
					solve[2] = type;
				}
			}
			else{
				if (x > value[6]){
					value[6] = x;
					solve[6] = type;
				}
			}
		}
		if (x + y == x0 + y0){
			if (x > x0){
				if (x < value[3]){
					value[3] = x;
					solve[3] = type;
				}
			}
			else{
				if (x > value[7]){
					value[7] = x;
					solve[7] = type;
				}
			}
		}
	}
	for (int i = 0; i <= 1; ++ i){
		for (int j = 0; j <= 1; ++ j){
			int x = (i << 2) + j;
			if (solve[x] == 1 || solve[x] == 2){
				return printf("YES\n"), 0;
			}
		}
		for (int j = 2; j <= 3; ++ j){
			int x = (i << 2) + j;
			if (solve[x] == 0 || solve[x] == 2){
				return printf("YES\n"), 0;
			}
		}
	}
	return printf("NO\n"), 0;
}