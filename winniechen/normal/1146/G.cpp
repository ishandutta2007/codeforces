#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 55
#define ll long long
int n,m,h;
struct node
{
	int l,r,h,c;
	bool operator < (const node &a) const {return l==a.l?r<a.r:l<a.l;}
}a[N];
int f[N][N][N],g[N][N][N];
int main()
{
	scanf("%d%d%d",&n,&h,&m);
	for(int i=1;i<=m;i++)scanf("%d%d%d%d",&a[i].l,&a[i].r,&a[i].h,&a[i].c);
	for(int len=1;len<=n;len++)
		for(int l=1,r=len;r<=n;l++,r++)
			for(int i=1;i<=h;i++)
			{
				f[l][r][i]=-1e9;
				for(int k=l;k<=r;k++)
				{
					int tmp=g[l][k-1][i]+g[k+1][r][i]+i*i;
					for(int t=1;t<=m;t++)
						if(a[t].l>=l&&a[t].l<=k&&a[t].r>=k&&a[t].r<=r&&a[t].h<i)
							tmp-=a[t].c;
					f[l][r][i]=max(f[l][r][i],tmp);
				}
				g[l][r][i]=max(g[l][r][i-1],f[l][r][i]);
			}
	printf("%d\n",g[1][n][h]);
}