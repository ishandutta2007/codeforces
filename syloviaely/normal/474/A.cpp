#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
char a[20]="qwertyuiop",b[20]="asdfghjkl;",c[20]="zxcvbnm,./";
char s[200];
char change(int k1,char k2){
	for (int i=0;i<10;i++) if (a[i]==k2) return a[i+k1];
	for (int i=0;i<10;i++) if (b[i]==k2) return b[i+k1];
	for (int i=0;i<10;i++) if (c[i]==k2) return c[i+k1];
}
int main(){
	char k1=getchar(); int pos=0;
	if (k1=='L') pos=1; else pos=-1;
	scanf("%s",s+1); int len=strlen(s+1);
	for (int i=1;i<=len;i++)
		s[i]=change(pos,s[i]);
	for (int i=1;i<=len;i++) putchar(s[i]); cout<<endl;
	return 0;
}