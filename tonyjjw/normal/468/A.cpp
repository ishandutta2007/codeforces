//*

#include<stdio.h>
#pragma warning(disable:4996)

int N;

void dfs(int N){
	if(N==4){
		puts("4 * 3 = 12");
		puts("12 * 2 = 24");
		puts("24 * 1 = 24");
		return;
	}
	if(N==5){
		puts("1 + 5 = 6");
		puts("6 - 2 = 4");
		puts("4 + 4 = 8");
		puts("8 * 3 = 24");
		return;
	}
	printf("%d - %d = 1\n",N,N-1);
	printf("1 * 1 = 1\n");
	dfs(N-2);
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d",&N);
	if(N<=3){
		puts("NO");
		return 0;
	}
	puts("YES");
	dfs(N);
	return 0;
}

//*/