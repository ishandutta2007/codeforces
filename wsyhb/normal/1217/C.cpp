#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int mx=2e5+5;
char s[mx];
int cnt[mx];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1),ans=0,Cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1') cnt[i]=-1,Cnt=i;
			else cnt[i]=Cnt;
		}
		for(int j=n;j>=1;j--)
		{
			int tot=0,i,ss=1;
			for(i=j;i>=1&&j-i+1<=20;i--)
			{
				tot+=(s[i]-'0')*ss,ss*=2;
				if(tot==j-i+1) ans++;
			}
			if(!i) continue;
			i++;
			if(cnt[i]==-1) continue;
			if(tot<=j-cnt[i]&&tot>j-i+1) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}