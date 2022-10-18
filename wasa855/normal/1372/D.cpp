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
#define int long long
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
int a[N],s1[N],s2[N];
signed main()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		s1[i]=s1[i-1],s2[i]=s2[i-1];
		if(i&1) s1[i]+=a[i];
		else s2[i]+=a[i];
	}
	int ans=s1[n];
	for(int i=1;i<n;i++)
	{
		int res=0;
		if(i&1) res=s1[i]+s2[n]-s2[i];
		else res=s2[i]+s1[n]-s1[i];
		ans=max(ans,res);
	}
	cout<<ans<<endl;
	return 0;
}