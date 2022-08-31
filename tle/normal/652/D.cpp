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
int n,lsn=0,lss[666666];
typedef pair<pair<int,int>,int> piii;
piii ps[666666];
#define pa first.first
#define pb first.second
#define pc second
int ss[666666],ans[666666];
int sum(int x)
{
	int anss=0;
	for(;x>=1;x-=x&-x) anss+=ss[x];
	return anss;
}
void edit(int x,int y)
{
	for(;x<=lsn;x+=x&-x) ss[x]+=y;
}
#define fls(x) x=lower_bound(lss+1,lss+1+lsn,x)-lss
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&ps[i].pa,&ps[i].pb);
		ps[i].pc=i; lss[++lsn]=ps[i].pa; lss[++lsn]=ps[i].pb;
	}
	sort(lss+1,lss+1+lsn);
	for(int i=1;i<=n;i++) fls(ps[i].pa),fls(ps[i].pb);
	sort(ps+1,ps+1+n);
	for(int i=n;i>=1;i--)
	{
		int l=ps[i].pa,r=ps[i].pb,c=ps[i].pc;
		ans[c]=sum(r); edit(r,1);
	}
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
}