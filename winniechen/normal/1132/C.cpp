#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 5005
#define ll long long
struct node
{
	int l,r;
	bool operator < (const node &a) const {return l==a.l?r<a.r:l<a.l;}
}a[N];
int n,m,ans,b[N],hav[N],nn;
vector<int>v[N];
int get_val(int x)
{
	int ret=nn;
	memset(hav,0,sizeof(hav));
	for(int i=a[x].l;i<=a[x].r;i++)
	{
		if(b[i]==1)ret--;
		else if(b[i]==2)hav[v[i][v[i][0]==x]]++;
	}
	for(int i=1;i<a[x].l;i++)if(b[i]==1)hav[v[i][0]]++;
	for(int i=a[x].r+1;i<=n;i++)if(b[i]==1)hav[v[i][0]]++;
	int tmp=1<<30;
	for(int i=1;i<=m;i++)if(i!=x)tmp=min(tmp,hav[i]);
	return ret-tmp;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d",&a[i].l,&a[i].r);sort(a+1,a+m+1);
	for(int i=1;i<=m;i++)
		for(int j=a[i].l;j<=a[i].r;j++)
			b[j]++,v[j].push_back(i);
	for(int i=1;i<=n;i++)if(b[i])nn++;
	for(int i=1;i<=m;i++)ans=max(ans,get_val(i));
	printf("%d\n",ans);
}