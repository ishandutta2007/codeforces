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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
inline int add(int x,int y) {return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z) {return add(add(x,y),z);}
inline int sub(int x,int y) {return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y) {return 1LL*x*y%mod;}
inline int mul(int x,int y,int z) {return mul(mul(x,y),z);}
int qpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=mul(ans,x);
		x=mul(x,x);
		y>>=1;
	}
	return ans;
}
int Inv(int x){return qpow(x,mod-2);}
#define N 1005
int c[N],ans[N],m,n;
#define A(x) (n+n-x)
#define B(x) (n-x)
signed main()
{
	cin>>m; for(int i=1;i<=m;i++) c[i]=read(),n+=c[i];
	if(m==1) {cout<<"0\n"; return 0;}
	int a=1,b=1,sum=0,ans=0,cur=1;
	sort(c+1,c+m+1);
	for(int i=1;i<=m;i++)
	{
		while(cur<c[i])
		{
			a=mul(a,A(cur)),b=mul(b,B(cur));
			sum=add(mul(sum,B(cur)),a);
			cur++;
		}
		ans=add(ans,1,mul(sum,Inv(b)));
	}
	while(cur<n)
	{
		a=mul(a,A(cur)),b=mul(b,B(cur));
		sum=add(mul(sum,B(cur)),a);
		cur++;
	}
	ans=sub(ans,mul(sum,Inv(b))),ans=sub(ans,1);
	ans=mul(ans,mod-2);
	cout<<ans<<endl;
	return 0;
}