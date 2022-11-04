#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<map>
using namespace std;

const int inf=0x3f3f3f3f;

int n,col,ans,tot;
int a[100010],c[100010],d[100010];
map<int,int> used;

int check(int lim)
{int i,j,x;
 
 col++;
 for(i=1;i<=n;i++)
 {	x=a[i];
 	while(x)
	{	if(x<=lim && used[x]!=col) break;
		x/=2;
	}
 	if(x)
 	{	used[x]=col;
 		c[i]=x;
 	}
 	else
 		return 0;
 }
 return 1;
}

int main()
{int i,j,x,l,r,mid;
 
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 	scanf("%d",&a[i]);
 l=0;
 r=inf;
 ans=inf;
 while(l<=r)
 {	mid=(l+r)/2;
 	if(check(mid))
 	{	ans=mid;
 		for(i=1;i<=n;i++) d[i]=c[i];
 		r=mid-1;
 	}
 	else
 		l=mid+1;
 }
 for(i=1;i<=n;i++)
 {	printf("%d",d[i]);
	printf("%c",i!=n?' ':'\n');
 }
 return 0;
}