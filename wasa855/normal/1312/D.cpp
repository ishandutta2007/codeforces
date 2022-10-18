#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
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
#define N 200005
int fac[N],inv[N],pw[N];
int C(int x,int y)
{
	return mul(fac[x],mul(inv[y],inv[x-y]));
}
signed main()
{
	int n,m;
	cin>>n>>m;
	fac[0]=1; for(int i=1;i<N;i++) fac[i]=mul(fac[i-1],i);
	inv[0]=inv[1]=1; for(int i=2;i<N;i++) inv[i]=mul(mod-mod/i,inv[mod%i]);
	for(int i=1;i<N;i++) inv[i]=mul(inv[i],inv[i-1]);
	pw[0]=1; for(int i=1;i<N;i++) pw[i]=mul(pw[i-1],2);
	if(n==2)
	{
		cout<<"0\n";
		return 0;
	}
	int ans=0;
	for(int i=n-1;i<=m;i++)
	{
		ans=add(ans,mul(C(i-1,n-2),mul(pw[n-3],n-2)));
	}
	cout<<ans<<endl;
	return 0;
}