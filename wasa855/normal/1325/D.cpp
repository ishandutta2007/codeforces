#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define INF 0x3fffffff
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}

signed main()
{
	int n,m;
	cin>>n>>m;
	if(m<n)
	{
		cout<<"-1\n";
		return 0;
	}
	m-=n;
	if(m&1)
	{
		cout<<"-1\n";
		return 0;
	}
	if(n==0)
	{
		if(m==0) cout<<"0\n";
		else printf("2\n%lld %lld\n",m/2,m/2);
	}
	else
	{
		if(m==0) printf("1\n%lld\n",n);
		else
		{
			if(n&(m/2)) printf("3\n%lld %lld %lld\n",n,m/2,m/2);
			else printf("2\n%lld %lld\n",n+m/2,m/2);
		}
	}
	return 0;
}