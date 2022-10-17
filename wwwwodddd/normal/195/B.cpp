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
int a[100020];
int n,m,c,t;
bool cmp(const int&a,const int &b)
{
	int xa=abs(t-2*a);
	int xb=abs(t-2*b);
	if(xa!=xb)
		return xa<xb;
	return a<b;
}
int main()
{
	scanf("%d %d",&n,&m);
	t=(m+1);
	for(int i=1;i<=m;i++)
		a[i]=i;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;i++)
		printf("%d\n",a[(i-1)%m+1]);
}