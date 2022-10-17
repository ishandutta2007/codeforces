#include<stdio.h>
#include<iostream>
using namespace std;
int xn,xm,yn,ym,n,m;
char s[60][60];
int main()
{
	scanf("%d %d",&n,&m);
	xn=n,yn=m;
	for(int i=0;i<n;i++)
		scanf("%s",s[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(s[i][j]=='*')
			{
				xn=min(xn,i),xm=max(xm,i);
				yn=min(yn,j),ym=max(ym,j);
			}
	for(int i=xn;i<=xm;i++,puts(""))
		for(int j=yn;j<=ym;j++)
			printf("%c",s[i][j]);
	return 0;
}