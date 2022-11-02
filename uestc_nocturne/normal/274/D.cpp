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
const int V=100100;
int n,m;
struct Node
{
	int va,id;
}q[V];
bool cmp(Node x,Node y)
{return x.va<y.va;}
int ct[V],ret[V],pos[V],re[V];
int a[V];
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		bool can=true;
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			scanf("%d",&q[i*m+j].va);
			a[i*m+j]=q[i*m+j].va;
			q[i*m+j].id=j;
		}
		for(int i=0;i<n;i++)
		sort(q+i*m,q+i*m+m,cmp);
		memset(ct,0,sizeof(ct));
		memset(re,0,sizeof(re));
		memset(pos,0,sizeof(pos));
		for(int i=0;i<n;i++)
		while(pos[i]<m&&q[i*m+pos[i]].va==-1)
		{
			ct[q[i*m+pos[i]].id]++;pos[i]++;
		}
		for(int i=0;i<n;i++)
		{
			int tmp=q[i*m+pos[i]].va;
			while(pos[i]<m&&q[i*m+pos[i]].va==tmp)
			{
				ct[q[i*m+pos[i]].id]++;
				pos[i]++,re[i]++;
			}
		}
		int cnt=0;
		for(int i=0;i<m;i++)
		if(ct[i]==n)ret[cnt++]=i;
		for(int j=0;j<cnt;j++)
		{
			int now=ret[j];
			for(int i=0;i<n;i++)
			{
				if(a[i*m+now]!=-1)
				re[i]--;
				if(re[i]==0)
				{
					int tmp=q[i*m+pos[i]].va;
					while(pos[i]<m&&q[i*m+pos[i]].va==tmp)
					{
						ct[q[i*m+pos[i]].id]++;
						if(ct[q[i*m+pos[i]].id]==n)
						{
							ret[cnt++]=q[i*m+pos[i]].id;
						}
						pos[i]++,re[i]++;
					}
				}
			}
		}
		if(cnt!=m)cout<<-1<<endl;
		else
		{
			for(int i=0;i<m;i++)
			{
				if(i)printf(" ");
				printf("%d",ret[i]+1);
			}puts("");
		}
	}
}