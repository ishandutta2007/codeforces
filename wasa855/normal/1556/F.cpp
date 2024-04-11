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
#define mod 1000000007
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
#define N 14
int prd[N][1<<N],n,a[N],p[N][N],f[1<<N];
int get(int v)
{
	memset(f,0,sizeof(f));
	f[1<<v]=1;
	for(int i=1;i<1<<n;i++)
	{
		if(!(i>>v&1)) continue;
		if(i==(1<<v)) continue;
		f[i]=1;
		for(int j=i&(i-1);j!=0;j=(j-1)&i)
		{
			int tmp=1;
			for(int k=0;k<n;k++)
			{
				if((i^j)>>k&1) tmp=mul(tmp,prd[k][j]);
			}
			f[i]=sub(f[i],mul(f[j],tmp));
		}
	}
	return f[(1<<n)-1];
}
signed main()
{
	cin>>n; for(int i=0;i<n;i++) a[i]=read();
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) p[i][j]=mul(a[i],Inv(a[i]+a[j]));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<1<<n;j++)
		{
			prd[i][j]=1;
			for(int k=0;k<n;k++) if(j>>k&1) prd[i][j]=mul(prd[i][j],p[i][k]);
		}
	}
	int ans=0;
	for(int i=0;i<n;i++) ans=add(ans,get(i));
	cout<<ans<<endl;
	return 0;
}