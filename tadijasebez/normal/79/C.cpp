#include <stdio.h>
#include <cstring>
const int N=100050;
const int M=2*N;
const int inf=1e9+7;
char ch[N];
char word[15][15];
int sz[15];
int min(int a, int b){ return a>b?b:a;}
int a[N],x[M],ls[M],rs[M],clock,root;
void Build(int &c, int ss, int se)
{
	c=++clock;
	if(ss==se){ x[c]=a[ss];return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	x[c]=min(x[ls[c]],x[rs[c]]);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return inf;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return min(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
int Check(int k, int n)
{
	for(int i=1;i<=n-k+1;i++)
	{
		if(Get(root,1,n,i,i+k-1)>i+k-1) return i;
	}
	return 0;
}
int main()
{
	int n,m,i,j,k;
	scanf("%s",ch+1);
	n=strlen(ch+1);
	for(i=1;i<=n;i++) a[i]=inf;
	scanf("%i",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%s",word[i]+1);
		sz[i]=strlen(word[i]+1);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			bool ok=1;
			for(k=1;k<=sz[j];k++)
			{
				if(ch[i+k-1]!=word[j][k]) ok=0;
			}
			if(ok) a[i]=min(a[i],i+sz[j]-1);
		}
	}
	Build(root,1,n);
	int top=n,bot=1,mid,ans=0,sol=1;
	while(top>=bot)
	{
		mid=top+bot>>1;
		int tr=Check(mid,n);
		if(tr) ans=mid,sol=tr,bot=mid+1;
		else top=mid-1;
	}
	printf("%i %i\n",ans,sol-1);
	return 0;
}