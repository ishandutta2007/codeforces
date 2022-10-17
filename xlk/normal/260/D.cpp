#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int n,x,y,w,c[100020];
vector<int>b[2];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>w>>c[i];
		b[w].push_back(i);
	}
	for(;x<b[0].size()&&y<b[1].size();)
	{
		if(c[b[0][x]]<c[b[1][y]])
		{
			printf("%d %d %d\n",b[0][x],b[1][y],c[b[0][x]]);
			c[b[1][y]]-=c[b[0][x]];
			x++;
		}
		else
		{
			printf("%d %d %d\n",b[0][x],b[1][y],c[b[1][y]]);
			c[b[0][x]]-=c[b[1][y]];
			y++;
		}
	}
	for(;x+y<n-1;)
	{
		if(x<b[0].size())
			printf("%d %d 0\n",b[0][++x],b[1][0]);
		else
			printf("%d %d 0\n",b[0][0],b[1][++y]);
	}
	return 0;
}