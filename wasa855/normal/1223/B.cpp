#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
bool vis[1005];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	string s,t;
	int T=read();
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		cin>>s>>t;
		int n=s.length();
		for(int i=0;i<n;i++) vis[s[i]]=1;
		bool ok=0;
		for(int i=0;i<n;i++) if(vis[t[i]]) ok=1;
		if(ok) cout<<"YES\n";
		else cout<<"NO\n";
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}