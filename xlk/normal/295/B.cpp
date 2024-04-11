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
ll d[550][550];
ll z[550];
ll r[550],p[550],n;
int main()
{
	cin >> n;
	fo(i,n)
		fo(j,n)
			scanf("%I64d",&d[i][j]);
	fo(i,n)
	{
		scanf("%I64d",&p[i]); r[p[i]] = i;
	}
	for(int k=n;k>0;k--)
	{
		fo(i,n)
			fo(j,n)
				d[i][j] = min(d[i][j],d[i][p[k]] + d[p[k]][j]);
		ll sm = 0;
		fo(i,n)
			fo(j,n)
				if(r[i]>=k&&r[j]>=k)
					sm += d[i][j];
		z[k]=sm;
	}
	fo(i,n)
		printf("%I64d ",z[i]);
	return 0;
}