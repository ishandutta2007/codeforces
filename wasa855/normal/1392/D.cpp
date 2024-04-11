#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
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
#define N 400005
char s[N];
int f[N],n;
int solve(char s[])
{
	for(int i=1;i<=n;i++) f[i]=inf;
	for(int i=1;i<=n;i++)
	{
		if(i>=4) f[i]=min(f[i],f[i-4]+(s[i-3]=='L')+(s[i-2]=='L')+(s[i-1]=='R')+(s[i]=='R'));
		if(i>=3) f[i]=min(f[i],f[i-3]+(s[i-2]=='L')+(s[i-1]=='L')+(s[i]=='R'));
		if(i>=3) f[i]=min(f[i],f[i-3]+(s[i-2]=='L')+(s[i-1]=='R')+(s[i]=='R'));
		if(i>=2) f[i]=min(f[i],f[i-2]+(s[i-1]=='L')+(s[i]=='R'));
	}
	return f[n];
}
void work()
{
	n=read();
	scanf("%s",s+1);
	s[n+1]=s[1],s[n+2]=s[2],s[n+3]=s[3];
	cout<<min(solve(s),min(solve(s+1),min(solve(s+2),solve(s+3))))<<endl;
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}