/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=1000100;
const int oo=1000000000;
char s[V],fh[V];
int va[V];
int i,n,ct;
int main()
{
	while(~scanf("%s",s))
	{
		n=strlen(s);
		for(i=n;i>0;i--)s[i]=s[i-1];s[0]='0';
		ct=0;
		for(i=n;i>=0;)
		{
			if(s[i]=='1')
			{
				if(i>0&&s[i-1]=='1')
				{
					fh[ct]='-';
					va[ct++]=n-i;
					while(s[i]=='1')i--;
					s[i]='1';
				}
				else
				{
					fh[ct]='+';
					va[ct++]=n-i;
					i--;
				}
			}
			else i--;
		}
		printf("%d\n",ct);
		for(i=0;i<ct;i++)
		printf("%c2^%d\n",fh[i],va[i]);
	}
}