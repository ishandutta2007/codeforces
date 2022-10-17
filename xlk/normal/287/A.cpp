#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
char s[5][5];
int n=4;
int C(int x,int y)
{
	return s[x][y]=='#';
}
int main()
{
	fr(i,n)
		scanf("%s",s[i]);
	fr(i,n-1)
		fr(j,n-1)
		{
			if(C(i,j)+C(i+1,j)+C(i,j+1)+C(i+1,j+1)!=2)
			{
				puts("YES");
				return 0;
			}
		}
	puts("NO");
}