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
const int V=2100;
const int P=1000000007;
char map[V][V];
int ret[V],n,m,K;
int main()
{
	while(~scanf("%d%d%d",&n,&m,&K))
	{
		for(int i=0;i<n;i++)
		scanf("%s",map[i]);
		memset(ret,0,sizeof(ret));
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		if(map[i][j]=='U')
		{
			if(i%2==0)ret[j]++;
		}
		else if(map[i][j]=='R')
		{
			ret[i+j]++;
		}
		else if(map[i][j]=='L')
		{
		    if(j-i>=0)
			ret[j-i]++;
		}
		for(int i=0;i<m;i++)printf("%d ",ret[i]);puts("");
	}
}