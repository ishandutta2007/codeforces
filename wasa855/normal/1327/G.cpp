#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
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
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
#define N 1005
#define M 400005
int ch[N][14],fail[N],w[N],cnt,n;
int to[N][N],c[N][N];
char s[M];
void insert(string s,int v)
{
	int u=0;
	for(int i=0;i<(int)s.length();i++)
	{
		int x=s[i]-'a';
		if(!ch[u][x]) ch[u][x]=++cnt;
		u=ch[u][x];
	}
	w[u]+=v;
}
void getfail()
{
	queue<int> q;
	for(int i=0;i<14;i++)
	{
		if(ch[0][i]) q.push(ch[0][i]);
	}
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		w[u]+=w[fail[u]];
		for(int i=0;i<14;i++)
		{
			if(!ch[u][i]) ch[u][i]=ch[fail[u]][i];
			else fail[ch[u][i]]=ch[fail[u]][i],q.push(ch[u][i]);
		}
	}
}
pii work(int u,string s)
{
	int res=0;
	for(int i=0;i<(int)s.length();i++)
	{
		u=ch[u][s[i]-'a'];
		res+=w[u];
	}
	return mp(u,res);
}
#define NN 20005
int f[NN][N];
int ct(int u){return __builtin_popcount(u);}
signed main()
{
	Fast_IO;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s; int v;
		cin>>s>>v;
		insert(s,v);
	}
	getfail();
	cin>>(s+1);
	int m=strlen(s+1);
	int k=0;
	string tmp;
	for(int i=1;i<=m;i++)
	{
		if(s[i]=='?')
		{
			for(int j=0;j<=cnt;j++)
			{
				pii R=work(j,tmp);
				to[j][k]=R.fir,c[j][k]=R.sec;
				// printf("%d %d %d %d\n",j,k,to[j][k],c[j][k]);
			}
			k++;
			tmp="";
		}
		else tmp+=s[i];
		if(i==m)
		{
			for(int j=0;j<=cnt;j++)
			{
				pii R=work(j,tmp);
				to[j][k]=R.fir,c[j][k]=R.sec;
				// printf("%d %d %d %d\n",j,k,to[j][k],c[j][k]);
			}
		}
	}
	int lim=1<<14;
	for(int i=0;i<lim;i++)
	{
		for(int j=0;j<=cnt;j++) f[i][j]=-INF;
	}
	f[0][to[0][0]]=c[0][0];
	int ans=-INF;
	for(int i=0;i<lim;i++)
	{
		int qaq=ct(i);
		if(qaq==k)
		{
			for(int j=0;j<=cnt;j++)
			{
				if(f[i][j]>ans) ans=f[i][j];
			}
		}
		if(qaq>=k) continue;
		for(int j=0;j<=cnt;j++)
		{
			for(int d=0;d<14;d++)
			{
				if(i&(1<<d)) continue;
				int v=ch[j][d];
				int R=f[i][j]+c[v][qaq+1]+w[v],QaQ=to[v][qaq+1],Q=i|(1<<d);
				if(f[Q][QaQ]<R) f[Q][QaQ]=R;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}