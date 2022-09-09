#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt meke_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=5050;
bool dp[N][N];
char s[N],t[N];
int main()
{
	int n,i,j;
	scanf("%s",s);
	n=strlen(s);
	int ans=2;
	for(i=0;i<n;i++)
	{
		bool ne=0;
		for(j=1;j<=n;j++) t[j-1]=s[(i+j)%n];
		for(j=0;j<n;j++)
		{
			if(t[j]!=s[j]){ ne=1;break;}
		}
		if(ne)
		{
			bool ok=1;
			for(j=0;j<n;j++)
			{
				if(t[j]!=t[n-j-1]){ ok=0;break;}
			}
			if(ok){ ans=1;break;}
		}
	}
	bool ok=0;
	for(i=0;i<n/2;i++) if(s[i]!=s[0]) ok=1;
	if(!ok) printf("Impossible\n");
	else printf("%i\n",ans);
	/*
	for(j=1;j<=n;j++)
	{
		for(i=1;i<=n-j+1;i++)
		{
			int l=i,r=i+j-1;
			if(l==r) dp[l][r]=1;
			else
			{
				if(l+1==r) dp[l][r]=s[l]==s[r];
				else dp[l][r]=s[l]==s[r] && dp[l+1][r-1];
			}
			//printf("%i %i: %i\n",l,r,dp[l][r]);
		}
	}
	int l=1,r=n;
	int ans=0,mul=1;
	while(l<=r)
	{
		//printf("%i %i %i\n",l,r,dp[l][r]);
		if(!dp[l][r]) break;
		if(l==r) return 0*printf("Impossible\n");
		if((r-l)&1) ans+=mul;
		else ans+=2*mul;
		r=r/2;
		mul*=2;
	}
	printf("%i\n",ans);*/
	return 0;
}