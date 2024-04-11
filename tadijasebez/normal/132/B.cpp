#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ldb double
template<typename T>void ckmn(T&a,T b){a=min(a,b);}
template<typename T>void ckmx(T&a,T b){a=max(a,b);}
void rd(int&x){scanf("%i",&x);}
void rd(ll&x){scanf("%lld",&x);}
void rd(char*x){scanf("%s",x);}
void rd(ldb&x){scanf("%lf",&x);}
void rd(string&x){scanf("%s",&x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&i:x)rd(i);}
template<typename T,typename...A>void rd(T&x,A&...args){rd(x);rd(args...);}
template<typename T>void rd(){T x;rd(x);return x;}
int ri(){int x;rd(x);return x;}
template<typename T>vector<T> rv(int n){vector<T> x(n);rd(x);return x;}
template<typename T>void ra(T a[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]);}
template<typename T1,typename T2>void ra(T1 a[],T2 b[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]);}
template<typename T1,typename T2,typename T3>void ra(T1 a[],T2 b[],T3 c[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]),rd(c[st+i]);}
void re(vector<int> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){rd(u,v);E[u].pb(v);if(!dir)E[v].pb(u);}}
template<typename T>void re(vector<pair<int,T>> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){T w;rd(u,v,w);E[u].pb({v,w});if(!dir)E[v].pb({u,w});}}

const int M=55;
const int N=M*M;
char s[M][M];
int go[N][8],idx[M][M],mv[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int mxx[N],mnx[N],mxy[N],mny[N],csz;
void DFS(int x,int y,int cmp){
	idx[x][y]=cmp;
	if(mnx[cmp]==0||mnx[cmp]>x)mnx[cmp]=x;
	mxx[cmp]=max(mxx[cmp],x);
	if(mny[cmp]==0||mny[cmp]>y)mny[cmp]=y;
	mxy[cmp]=max(mxy[cmp],y);
	for(int i=0;i<4;i++){
		int nx=x+mv[i][0];
		int ny=y+mv[i][1];
		if(!idx[nx][ny]&&s[nx][ny]==s[x][y])
			DFS(nx,ny,cmp);
	}
}
bool was[N][8];
int main(){
	int m,n;rd(m,n);
	for(int i=1;i<=m;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=m;i++){
		int k=strlen(s[i]+1);
		for(int j=1;j<=k;j++){
			if(!idx[i][j]&&s[i][j]!='0'){
				csz++;
				DFS(i,j,csz);
				//printf("%i %i %i %i\n",mnx[csz],mny[csz],mxx[csz],mxy[csz]);
			}
		}
	}
	for(int i=1;i<=csz;i++){
		go[i][0]=idx[mnx[i]][mxy[i]+1];
		go[i][1]=idx[mxx[i]][mxy[i]+1];
		go[i][2]=idx[mxx[i]+1][mxy[i]];
		go[i][3]=idx[mxx[i]+1][mny[i]];
		go[i][4]=idx[mxx[i]][mny[i]-1];
		go[i][5]=idx[mnx[i]][mny[i]-1];
		go[i][6]=idx[mnx[i]-1][mny[i]];
		go[i][7]=idx[mnx[i]-1][mxy[i]];
	}
	pii now={idx[1][1],0};
	bool w=0;int cyc=0;
	while(n){
		/*if(!w&&was[now.first][now.second]){
			w=1;
			n%=cyc;
			if(n==0)break;
		}*/
		//cyc++;
		//was[now.first][now.second]=1;
		if(go[now.first][now.second])now.first=go[now.first][now.second];
		else now.second=(now.second+1)%8;
		n--;
	}
	printf("%c\n",s[mnx[now.first]][mny[now.first]]);
	return 0;
}