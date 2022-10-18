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
#define N 105
int C2(int x) {return x*(x-1)/2;}
int ok[N][N*N],fa[N][N*N],las[N][N*N],op[N][N*N];
void init()
{
	ok[1][1]=1; int n=100;
	for(int i=2;i<=n;i++)
	{
		for(int j=i;j<=C2(i+1);j++)
		{
			for(int k=1;k<i&&!ok[i][j];k++)
			{
				if(i-k>=3&&j-(i-k+1)>=0&&ok[k][j-(i-k+1)])
				{
					ok[i][j]=1,fa[i][j]=k,las[i][j]=j-(i-k+1),op[i][j]=0;
				}
				if(j-C2(i-k+2)+1>=0&&ok[k][j-C2(i-k+2)+1])
				{
					ok[i][j]=1,fa[i][j]=k,las[i][j]=j-C2(i-k+2)+1,op[i][j]=1;
				}
			}
		}
	}
	// printf("%d - %d\n",fa[4][10],op[4][10]);
}
vector<int> solve(int n,int k)
{
	if(n==1) return {1};
	if(op[n][k]==0)
	{
		vector<int> res=solve(fa[n][k],las[n][k]);
		for(int &i:res) i++;
		int go=n-fa[n][k];
		for(int i=3;i<=go;i+=2) res.pb(fa[n][k]+i);
		res.pb(1);
		for(int i=2;i<=go;i+=2) res.pb(fa[n][k]+i);
		if(go!=3) swap(res[n-1],res[n-2]);
		return res;
	}
	else
	{
		vector<int> res=solve(fa[n][k],las[n][k]);
		if(res.back()==fa[n][k])
		{
			for(int i=0;i<(int)res.size();i++) res[i]=fa[n][k]-res[i]+1;
		}
		int go=n-fa[n][k];
		for(int i=1;i<=go;i++) res.pb(fa[n][k]+i);
		return res;
	}
}
void work()
{
	int n=read(),k=read();
	if(!ok[n][k]) {puts("NO"); return ;}
	puts("YES");
	vector<int> ans=solve(n,k);
	print(ans);
}
signed main()
{
	init();
	int T=read(); while(T--) work();
	return 0;
}