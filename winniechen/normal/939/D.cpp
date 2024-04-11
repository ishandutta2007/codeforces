#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 100005
char s1[N],s2[N];int fa[30],n,ans,a[30],b[30];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main()
{
	for(int i=0;i<30;i++)fa[i]=i;
	scanf("%d%s%s",&n,s1+1,s2+1);
	for(int i=1;i<=n;i++)
	{
		int x=s1[i]-'a'+1,y=s2[i]-'a'+1;
		if(find(x)!=find(y))
		{
			ans++;
			a[ans]=find(x),b[ans]=find(y);
			fa[find(x)]=find(y);
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++)printf("%c %c\n",a[i]+'a'-1,b[i]+'a'-1);
}