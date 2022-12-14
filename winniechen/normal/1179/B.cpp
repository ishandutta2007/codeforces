#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000005;
int n,m,flag,tot;
struct P
{
	int x,y;
	P(){x=y=0;}
	P(int a,int b){x=a,y=b;}
	P operator + (const P &a) const {return P(x+a.x,y+a.y);}
}ans[N];
int main()
{
	scanf("%d%d",&n,&m);
	if(n==1)
	{
		for(int j=1;j<=m>>1;j++)
			ans[++tot]=P(1,j),ans[++tot]=P(1,m-j+1);
		if(m&1)ans[++tot]=P(1,(m+1)>>1);
		for(int i=1;i<=tot;i++)printf("%d %d\n",ans[i].x,ans[i].y);
		return 0;
	}
	for(int i=1;i<=n>>1;i++)
		for(int j=1;j<=m;j++)
			ans[++tot]=P(i,j),ans[++tot]=P(n-i+1,m-j+1);
	int pos=(n>>1)+1;
	if(n&1)
	{
		for(int j=1;j<=m>>1;j++)
			ans[++tot]=P(pos,m-j+1),ans[++tot]=P(pos,j);
		if(m&1)ans[++tot]=P(pos,(m+1)>>1);
	}
	for(int i=1;i<=tot;i++)printf("%d %d\n",ans[i].x,ans[i].y);
}