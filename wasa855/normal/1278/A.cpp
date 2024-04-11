#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 105
int cnt[30];
int c2[N][30];
void work()
{
	string p,s;
	cin>>p>>s;
	int n=p.length(),m=s.length();
	p=' '+p,s=' '+s;
	for(int i=0;i<26;i++) cnt[i]=0;
	for(int i=1;i<=n;i++) cnt[p[i]-'a']++;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<26;j++) c2[i][j]=c2[i-1][j];
		c2[i][s[i]-'a']++;
	}
	for(int i=n;i<=m;i++)
	{
		bool ok=1;
		for(int j=0;j<26;j++)
		{
			if(cnt[j]!=c2[i][j]-c2[i-n][j]) ok=0;
		}
		if(ok)
		{
			cout<<"YES\n";
			return ;
		}
	}
	cout<<"NO\n";
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}