#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;

int pre[N][N] , n , m , now , best[N];
bool isbest[N][N];
char s[N];

bool equal(int a , int b ,int c , int d) {
//	cerr << a <<" "<< b <<" "<< c <<" "<<d  <<" "<< isbest[a][b] <<" "<< isbest[c][d] << endl;
	if(isbest[a][b] ^ isbest[c][d]) return 0;
	return s[a + b + 1] == s[c + d + 1];
}

bool cmp(int a , int b ,int c ,int d) {
	if(isbest[a][b] && !isbest[c][d]) return 1;
	if(!isbest[a][b] && isbest[c][d]) return 0;
	return s[a + b + 1] < s[c + d + 1];
}

void print(int x , int y) {
	if(!x) return;
	int now = pre[x][y];
	print(x - 1 , now);
	putchar(s[x + now]);
}

main(void) {
	scanf("%s" , s + 1);
	n = strlen(s + 1);
	pre[0][0] = 0;
	int up = 0;
	while((1 << (up + 1)) - 1 < n) ++ up;
	-- up;
	for(int i = 0;i < (1 << (up + 1));++ i) isbest[0][i] = 1;
	for(int i = 1;i <= n - (1 << (up + 1)) + 1;++ i) {
		for(int j = 0;j < (1 << (up + 1));++ j) if(i + j <= n){
			pre[i][j] = j;
			for(int k = 0;k <= up;++ k) if((1 << k) & j) {
				if(cmp(i - 1 , pre[i][j ^ (1 << k)] , i - 1 , pre[i][j])) pre[i][j] = pre[i][j ^ (1 << k)];
			}
		}
		int Best = 0;
		for(int j = 0;j < (1 << (up + 1));++ j) {
			if(cmp(i - 1 , pre[i][j] , i - 1 , pre[i][Best])) Best = j;
		}
//		cerr << i <<" "<< Best << " "<< pre[i][Best] << endl;
		for(int j = 0;j <(1 << (up + 1));++ j) {
			if(equal(i - 1, pre[i][j] , i - 1 , Best)) isbest[i][j] = 1;
//			cerr << i <<" "<< j <<" "<< pre[i][j] <<" "<<isbest[i][j] << endl;
		}
	}
	print(n - (1 << (up + 1)) + 1 , (1 << (up + 1)) - 1);
}