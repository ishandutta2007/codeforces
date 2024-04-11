#include <stdio.h>
#include <vector>
using namespace std;
const int N=1024;
const int M=100050;
int x[M*12],ls[M*12],rs[M*12],clock,root[M][N];
bool Lazy[M][N];
void Set(int p ,int &c, int ss, int se, int qi, int val)
{
	c=++clock;ls[c]=ls[p];rs[c]=rs[p];x[c]=x[p]+val;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[p],ls[c],ss,mid,qi,val);
	else Set(rs[p],rs[c],mid+1,se,qi,val);
}
int Get(int c, int ss, int se, int qi)
{
	if(ss==se) return x[c];
	int mid=ss+se>>1;
	if(qi<=mid) return Get(ls[c],ss,mid,qi);
	return Get(rs[c],mid+1,se,qi);
}
int Calc(int xx, int n, int m)
{
	int ret=0;
	int i;
	for(i=1;i<=n;i++)
	{
		if(Lazy[xx][i]) ret+=m-x[root[xx][i]];
		else ret+=x[root[xx][i]];
	}
	return ret;
}
int main()
{
	int n,m,q,i,j,t,x,y;
	scanf("%i %i %i",&n,&m,&q);
	for(i=1;i<=q;i++)
	{
		scanf("%i",&t);
		if(t==1)
		{
			scanf("%i %i",&x,&y);
			for(j=1;j<=n;j++)
			{
				root[i][j]=root[i-1][j];
				Lazy[i][j]=Lazy[i-1][j];
			}
			int k=Get(root[i][x],1,m,y);
			if(k && Lazy[i][x]) Set(root[i][x],root[i][x],1,m,y,-1);
			if(!k && !Lazy[i][x]) Set(root[i][x],root[i][x],1,m,y,1);
		}
		if(t==2)
		{
			scanf("%i %i",&x,&y);
			for(j=1;j<=n;j++)
			{
				root[i][j]=root[i-1][j];
				Lazy[i][j]=Lazy[i-1][j];
			}
			int k=Get(root[i][x],1,m,y);
			if(!k && Lazy[i][x]) Set(root[i][x],root[i][x],1,m,y,1);
			if(k && !Lazy[i][x]) Set(root[i][x],root[i][x],1,m,y,-1);
		}
		if(t==3)
		{
			scanf("%i",&x);
			for(j=1;j<=n;j++)
			{
				root[i][j]=root[i-1][j];
				Lazy[i][j]=Lazy[i-1][j];
			}
			Lazy[i][x]^=1;
		}
		if(t==4)
		{
			scanf("%i",&x);
			for(j=1;j<=n;j++)
			{
				root[i][j]=root[x][j];
				Lazy[i][j]=Lazy[x][j];
			}
		}
		printf("%i\n",Calc(i,n,m));
	}
	return 0;
}