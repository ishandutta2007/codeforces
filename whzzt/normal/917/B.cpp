#include<bits/stdc++.h>

#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-funroll-loops")
#pragma GCC target("avx,sse4")

#define mms(a,n) memset(a,0,sizeof((a)[0])*(n))
#define mmp(a,b,n) memcpy(a,b,sizeof((b)[0])*(n))
#define lowbit(x) ((x)&-(x))
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define fo(i,l,r) for(register int i=l,_lim_=r;i<=_lim_;i++)
#define fd(i,r,l) for(register int i=r,_lim_=l;i>=_lim_;i--)
#define fos(i,l,r,d) for(register int i=l,_lim_=r;i<=r;i+=d)
#define fol(i,l,r) for(register ll i=l,_lim_=r;i<=_lim_;i++)
#define fdl(i,r,l) for(register ll i=r,_lim_=l;i>=_lim_;i--)
#define fosl(i,l,r,d) for(register ll i=l,_lim_=r;i<=r;i+=d)
#define Clear(a) memset(a,0,sizeof(a))
#define Copy(a,b) memcpy(a,b,sizeof(b))
#define ALL(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())

using namespace std;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ldb;
typedef double db;
typedef pair<int,int> pi;
typedef vector<int> VI;
typedef vector<VI> VII;

const int N=105,M=30;

int n,m;
bool dp[N][N][M];
bool vi[N][N][M];
vector<int>e[N][M];

bool play(int u,int v,int c){
	if(c>=26)return false;
	if(vi[u][v][c])return dp[u][v][c];
	vi[u][v][c]=true;
	fo(i,c,25)for(int x:e[u][i])if(!play(v,x,i))return dp[u][v][c]=true;
	return dp[u][v][c]=false;
}

int main(){
	scanf("%d%d",&n,&m);
	fo(i,1,m){
		int u,v;char s[5];
		scanf("%d%d%s",&u,&v,s);
		e[u][*s-'a'].pb(v);
	}
	fo(i,1,n){
		fo(j,1,n)if(play(i,j,0))putchar('A');else putchar('B');
		putchar('\n');
	}
	return 0;
}