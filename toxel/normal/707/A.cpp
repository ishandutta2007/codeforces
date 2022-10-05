#include<bits/stdc++.h>

const int N = 110;

char s[N];
int n, m;

int main(){
	scanf("%d%d", &n, &m);
	bool flag = true;
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < m; ++ j){
			scanf("%s", s);
			if (s[0] == 'C' || s[0] == 'M' || s[0] == 'Y'){
				flag = false;
			}
		}
	}
	return printf(flag ? "#Black&White" : "#Color"), 0;
}