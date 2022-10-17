#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=1005; 
int n;
char s[MAXN];
int main(){
	scanf("%s",s);
	n=strlen(s);
	for (int i=0;i<n;i++) putchar(s[i]);
	for (int i=n-1;~i;i--) putchar(s[i]);
	return 0;
}