#include <stdio.h>
const int N=1000050;
const int M=2*N;
int max(int a, int b){ return a>b?a:b;}
int cnt[M][2],dp[M][2],lzy[M],ls[M],rs[M],a[N],tsz,root;
void Take(int c)
{
	dp[c][0]=max(dp[ls[c]][0],dp[rs[c]][0]);
	dp[c][0]=max(dp[c][0],cnt[ls[c]][0]+cnt[rs[c]][1]);
	dp[c][0]=max(dp[c][0],dp[ls[c]][0]+cnt[rs[c]][1]);
	dp[c][0]=max(dp[c][0],cnt[ls[c]][0]+dp[rs[c]][0]);
	dp[c][1]=max(dp[ls[c]][1],dp[rs[c]][1]);
	dp[c][1]=max(dp[c][1],cnt[ls[c]][1]+cnt[rs[c]][0]);
	dp[c][1]=max(dp[c][1],dp[ls[c]][1]+cnt[rs[c]][0]);
	dp[c][1]=max(dp[c][1],cnt[ls[c]][1]+dp[rs[c]][1]);
	cnt[c][0]=cnt[ls[c]][0]+cnt[rs[c]][0];
	cnt[c][1]=cnt[ls[c]][1]+cnt[rs[c]][1];
	dp[c][0]=max(dp[c][0],cnt[c][0]);
	dp[c][0]=max(dp[c][0],cnt[c][1]);
	dp[c][1]=max(dp[c][1],cnt[c][0]);
	dp[c][1]=max(dp[c][1],cnt[c][1]);
}
void Build(int &c, int ss, int se)
{
	c=++tsz;
	if(ss==se)
	{
		dp[c][0]=dp[c][1]=1;
		cnt[c][a[ss]]=1;
		return;
	}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	Take(c);
}
void Swap(int &a, int &b){ a^=b,b^=a,a^=b;}
void Propagate(int c, int ss, int se)
{
	if(lzy[c])
	{
		Swap(dp[c][0],dp[c][1]);
		Swap(cnt[c][0],cnt[c][1]);
		if(ss!=se) lzy[ls[c]]^=1,lzy[rs[c]]^=1;
		lzy[c]=0;
	}
}
void Set(int c, int ss, int se, int qs, int qe)
{
	Propagate(c,ss,se);
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se)
	{
		lzy[c]^=1;
		Propagate(c,ss,se);
		return;
	}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe);
	Set(rs[c],mid+1,se,qs,qe);
	Take(c);
}
char s[N],t[20];
int main()
{
	int n,q,i,l,r;
	scanf("%i %i",&n,&q);
	scanf("%s",s+1);
	for(i=1;i<=n;i++) if(s[i]=='7') a[i]=1;
	Build(root,1,n);
	while(q--)
	{
		scanf("%s",t+1);
		if(t[1]=='s') scanf("%i %i",&l,&r),Set(root,1,n,l,r);
		else printf("%i\n",dp[root][0]);
	}
	return 0;
}