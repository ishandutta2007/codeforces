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
#define N 55
string s[N];
int siz[N];
void work()
{
	int n=read();
	for(int i=1;i<=n;i++) cin>>s[i];
	int s0=0,s1=0,ji=0;
	for(int i=1;i<=n;i++)
	{
		int ls=s[i].length();
		siz[i]=ls/2;
		if(ls&1) ji++;
		for(int j=0;j<ls;j++)
		{
			if(s[i][j]=='0') s0++;
			else s1++;
		}
	}
	sort(siz+1,siz+n+1);
	int tot=s0/2+s1/2,ans=0;
	for(int i=1;i<=n;i++)
	{
		if(tot>=siz[i]) ans++;
		else break;
		tot-=siz[i];
	}
	cout<<ans<<endl;
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