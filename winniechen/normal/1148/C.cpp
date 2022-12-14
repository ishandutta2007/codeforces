#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 300005
int p[N],n,pos[N];
int ans[N*5][2],cnt;
void add(int x,int y){swap(p[x],p[y]);swap(pos[p[x]],pos[p[y]]);ans[++cnt][0]=x,ans[cnt][1]=y;}
void print(int x,int y)
{
	if(x>y)swap(x,y);
	if((y-x)*2>=n)add(x,y);
	else
	{
		if(x>(n/2))add(x,1),add(1,y),add(1,x);
		else if(y<=(n/2))add(x,n),add(n,y),add(n,x);
		else add(n,x),add(y,1),add(n,1),add(n,x),add(y,1);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]),pos[p[i]]=i;
	for(int i=1;i<=n;i++)if(p[i]!=i)print(i,pos[i]);
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)printf("%d %d\n",ans[i][0],ans[i][1]);
}