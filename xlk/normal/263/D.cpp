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
vector<int>a[100020];
int n,m,k;
int r[100020];
int s[100020],ss;
int dfs(int x)
{
	s[++ss]=x;
	r[x]=ss;
	for(int i:a[x])
		if(!r[i])
		{
			dfs(i);
			break;
		}
}
int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1);
	int p=0x3f3f3f3f;
	for(int i:a[s[ss]])
		if(r[i]<p)
			p=r[i];
	printf("%d\n",ss-p+1);
	for(int i=p;i<=ss;i++)
		printf("%d ",s[i]);
	return 0;
}