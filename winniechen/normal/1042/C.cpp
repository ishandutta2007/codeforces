#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
#include <set>
using namespace std;
#define N 200005
#define inf 0x3f3f3f3f
#define nc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++)
char buf[1000000],*p1,*p2;
int rd()
{
	// int y;scanf("%d",&y);return y;
    register int x=0,f=1;register char c=nc();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=nc();}
    while(c>='0'&&c<='9')x=((x+(x<<2))<<1)+(c^48),c=nc();
    return x*f;
}
int b[N],n,cnt,mn=inf,mx=-inf,tot;bitset<N>vis;
int main()
{
	n=rd();int p1=0,p2=0;
	for(int i=1;i<=n;i++)
	{
		int x=rd();
		if(x<0)
		{
			cnt^=1;
			if(x>mx)mx=x,p1=i;
		}
		else if(x>0&&x<mn)mn=x,p2=i;
		else if(!x)b[++tot]=i,vis[i]=1;
	}
	if(cnt==1)b[++tot]=p1,vis[p1]=1;
	for(int i=1;i<tot;i++)printf("1 %d %d\n",b[i],b[i+1]);
	if(tot&&tot!=n)printf("2 %d\n",b[tot]);
	int last=-1;
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			if(last!=-1) printf("1 %d %d\n",last,i);
			last=i;
		}
	return 0;
}