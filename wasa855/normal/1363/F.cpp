#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 2005
char s[N],t[N];
int ss[N][26],st[N][26],f[N][N];
void work()
{
	int n=read();
	scanf("%s%s",s+1,t+1);
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<26;j++) ss[i][j]=ss[i+1][j];
		ss[i][s[i]-'a']++;
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<26;j++) st[i][j]=st[i+1][j];
		st[i][t[i]-'a']++;
	}
	// for(int i=1;i<=n;i++)
	// {
		// for(int j=0;j<26;j++) printf("%d ",ss[i][j]);
		// cout<<"\n";
	// }
	for(int i=0;i<26;i++)
	{
		if(ss[1][i]!=st[1][i]) {cout<<"-1\n"; return ;}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[i][j]=max(f[i-1][j],f[i][j-1]);
			if(s[i]==t[j])
			{
				bool ok=1;
				for(int k=0;k<26;k++) if(ss[i][k]<st[j][k]) ok=0;
				if(ok) f[i][j]=max(f[i][j],f[i-1][j-1]+1);
			}
		}
	}
	// for(int i=1;i<=n;i++)
	// {
		// for(int j=1;j<=n;j++) printf("%d ",f[i][j]);
		// cout<<"\n";
	// }
	cout<<n-f[n][n]<<endl;
	for(int i=1;i<=n;i++) for(int j=0;j<26;j++) ss[i][j]=st[i][j]=0;
}
signed main()
{
	int T=read();
	while(T--) work();
	return 0;
}