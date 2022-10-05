#include <bits/stdc++.h>
using namespace std;
const int Maxn=55;
int ans,dp[1005][Maxn][Maxn],n,m,p,fail1[Maxn],fail2[Maxn],nxt1[Maxn][28],nxt2[Maxn][28];
string s,t,c;
void init(void)
{
	fail1[0]=fail1[1]=0;
	for(int i=1;i<n;i++)
	{
		int tmp=fail1[i];
		while(tmp&&s[tmp]!=s[i]) tmp=fail1[tmp];
		fail1[i+1]=(s[tmp]==s[i])?tmp+1:0;
	}
	for(int i=0;i<n;i++)
		for(char j='a';j<='z';j++)
		{
			int tmp=i;
			while(tmp&&s[tmp]!=j) tmp=fail1[tmp];
			if(s[tmp]==j) tmp++;
			nxt1[i][j-'a']=tmp;
		}
	fail2[0]=fail2[1]=0;
	for(int i=1;i<m;i++)
	{
		int tmp=fail2[i];
		while(tmp&&t[tmp]!=t[i]) tmp=fail2[tmp];
		fail2[i+1]=(t[tmp]==t[i])?tmp+1:0;
	}
	for(int i=0;i<m;i++)
		for(char j='a';j<='z';j++)
		{
			int tmp=i;
			while(tmp&&t[tmp]!=j) tmp=fail2[tmp];
			if(t[tmp]==j) tmp++;
			nxt2[i][j-'a']=tmp;
		}
}
int main()
{
//	freopen("CF1063D.in","r",stdin);
 	cin>>c>>s>>t;
 	n=s.size(),m=t.size(),p=c.size();
 	init();
 	memset(dp,-0x3f,sizeof(dp));
 	dp[0][0][0]=0;
 	for(int i=1;i<=p;i++)
 		for(int j=0;j<n;j++)
 			for(int k=0;k<m;k++)
 				for(int ch='a';ch<='z';ch++)
 					if(c[i-1]=='*'||c[i-1]==ch)
 					{
 						int tmp1=nxt1[j][ch-'a'],tmp2=nxt2[k][ch-'a'];
 						int now=dp[i-1][j][k]+(tmp1==n)-(tmp2==m);
 						if(tmp1==n) tmp1=fail1[tmp1];
 						if(tmp2==m) tmp2=fail2[tmp2];
						dp[i][tmp1][tmp2]=max(dp[i][tmp1][tmp2],now);
 					}
 	ans=-0x3f3f3f3f;
	for(int i=0;i<n;i++)
 		for(int j=0;j<m;j++)
 			ans=max(ans,dp[p][i][j]);
 	printf("%d",ans);
 	return 0;
 }