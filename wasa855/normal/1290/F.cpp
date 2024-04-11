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
int a[5][2],f[31][21][21][21][21][2][2],n,m;
int dfs(int d,int x1,int x2,int y1,int y2,int lx,int ly)
{
	if(d>30) return !x1&&!x2&&!y1&&!y2&&!lx&&!ly;
	if(f[d][x1][x2][y1][y2][lx][ly]!=-1) return f[d][x1][x2][y1][y2][lx][ly];
	int ans=0;
	for(int i=0;i<1<<n;i++)
	{
		int tx1=x1,tx2=x2,ty1=y1,ty2=y2;
		for(int j=0;j<n;j++) if(i>>j&1)
		{
			if(a[j][0]>0) tx1+=a[j][0];
			else tx2-=a[j][0];
			if(a[j][1]>0) ty1+=a[j][1];
			else ty2-=a[j][1];
		}
		if((tx1^tx2)&1) continue;
		if((ty1^ty2)&1) continue;
		int tlx=lx,tly=ly;
		if((tx1&1)>(m>>d&1)) tlx=1;
		if((tx1&1)<(m>>d&1)) tlx=0;
		if((ty1&1)>(m>>d&1)) tly=1;
		if((ty1&1)<(m>>d&1)) tly=0;
		ans=add(ans,dfs(d+1,tx1/2,tx2/2,ty1/2,ty2/2,tlx,tly));
	}
	return f[d][x1][x2][y1][y2][lx][ly]=ans;
}
signed main()
{
	// cout<<sizeof(f)/1024.0/1024.0<<endl;
	cin>>n>>m; for(int i=0;i<n;i++) a[i][0]=read(),a[i][1]=read();
	memset(f,-1,sizeof(f));
	int ans=dfs(0,0,0,0,0,0,0);
	cout<<sub(ans,1)<<endl;
	return 0;
}