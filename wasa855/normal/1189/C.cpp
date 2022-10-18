#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int ans=0;
	while(isdigit(ch))
	{
		ans=ans*10+ch-48;
		ch=getchar();
	}
	return ans;
}
#define N 100005
int a[N];
int suf[N][25];
int ans[N][25];
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		suf[i][0]=a[i];
	}
	for(int i=1;i<=24;i++)
	{
		for(int j=1<<i;j<=n;j++)
		{
			suf[j][i]=(suf[j][i-1]+suf[j-(1<<(i-1))][i-1])%10;
			ans[j][i]=ans[j][i-1]+ans[j-(1<<(i-1))][i-1]+(suf[j][i-1]+suf[j-(1<<(i-1))][i-1])/10;
		}
	}
	int q=read();
	int l,r;
	for(int i=1;i<=q;i++)
	{
		l=read(),r=read();
		int dif=r-l+1;
		for(int j=0;j<=24;j++)
		{
			if((1<<j)==dif)
			{
				printf("%I64d\n",ans[r][j]);
				break;
			}
		}
	}
	return 0;
}

//affec6chtvrte5rtesrg