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
char s[100100];
int i,j,n,st;
int main()
{
	while(~scanf("%s",s))
	{
		n=strlen(s);
		st=0;
		string ret="";
		for(i=25;i>=0;i--)
		{
			for(j=st;j<n;j++)
			{
				if(s[j]==i+'a')
				ret+=i+'a',st=j+1;
			}
		}
		cout<<ret<<endl;
	}
}