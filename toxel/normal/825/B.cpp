#include<bits/stdc++.h>

const int N = 20;

char s[N][N];

bool check(){
	for (int i = 0; i < 10; ++ i){
		for (int j = 0; j <= 5; ++ j){
			bool flag = true;
			for (int k = 0; k < 5; ++ k){
				if (s[i][j + k] != 'X'){
					flag = false;
				}
			}
			if (flag){
				return true;
			}
		}
	}
	for (int i = 0; i <= 5; ++ i){
		for (int j = 0; j < 10; ++ j){
			bool flag = true;
			for (int k = 0; k < 5; ++ k){
				if (s[i + k][j] != 'X'){
					flag = false;
				}
			}
			if (flag){
				return true;
			}
		}
	}
	for (int i = 0; i <= 5; ++ i){
		for (int j = 0; j <= 5; ++ j){
			bool flag = true;
			for (int k = 0; k < 5; ++ k){
				if (s[i + k][j + k] != 'X'){
					flag = false;
				}
			}
			if (flag){
				return true;
			}
		}
	}
	for (int i = 0; i <= 5; ++ i){
		for (int j = 4; j < 10; ++ j){
			bool flag = true;
			for (int k = 0; k < 5; ++ k){
				if (s[i + k][j - k] != 'X'){
					flag = false;
				}
			}
			if (flag){
				return true;
			}
		}
	}
	return false;
} 

int main(){
	for (int i = 0; i < 10; ++ i){
		scanf("%s", s[i]);
	}
	for (int i = 0; i < 10; ++ i){
		for (int j = 0; j < 10; ++ j){
			if (s[i][j] == '.'){
				s[i][j] = 'X';
				if (check()){
					return printf("YES\n"), 0;
				}
				s[i][j] = '.';
			}
		}
	}
	return printf("NO\n"), 0;
}