#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
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
#define N 100005
int x[N],y[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<=n;i++) x[i]=read(),y[i]=read();
	if(n&1)
	{
		cout<<"NO\n";
		return 0;
	}
	int rx=x[1]+x[n/2+1],ry=y[1]+y[n/2+1];
	for(int i=1;i<=n/2;i++)
	{
		int tx=x[i]+x[n/2+i],ty=y[i]+y[n/2+i];
		if(rx!=tx||ry!=ty)
		{
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}