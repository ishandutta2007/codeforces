#include<bits/stdc++.h>
#define maxn 2000005
using namespace std;
int T,n,k;
char str[maxn];
int a[maxn],s[maxn];
bool vis[maxn];
int Ans[maxn];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",str+1);
		for(int i=1;i<=n;++i)a[i]=(str[i]-'0')^1;
		for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
		for(int l=1;l<=n-k+1;++l)
		{
			int r=l+k-1;
			int st=max(l,r-19);
			if(s[st-1]!=s[l-1])continue;
			int num=0;
			for(int j=st;j<=r;++j)num=num*2+a[j];
			vis[num]=1;
		}
		int ans=-1;
		for(int i=0;i<(1<<20);++i)if(!vis[i])
		{
			ans=i;
			break;
		}
		if(ans==-1)puts("NO");
		else if(k<=20&&ans>=(1<<k))puts("NO");
		else
		{
			puts("YES");
			if(k<=20)
			{
				for(int i=0;i<k;++i)Ans[i]=(ans>>i)&1;
				for(int i=k-1;i>=0;--i)printf("%d",Ans[i]);
				printf("\n");
			}
			else
			{
				for(int i=1;i<=k-20;++i)printf("0");
				for(int i=0;i<20;++i)Ans[i]=(ans>>i)&1;
				for(int i=19;i>=0;--i)printf("%d",Ans[i]);
				printf("\n");
			}
		}
		for(int l=1;l<=n-k+1;++l)
		{
			int r=l+k-1;
			int st=max(l,r-19);
			if(s[st-1]!=s[l-1])continue;
			int num=0;
			for(int j=st;j<=r;++j)num=num*2+a[j];
			vis[num]=0;
		}
	}
}