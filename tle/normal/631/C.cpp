#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <math.h>
#include <limits>
#include <set>
#include <map>
using namespace std;
int n,m,a[233333],t[233333],r[233333],mn,ax[233333];
int sn=0,st[233333];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=m;i++) scanf("%d%d",t+i,r+i);
	for(int i=1;i<=m;i++)
	{
		while(sn&&r[st[sn]]<r[i]) --sn;
		st[++sn]=i;
	}
	mn=r[st[1]];
	sort(a+1,a+1+mn);
    int gg=1,L=1,R=mn,cur=0,lst=mn;
    for(int i=1;i<=sn;i++)
    {
    	if(gg==t[st[i]]) continue;
    	gg=t[st[i]];
    	cur^=1;
    	for(int j=lst;j>r[st[i]];j--) ax[j]=(cur)?(R--):(L++);
		lst=r[st[i]];
    }
    cur^=1;
    for(int j=lst;j>=1;j--) ax[j]=(cur)?(R--):(L++);
    for(int i=1;i<=mn;i++) printf("%d ",a[ax[i]]);
    for(int i=mn+1;i<=n;i++) printf("%d ",a[i]);
}