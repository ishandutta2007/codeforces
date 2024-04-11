#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int n;
int a[200010],b[200010],fa[200010],used[200010];
long long now;
long long ans[200010],f[200010];

int find(int x)
{return fa[x]==x?x:fa[x]=find(fa[x]);
}

void work(int x,int y)
{int fx,fy;

 fx=find(x);
 fy=find(y);
 fa[fx]=fy;
 f[fy]+=f[fx];
 now=max(now,f[fy]);
}

int main()
{int i,j,p;
 
 scanf("%d",&n);
 for(i=1;i<=n;i++) scanf("%d",&a[i]);
 for(i=1;i<=n;i++) scanf("%d",&b[i]);
 for(i=1;i<=n;i++) fa[i]=i;
 for(i=n;i>=1;i--)
 {	ans[i]=now;
 	p=b[i];
 	used[p]=1;
 	f[p]=a[p];
 	now=max(now,f[p]);
 	if(used[p-1]) work(p-1,p);
 	if(used[p+1]) work(p,p+1);
 }
 for(i=1;i<=n;i++)
 	printf("%I64d\n",ans[i]);
 return 0;
}