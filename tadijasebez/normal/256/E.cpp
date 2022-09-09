#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
const int mod=777777777;
const int N=77777+1;
const int M=2*N;
bool good[4][4];
struct Node
{
	int dp[4][4];
	Node(){}
	Node(int x)
	{
		for(int i=0;i<4;i++) for(int j=0;j<4;j++) dp[i][j]=0;
		if(x==0) dp[1][1]=dp[2][2]=dp[3][3]=1;
		else dp[x][x]=1;
	}
	int Get()
	{
		int i,j;
		int ans=0;
		for(i=1;i<=3;i++) for(j=1;j<=3;j++) ans+=dp[i][j],ans=ans>=mod?ans-mod:ans;
		return ans;
	}
} node[M];
Node operator + (Node a, Node b)
{
	Node ans;
	int i,j,k,l;
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			ans.dp[i][j]=0;
			for(k=1;k<=3;k++)
			{
				for(l=1;l<=3;l++)
				{
					if(!good[k][l]) continue;
					ans.dp[i][j]+=(ll)a.dp[i][k]*b.dp[l][j]%mod;
					if(ans.dp[i][j]>=mod) ans.dp[i][j]-=mod;
				}
			}
		}
	}
	return ans;
}
int ls[M],rs[M],root,tsz;
void Build(int &c, int ss, int se)
{
	c=++tsz;
	if(ss==se){ node[c]=Node(0);return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	node[c]=node[ls[c]]+node[rs[c]];
}
void Set(int c, int ss, int se, int qi, int x)
{
	if(ss==se){ node[c]=Node(x);return;}
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,x);
	else Set(rs[c],mid+1,se,qi,x);
	node[c]=node[ls[c]]+node[rs[c]];
}
int main()
{
	int n,i,j,q,x,y;
	scanf("%i %i",&n,&q);
	for(i=1;i<=3;i++) for(j=1;j<=3;j++) scanf("%i",&good[i][j]);
	Build(root,1,n);
	while(q--)
	{
		scanf("%i %i",&x,&y);
		Set(root,1,n,x,y);
		printf("%i\n",node[root].Get());
	}
	return 0;
}