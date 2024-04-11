#include<bits/stdc++.h>

const int N = 2000010;

char s[N], *pt[N];
int n;

int main(){
	scanf("%d", &n);
	scanf("%s", s);
	pt[0] = s;
	for (int i = 1; i < n; ++ i){
		pt[i] = pt[i - 1] + strlen(pt[i - 1]) + 1;
		scanf("%s", pt[i]);
	}
	for (int i = n - 2; i >= 0; -- i){
		int len1 = strlen(pt[i]), len2 = strlen(pt[i + 1]);
		for (int j = 0; j < len1; ++ j){
			if (pt[i][j] > pt[i + 1][j]){
				pt[i][j] = '\0';
				break;
			}
			else if (pt[i][j] < pt[i + 1][j]){
				break;
			}
		}
	}
	for (int i = 0; i < n; ++ i){
		printf("%s\n", pt[i]);
	}
	return 0;
}