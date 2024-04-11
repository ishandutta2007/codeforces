#include<iostream>
#include<cstdio>
#include<algorithm> 
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int n,a[100005],cnt[100005],cnt2[100005];
int main()
{
	int t;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		int ans=0;
		for(int i=0;i<=n;i++)cnt[i]=0,cnt2[i]=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			cnt[a[i]]++;
			if(a[i]==a[i-1])cnt2[a[i]]+=2,ans++;
		}
		sort(cnt,cnt+n+1);
		if(cnt[n]>(n+1)/2){cout<<"-1\n";continue;} 
		cnt2[a[1]]++;
		cnt2[a[n]]++;
		sort(cnt2,cnt2+n+1);
		printf("%d\n",ans+max(0,cnt2[n]-ans-2));
	}
}