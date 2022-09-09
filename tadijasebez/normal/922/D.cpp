#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
#define ll long long
const int N=100050;
int s[N],h[N];
bool comp(int a, int b)
{
	return (ll)s[a]*h[b]>(ll)s[b]*h[a];
}
string str[N];
int a[N];
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		cin >> str[i];
		for(j=0;j<str[i].size();j++)
		{
			if(str[i][j]=='s') s[i]++;
			else h[i]++;
		}
		a[i]=i;
	}
	sort(a+1,a+1+n,comp);
	int cnt=0;
	ll sol=0;
	for(i=1;i<=n;i++)
	{
		//printf("%i\n",a[i]);
		for(j=0;j<str[a[i]].size();j++)
		{
			if(str[a[i]][j]=='s') cnt++;
			else sol+=cnt;
		}
	}
	printf("%lld\n",sol);
	return 0;
}