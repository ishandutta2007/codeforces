#include<bits/stdc++.h>
using namespace std;
const int max_n=500+5;
const int max_m=500+5;
char s[max_n][max_m];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			scanf("%s",s[i]+1);
		bool flag=false;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				if(i<n&&s[i][j]=='0'&&s[i+1][j]=='0')
					flag=true;
				if(j<m&&s[i][j]=='0'&&s[i][j+1]=='0')
					flag=true;
			}
		for(int i=1;i<n;++i)
			for(int j=1;j<m;++j)
			{
				if(s[i][j]=='0'&&s[i+1][j+1]=='0')
					flag=true;
			}
		for(int i=1;i<n;++i)
			for(int j=2;j<=m;++j)
			{
				if(s[i][j]=='0'&&s[i+1][j-1]=='0')
					flag=true;
			}
		if(flag)
		{
			int ans=0;
			for(int i=1;i<=n;++i)
				for(int j=1;j<=m;++j)
					ans+=s[i][j]^'0';
			printf("%d\n",ans);
			continue;
		}
		int cnt=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				cnt+=s[i][j]^'0';
		if(cnt==n*m)
			printf("%d\n",cnt-2);
		else
			printf("%d\n",max(cnt-1,0));
	}
	return 0;
}