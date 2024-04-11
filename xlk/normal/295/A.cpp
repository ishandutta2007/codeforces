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
typedef long long ll;
ll a[100020];
ll b[100020];
ll c[100020];
ll L[100020];
ll R[100020];
ll D[100020];
int n,m,k;
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",a+i);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%I64d%I64d%I64d",L+i,R+i,D+i);
	}
	for(int i=1;i<=k;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		b[x]++;
		b[y+1]--;
	}
	for(int i=1;i<=m+1;i++)
	{
		b[i]+=b[i-1];
	}
	for(int i=1;i<=m;i++)
	{
		c[L[i]]+=b[i]*D[i];
		c[R[i]+1]-=b[i]*D[i];
	}
	for(int i=1;i<=n;i++)
	{
		c[i]+=c[i-1];
		printf("%I64d ",a[i]+c[i]);
	}
}