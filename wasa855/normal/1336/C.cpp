#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
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
#define N 3005
char s[N],t[N];
int f[N][N];
signed main()
{
	scanf("%s%s",s+1,t+1);
	int n=strlen(s+1),m=strlen(t+1);
	for(int i=1;i<=m;i++)
	{
		if(s[1]==t[i]) f[i][i]=2;
	}
	for(int i=m+1;i<=n;i++) f[i][i]=2;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i+k-1<=n;i++)
		{
			int j=i+k-1;
			if(j>m||s[k]==t[j]) f[i][j]=add(f[i][j],f[i][j-1]);
			if(i>m||s[k]==t[i]) f[i][j]=add(f[i][j],f[i+1][j]);
		}
	}
	int ans=0;
	for(int i=m;i<=n;i++) ans=add(ans,f[1][i]);
	cout<<ans<<endl;
	return 0;
}