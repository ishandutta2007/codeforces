#include <bits/stdc++.h>
#define N 510
using namespace std;

char a[N][N];
int n;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%s", a[i] + 1);
	}
	
	int ans = 0;
	for (int i = 2; i < n; i++){
		for (int j = 2; j < n; j++){
			if (a[i][j] == 'X' && a[i - 1][j - 1] == 'X' && a[i - 1][j + 1] == 'X'
				&& a[i + 1][j - 1] == 'X' && a[i + 1][j + 1] == 'X'){
				ans ++;	
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}