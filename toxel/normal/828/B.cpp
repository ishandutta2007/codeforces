#include<bits/stdc++.h>

const int N = 110;

char s[N][N];
int n, m;

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++ i){
		scanf("%s", s[i]);
	}
	int cnt = 0;
	int minx = INT_MAX, miny = INT_MAX, maxx = 0, maxy = 0;
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < m; ++ j){
			if (s[i][j] == 'B'){
				minx = std::min(minx, i);
				miny = std::min(miny, j);
				maxx = std::max(maxx, i);
				maxy = std::max(maxy, j);
				++ cnt;
			}
		}
	}
	int x = std::max(std::max(maxx - minx + 1, maxy - miny + 1), 1);
	return printf("%d\n", x > n || x > m ? -1 : x * x - cnt), 0;
}