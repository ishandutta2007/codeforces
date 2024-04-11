#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define INF 0x3fffffff
#define ll long long
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
#define N 1005
int a[N];
void work()
{
	int n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	
	for(int i=1;i<n;i++)
	{
		if(a[i]%2!=a[i+1]%2)
		{
			cout<<"NO\n";
			return ;
		}
	}
	cout<<"YES\n";
	
}
signed main()
{
	int T=read();
	while(T--) work();
	return 0;
}

//
//