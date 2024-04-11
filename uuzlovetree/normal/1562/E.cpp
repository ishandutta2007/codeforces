#include<bits/stdc++.h>
using namespace std;
#define maxn 5005
struct Suffix_Array
{
	int n,s[maxn],x[maxn],y[maxn],c[maxn],sa[maxn],rk[maxn],h[maxn];
	void clear()
	{
		n=0;
		memset(s,0,sizeof(s));
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		memset(c,0,sizeof(c));
		memset(sa,0,sizeof(sa));
		memset(rk,0,sizeof(rk));
		memset(h,0,sizeof(h));
	}
	void build(int m)
	{
	    for(int i=1;i<=m;i++)c[i]=0;
	    for(int i=1;i<=n;i++)c[x[i]=s[i]]++;
	    for(int i=1;i<=m;i++)c[i]+=c[i-1];
	    for(int i=n;i>=1;i--)sa[c[x[i]]--]=i;
	    for(int k=1;k<=n;k<<=1)
	    {
	        int p=0;
	        for(int i=n-k+1;i<=n;i++)y[++p]=i;
	        for(int i=1;i<=n;i++)if(sa[i]>k)y[++p]=sa[i]-k;
	        for(int i=1;i<=m;i++)c[i]=0;
	        for(int i=1;i<=n;i++)c[x[y[i]]]++;
	        for(int i=1;i<=m;i++)c[i]+=c[i-1];
	        for(int i=n;i>=1;i--)sa[c[x[y[i]]]--]=y[i];
	        swap(x,y);x[sa[1]]=p=1;
	        for(int i=2;i<=n;i++)
	        if(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])x[sa[i]]=p;else x[sa[i]]=++p;
	        if(p>=n)break;
			m=p+1;
	    }
	    for(int i=1;i<=n;i++)rk[sa[i]]=i;
	    int k=0;
	    for(int i=1;i<=n;i++)
	    {
	        int j=sa[rk[i]-1];
	        if(k)k--;while(s[i+k]==s[j+k])k++;
	        h[rk[i]]=k;
	    }
	}
	int st[maxn][20],Log[maxn];
	void init()
	{
	    for(int i=1;i<=n;i++)st[i][0]=h[i];
	    for(int i=1;i<=n;++i)Log[i]=log2(i);
	    for(int j=1;(1<<j)<=n;j++)
	    for(int i=1;i+(1<<j)-1<=n;i++)
	    st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	}
	int lcp(int x,int y)
	{
		if(x==y)return n-x+1;
	    int l=rk[x],r=rk[y];
	    if(l>r)swap(l,r);l++;
	    int k=Log[r-l+1];
	    return min(st[l][k],st[r-(1<<k)+1][k]);
	}
}sa;
int T,n; 
char str[maxn];
int dp[maxn];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",str+1);
		sa.clear();
		for(int i=1;i<=n;++i)sa.s[++sa.n]=str[i];
		sa.build(150);
		sa.init();
		int ans=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;++i)
		{
			dp[i]=n-i+1;
			for(int j=1;j<i;++j)
			{
				int L=sa.lcp(j,i);
				if(i+L-1==n)dp[i]=max(dp[i],dp[j]);
				else
				{
					if(str[j+L]<str[i+L])dp[i]=max(dp[i],dp[j]+(n-(i+L)+1));
				}
			}
			ans=max(ans,dp[i]);
		}
		printf("%d\n",ans);
	}
}