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
#define N 2005
char s[N][N];
int ans[N][N],n;
void fix(int x,int y,int col)
{
	if((x+y)&1)
	{
		int go=min(x-1,y-1);
		x-=go,y-=go,col^=(go&1);
		if(x==1) y--;
		else x--;
	}
	int go=min(x-1,n-y);
	x-=go,y+=go,col^=(go&1);
	go=min(x-1,y-1);
	if(go) x-=go,y-=go;
	assert(x==1);
	if(ans[x][y]!=-1&&ans[x][y]!=col) cout<<"NONE\n",exit(0);
	ans[x][y]=col;
}
int getcol(int x,int y)
{
	int col=0;
	if((x+y)&1)
	{
		int go=min(x-1,y-1);
		x-=go,y-=go,col^=(go&1);
		if(x==1) y--;
		else x--;
	}
	int go=min(x-1,n-y);
	x-=go,y+=go,col^=(go&1);
	go=min(x-1,y-1);
	if(go) x-=go,y-=go;
	return col^ans[x][y];
}
signed main()
{
	memset(ans,-1,sizeof(ans));
	cin>>n;
	if(n&1) cout<<"NONE\n",exit(0);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
	{
		if(s[i][j]=='.') continue;
		fix(i,j,s[i][j]=='S');
	}
	for(int i=1;i<=n;i+=2) if(ans[1][i]==-1) cout<<"MULTIPLE\n",exit(0);
	cout<<"UNIQUE\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) printf("%c","GS"[getcol(i,j)]);
		cout<<"\n";
	}
	return 0;
}