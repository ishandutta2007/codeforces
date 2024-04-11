#include<bits/stdc++.h>

const int N = 1010;

char s[N][N];
int n;

void print(){
	printf("YES\n");
	for (int i = 0; i < n; ++ i){
		printf("%s\n", s[i]);
	}
	exit(0);
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%s", s[i]);
	}
	for (int i = 0; i < n; ++ i){
		if (s[i][0] == 'O' && s[i][1] == 'O'){
			s[i][0] = s[i][1] = '+';
			print();
		}
		if (s[i][3] == 'O' && s[i][4] == 'O'){
			s[i][3] = s[i][4] = '+';
			print();
		}
	}
	return printf("NO\n"), 0;
}