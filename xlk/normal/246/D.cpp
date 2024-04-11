#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
set<int>s[100020];
int c[100020];
int z[100020];
int v[100020];
int n,m,x,y;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",c+i),v[c[i]]=1;
	for(int j=0;j<m;j++)
	{
		scanf("%d %d",&x,&y);
		if(c[x]==c[y])
			continue;
		if(!s[c[x]].count(c[y]))
		{
			s[c[x]].insert(c[y]);
			z[c[x]]++;
		}
		if(!s[c[y]].count(c[x]))
		{
			s[c[y]].insert(c[x]);
			z[c[y]]++;
		}
	}
	int zz=-1;
	for(int i=0;i<100010;i++)
		if(v[i])
			if(zz==-1||z[i]>z[zz])
				zz=i;
	printf("%d",zz);
	return 0;
}