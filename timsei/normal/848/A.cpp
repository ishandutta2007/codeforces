#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

#define int long long

const int  N = 2000005;

int k , n , m , its[N] , tot = 0;
int xx[26];
char ans[N * 30];

main() {
	scanf("%d",&k);
	if(k == 0) {
		puts("abcdefghijklmn");
		return 0;
	}
	for(int i = 1;i <= k * 2;i ++) {
		its[i] = (i - 1) * i / 2;
	} 
	
	int cnt = 0;
	
	for(int i = k * 2;i >= 1;i --) {
		while(its[i] <= k) {
			k -= its[i];
			xx[cnt ++] = i;
		}
		if(!k) break;
	}
	for(int i = 0;i <cnt;i ++) {
		for(int j = 1;j <= xx[i];j ++) {
			putchar(i + 'a');
		}
	}
}