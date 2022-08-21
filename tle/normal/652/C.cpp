#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <limits>
#include <set>
#include <map>
using namespace std;
int n,m,p[333333],rv[333333];
typedef pair<int,int> pii;
pii ss[333333];
bool cmp(pii a,pii b) {return a.second<b.second;}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",p+i);
		rv[p[i]]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int aa=rv[a],bb=rv[b];
		if(aa>bb) swap(aa,bb);
		ss[i]=pii(aa,bb);
	}
	sort(ss+1,ss+1+m,cmp);
	int cc=1,ml=0;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		while(cc<=m&&ss[cc].second<=i) ml=max(ml,ss[cc++].first);
		ans+=i-ml;
	}
	cout<<ans;
}