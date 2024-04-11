#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef double ld;
#define pb push_back
#define SZ 666666
int n,f[SZ],t[SZ],c=0,g[SZ],h[SZ];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",f+i);
		if(!t[f[i]]) t[f[i]]=++c;
	}
	for(int i=1;i<=n;i++)
		h[t[f[i]]]=f[i],g[f[i]]=t[f[i]];
	for(int i=1;i<=n;i++)
		if(!g[i]) g[i]=g[f[i]];
	for(int i=1;i<=c;i++)
		if(g[h[i]]!=i) {puts("-1"); return 0;}
	for(int i=1;i<=n;i++)
		if(h[g[i]]!=f[i]) {puts("-1"); return 0;}
	printf("%d\n",c);
	for(int i=1;i<=n;i++) printf("%d ",g[i]);puts("");
	for(int i=1;i<=c;i++) printf("%d ",h[i]);puts("");
}