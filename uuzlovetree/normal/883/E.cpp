#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int n,m;
string s,a[maxn];
int has[maxn],ban[maxn];
int main()
{
	cin>>n;
	cin>>s;
	cin>>m;
	for(int i=1;i<=m;++i)cin>>a[i];
	for(int j=0;j<n;++j)has[s[j]]=1;
	for(int i=1;i<=m;++i)
	{
		for(int j=0;j<n;++j)if(a[i][j]!=s[j])
		{
			if(s[j]=='*'&&has[a[i][j]])ban[i]=1;
			if(s[j]!='*')ban[i]=1;
		}
	}
	int ans=0;
	for(char c='a';c<='z';++c)
	{
		bool ok=1;
		for(int j=0;j<n;++j)if(s[j]==c)ok=0;
		for(int i=1;i<=m;++i)if(!ban[i])
		{
			bool yes=0;
			for(int j=0;j<n;++j)if(a[i][j]==c)yes=1;
			if(!yes)ok=0;
		}
		if(ok)ans++;
	}
	cout<<ans<<endl;
}