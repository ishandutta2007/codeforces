#include <stdio.h>
const int N=100050;
const int M=N*2;
const int inf=1e9;
int logs[N],MaxTable[N][20],MinTable[N][20],A[N];
void Preprocess()
{
	int k=0,i;
	for(i=0;i<N;i++)
	{
		if(i==1<<(k+1)) k++;
		logs[i]=k;
	}
}
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
void BuildSparseTable(int n)
{
	Preprocess();
	int i,j;
	for(i=1;i<=n;i++) MaxTable[i][0]=A[i];
	for(i=1;i<=n;i++) MinTable[i][0]=A[i];
	for(j=1;j<20;j++)
	{
		for(i=1;i<=n-(1<<j)+1;i++)
		{
			MaxTable[i][j]=max(MaxTable[i][j-1],MaxTable[i+(1<<(j-1))][j-1]);
			MinTable[i][j]=min(MinTable[i][j-1],MinTable[i+(1<<(j-1))][j-1]);
		}
	}
}
int Query(int l, int r)
{
	int k=logs[r-l+1];
	return max(MaxTable[l][k],MaxTable[r-(1<<k)+1][k])-min(MinTable[l][k],MinTable[r-(1<<k)+1][k]);
}
int x[M],ls[M],rs[M],clock,root;
void Build(int &c, int ss, int se)
{
	c=++clock;
	x[c]=inf;
	if(ss==se) return;
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
void Set(int c, int ss, int se, int qi, int val)
{
	x[c]=min(x[c],val);
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe) return inf;
	if(ss>qe || qs>se) return inf;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return min(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
int dp[N];
int main()
{
	int n,i,l,s;
	scanf("%i %i %i",&n,&s,&l);
	for(i=1;i<=n;i++) scanf("%i",&A[i]);
	BuildSparseTable(n);
	Build(root,0,N-1);
	Set(root,0,N-1,0,0);
	for(i=1;i<=n;i++)
	{
		int top=i;
		int bot=1;
		int mid,sol;
		while(top>=bot)
		{
			mid=top+bot>>1;
			if(Query(mid,i)<=s) sol=mid,top=mid-1;
			else bot=mid+1;
		}
		dp[i]=Get(root,0,N-1,sol-1,i-l)+1;
		Set(root,0,N-1,i,dp[i]);
	}
	if(dp[n]<inf) printf("%i\n",dp[n]);
	else printf("-1\n");
	return 0;
}