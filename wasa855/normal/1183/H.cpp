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
#define N 105
int f[N][N][27],s[N][N];
char t[N];
signed main()
{
	int n,k;
	cin>>n>>k;
	cin>>t+1;
	for(int i=1;i<=n;i++)
	{
		f[i][1][t[i]-'a']=1;
		for(int j=1;j<=i;j++)
		{
			for(int c=0;c<26;c++)
			{
				if(t[i]-'a'==c) f[i][j][c]+=s[i-1][j-1];
				else f[i][j][c]+=f[i-1][j][c];
				if(f[i][j][c]>k) f[i][j][c]=k;
				s[i][j]+=f[i][j][c];
			}
			if(s[i][j]>k) s[i][j]=k;
		}
	}
	s[n][0]=1;
	int ans=0;
	for(int i=n;i>=0;i--)
	{
		if(s[n][i]>k)
		{
			ans+=k*(n-i);
			k=0;
			break;
		}
		ans+=s[n][i]*(n-i);
		k-=s[n][i];
	}
	if(k) cout<<"-1\n";
	else cout<<ans<<endl;
	return 0;
}