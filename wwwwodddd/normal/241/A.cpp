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
int m,k,mx;
long long lft,z;
int d[100020];
int s[100020];
int main()
{
	scanf("%d %d",&m,&k);
	for(int i=0;i<m;i++)
		scanf("%d",d+i),z+=d[i];
	for(int i=0;i<m;i++)
		scanf("%d",s+i);
	for(int i=0;i<m;i++)
	{
		mx=max(mx,s[i]);
		lft+=s[i];
		if(lft<d[i])
		{
			long long tim=(d[i]-lft+mx-1)/mx;
			z+=tim*k;
			lft+=mx*tim;
		}
		lft-=d[i];
	}
	cout<<z<<endl;
	return 0;
}