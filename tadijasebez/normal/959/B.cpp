#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <iostream>
#include <string>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
const int N=100050;
map<string,int> id;
int a[N],Min[N],b[N];
vector<int> Groups[N];
const int inf=1e9+7;
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int n,k,m,i,j,sz,x;
	scanf("%i %i %i",&n,&k,&m);
	string s;
	for(i=1;i<=n;i++)
	{
		cin >> s;
		id[s]=i;
	}
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=k;i++)
	{
		scanf("%i",&sz);
		b[i]=inf;
		while(sz--)
		{
			scanf("%i",&x);
			Groups[x].pb(i);
			b[i]=min(b[i],a[x]);
		}
	}
	ll sol=0;
	for(i=1;i<=m;i++)
	{
		cin >> s;
		int idx=id[s];
		for(j=0;j<Groups[idx].size();j++)
		{
			a[idx]=min(a[idx],b[Groups[idx][j]]);
		}
		Groups[idx].clear();
		sol+=a[idx];
	}
	printf("%lld\n",sol);
	return 0;
}