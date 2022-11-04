#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct unit
{int c,v;
};
struct unit a[200010],b[200010];

int n,m,s,T,tot,ans;
int g[200010];

bool cmp(unit A,unit B)
{return A.v>B.v || (A.v==B.v && A.c<B.c);
}

int check(int x)
{int i;
 long long ret=0;
 
 for(i=1;i<=m;i++)
 {	if(x<g[i]-g[i-1]) return 0;
 	ret+=(ll)(g[i]-g[i-1])*2;
 	ret-=min(x-(g[i]-g[i-1]),g[i]-g[i-1]);
 }
 return ret<=T;
}

int main()
{int i,j,l,r,mid;

 scanf("%d%d%d%d",&n,&m,&s,&T);
 for(i=1;i<=n;i++)
 	scanf("%d%d",&a[i].c,&a[i].v);
 sort(a+1,a+n+1,cmp);
 for(i=1;i<=m;i++) scanf("%d",&g[i]);
 g[++m]=s;
 sort(g+1,g+m+1);
 tot=0;
 for(i=1;i<=n;i++)
 	if(!tot || a[i].c<b[tot].c)
 		b[++tot]=a[i];
 l=1;
 r=tot;
 ans=-1;
 while(l<=r)
 {	mid=(l+r)/2;
 	if(check(b[mid].v))
 	{	ans=max(ans,mid);
 		l=mid+1;
 	}
 	else
 		r=mid-1;
 }
 if(ans!=-1)
 	printf("%d\n",b[ans].c);
 else
 	printf("%d\n",-1);
 return 0;
}