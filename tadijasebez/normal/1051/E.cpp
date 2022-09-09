#include <bits/stdc++.h>
using namespace std;
const int N=1000050;
char a[N],l[N],r[N];
const int mod=998244353;
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
int sub(int x, int y){ x-=y;return x<0?x+mod:x;}
int dp[N],sum[N];
int LCP[N],RCP[N],TMP[N];
void Build(char *s, char *t, int *LCP)
{
	int n=strlen(s+1),m=strlen(t+1);
	for(int l=0,r=0,i=2;i<=n;i++)
	{
		if(r>=i) TMP[i]=min(TMP[i-l+1],r-i+1);
		else TMP[i]=0;
		while(s[TMP[i]+1]==s[i+TMP[i]]) TMP[i]++;
		if(i+TMP[i]-1>r) l=i,r=i+TMP[i]-1;
	}
	for(int l=0,r=0,i=1;i<=m;i++)
	{
		if(r>=i) LCP[i]=min(TMP[i-l+1],r-i+1);
		while(LCP[i]<n && s[LCP[i]+1]==t[i+LCP[i]]) LCP[i]++;
		if(i+LCP[i]-1>r) l=i,r=i+LCP[i]-1;
	}
}
int n,L,R;
bool CheckL(int x)
{
	int p=x-L+1;
	int y=LCP[p];
	if(y==L || l[y+1]<a[p+y]) return 1;
	return 0;
}
bool CheckR(int x)
{
	int p=x-R+1;
	int y=RCP[p];
	if(y==R || r[y+1]>a[p+y]) return 1;
	return 0;
}
int main()
{
	scanf("%s %s %s",a+1,l+1,r+1);
	n=strlen(a+1),L=strlen(l+1),R=strlen(r+1);
	Build(l,a,LCP);
	Build(r,a,RCP);
	dp[0]=1;sum[1]=1;
	for(int i=1;i<=n;i++)
	{
		int lo=max(0,i-R+1),hi=i-L-1;
		if(hi>=lo) dp[i]=sub(sum[hi+1],sum[lo]);
		if(L==R)
		{
			if(i>=L && (a[i-L+1]!='0' || L==1) && CheckL(i) && CheckR(i)) dp[i]=add(dp[i],dp[i-L]);
		}
		else
		{
			if(i>=L && (a[i-L+1]!='0' || L==1) && CheckL(i)) dp[i]=add(dp[i],dp[i-L]);
			if(i>=R && (a[i-R+1]!='0' || R==1) && CheckR(i)) dp[i]=add(dp[i],dp[i-R]);
		}
		if(a[i+1]=='0') sum[i+1]=sum[i];
		else sum[i+1]=add(sum[i],dp[i]);
	}
	printf("%i\n",dp[n]);
	return 0;
}