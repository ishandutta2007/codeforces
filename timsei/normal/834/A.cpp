#include<bits/stdc++.h>
using namespace std;

char s[101] , dir1 , dir2 ;
int n , T1 , T2;
int nxt[2000];

void init() {
	nxt[118] = 60; nxt[60] = 94; nxt[94] = 62; nxt[62] = 118;
}

int chg(char x) {
	return (int)x;
}

int main() {
	init();
	dir1 = getchar();
	getchar();
	dir2 = getchar();
	T1 = chg(dir1);
	T2 = chg(dir2);
	scanf("%d",&n);
	n %= 4;
	int now = T1;
	for(int i = 1;i <= n;i ++) now = nxt[now];
	bool flag1 = 0, flag2 = 0;
	if(now == T2) {
		flag1 =1;
	}
	now = T2;
	for(int i = 1;i <= n ;i ++) now = nxt[now];
	if(now == T1) {
		flag2=1;
	}
	if(flag1&&flag2||(!flag1 && !flag2))
	puts("undefined");
	else if(flag1 && !flag2) {
		puts("cw");
	}
	else puts("ccw");
	return 0;
}