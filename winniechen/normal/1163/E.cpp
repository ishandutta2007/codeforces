#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 200005
int a[N],n;int p[30],val[30];
bool check(int x)
{
	memset(p,0,sizeof(p));int cnt=0;
	for(int i=1,tmp;i<=n;i++)if(a[i]<(1<<x+1))
	{
		tmp=a[i];
		for(int j=x;~j;j--)if(tmp>>j&1)
			if(p[j])tmp^=p[j];
			else{val[j]=a[i],p[j]=tmp,cnt++;break;}
	}
	return cnt==x+1;
}
int ans[(1<<20)+5];
void solve(int *a,int dep)
{
	if(dep==-1)return ;
	a[1<<dep]=val[dep];
	solve(a,dep-1),solve(a+(1<<dep),dep-1);
}
void print(int x){solve(ans,x-1);printf("0 ");for(int i=1;i<1<<x;i++)ans[i]^=ans[i-1],printf("%d ",ans[i]);}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=18;i;i--)
		if(check(i-1))return printf("%d\n",i),print(i),0;
	puts("0\n0");
}