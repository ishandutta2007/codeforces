#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N  = 2000001;

char s[N];
int n , k , array[2000001];

int leftpoint[27] , rightpoint[27] , vis[27];

int chg(char x) {
	return x - 'A' + 1;
}

int main() {
	scanf("%d%d",&n,&k);
	scanf("%s",s + 1);
	memset(leftpoint , 127 ,sizeof(leftpoint));
	for(int i = 1;i <=n ;i ++) {
		int p = chg(s[i]);
		leftpoint[p] = min(leftpoint[p] , i);
		rightpoint[p]= max(rightpoint[p], i);
		vis[p] = 1;
	}
	for(int i = 1;i <= 26;i ++) {
		if(vis[i]) {
			array[leftpoint[i]] ++;
			array[rightpoint[i] + 1] --;
		}
	}
	for(int i = 1;i <= n;i ++) {
		array[i] +=array[i-1];
		if(array[i] >k) {
			puts("YES");return 0;
		}
	}
	puts("NO");
}