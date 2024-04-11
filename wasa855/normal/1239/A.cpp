#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
#define mod 1000000007
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 100005
int f[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,m;
	cin>>n>>m;
	f[0]=1,f[1]=1;
	for(int i=2;i<=max(n,m);i++)
	{
		f[i]=(f[i-1]+f[i-2])%mod;
	}
	printf("%lld\n",(f[n]+f[m]-1)*2%mod);
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}