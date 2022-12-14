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
bitset<7005>ans[N],G[7005],F[7005];
int miu[7005],pri[7005],vis[7005],cnt;
void Miu()
{
	miu[1]=1;
	for(int i=2;i<=7000;i++)
	{
		if(!vis[i])pri[++cnt]=i,miu[i]=-1;
		for(int j=1;j<=cnt&&i*pri[j]<=7000;++j)
		{
			vis[i*pri[j]]=1;if(i%pri[j]==0)break;
			miu[i*pri[j]]=-miu[i];
		}
	}
} 
int n,Q,op,x,y,z;
int main() {
	Miu();
	for(int i=1;i<=7000;i++)
		for(int j=i;j<=7000;j+=i)
			G[j][i]=1,F[i][j]=(miu[j/i]?1:0);
	scanf("%d%d",&n,&Q);
	while(Q--)
	{
		scanf("%d%d%d",&op,&x,&y);
		if(op==1)ans[x]=G[y];
		else if(op==2)scanf("%d",&z),ans[x]=ans[y]^ans[z];
		else if(op==3)scanf("%d",&z),ans[x]=ans[y]&ans[z];
		else printf("%d",((ans[x]&F[y]).count()&1));
	}puts("");
}