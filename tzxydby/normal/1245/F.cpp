#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,l,r,f[35][2][2][2][2];
int dfs(int pos,bool f1,bool f2,bool f3,bool f4)
{
	if(pos==-1) 
		return 1;
	if(f[pos][f1][f2][f3][f4]!=-1) 
		return f[pos][f1][f2][f3][f4];
	int &t=f[pos][f1][f2][f3][f4];t=0;
	int d1=f1?l>>pos&1:0,d2=f2?r>>pos&1:1,d3=f3?l>>pos&1:0,d4=f4?r>>pos&1:1;
	for(int x=d1;x<=d2;x++)
		for(int y=d3;y<=d4;y++)
			if (!x||!y) t+=dfs(pos-1,f1&(x==d1),f2&(x==d2),f3&(y==d3),f4&(y==d4));
	return t;
}
int cal(int l,int r)
{
	int pos=0;
	for(int i=31;i;i--)
	{
		if(r>>i&1)
		{
			pos=i;
			break;
		}
	}	
	return dfs(pos,1,1,1,1);
}
signed main()
{
	scanf("%I64d",&T);
	for(;T--;)
	{
		memset(f,-1,sizeof(f));
		scanf("%I64d%I64d",&l,&r);
		printf("%I64d\n",cal(l,r));
	}
	return 0;
}