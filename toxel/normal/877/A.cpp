#include<bits/stdc++.h>

const int N = 110;

char s[N], fr[N][N] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
int len[] = {5, 4, 5, 3, 6};

int main(){
	scanf("%s", s);
	int len = strlen(s), cnt = 0;
	for (int i = 0; i < len; ++ i){
		for (int j = 0; j < 5; ++ j){
			bool flag = true;
			for (int k = 0; k < ::len[j]; ++ k){
				if (s[i + k] != fr[j][k]){
					flag = false;
					break;
				}
			}
			cnt += flag;
		}
	}
	return printf(cnt == 1 ? "YES\n" : "NO\n"), 0;
}