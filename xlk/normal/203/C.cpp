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
int n,d,a,b,r[100020],x[100020],y[100020];
bool cmp(const int&p,const int&q)
{
	return a*x[p]+b*y[p]<a*x[q]+b*y[q];
}
int main()
{
	scanf("%d %d %d %d",&n,&d,&a,&b);
	for(int i=0;i<n;i++)
		scanf("%d %d",x+i,y+i),r[i]=i;
	sort(r,r+n,cmp);
	for(int i=0;i<n+1;i++)
		if(i!=n&&a*x[r[i]]+b*y[r[i]]<=d)
			d-=a*x[r[i]]+b*y[r[i]];
		else
		{
			printf("%d\n",i);
			for(int j=0;j<i;j++)
				printf("%d ",r[j]+1);
			break;
		}
	return 0;
}