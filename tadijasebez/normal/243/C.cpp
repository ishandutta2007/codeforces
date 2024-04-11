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

const int N=2050;
const int inf=1e9+7;
vector<int> xs,ys;
char ch[N];int d[N];
int blk[N][N],was[N][N];
int mv[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int main(){
	int n=ri();
	int x=0,y=0;
	for(int i=1;i<=n;i++){
		scanf("\n%c %i",&ch[i],&d[i]);
		if(ch[i]=='L')x-=d[i],xs.pb(x);
		else if(ch[i]=='R')x+=d[i],xs.pb(x);
		else if(ch[i]=='U')y+=d[i],ys.pb(y);
		else y-=d[i],ys.pb(y);
	}
	xs.pb(-inf);xs.pb(0);xs.pb(inf);
	ys.pb(-inf);ys.pb(0);ys.pb(inf);
	sort(xs.begin(),xs.end());
	xs.erase(unique(xs.begin(),xs.end()),xs.end());
	sort(ys.begin(),ys.end());
	ys.erase(unique(ys.begin(),ys.end()),ys.end());
	x=0,y=0;
	vector<pii> X,Y;
	for(int i=0;i<xs.size();i++){
		if(i>0&&xs[i]!=xs[i-1]+1)X.pb({xs[i-1]+1,xs[i]-1});
		X.pb({xs[i],xs[i]});
		if(xs[i]==0)x=X.size()-1;
	}
	for(int i=0;i<ys.size();i++){
		if(i>0&&ys[i]!=ys[i-1]+1)Y.pb({ys[i-1]+1,ys[i]-1});
		Y.pb({ys[i],ys[i]});
		if(ys[i]==0)y=Y.size()-1;
	}
	blk[x][y]=1;
	int _x=0,_y=0;
	for(int i=1;i<=n;i++){
		if(ch[i]=='L'){
			_x-=d[i];
			while(X[x].first!=_x){
				x--;
				blk[x][y]=1;
			}
		}else if(ch[i]=='R'){
			_x+=d[i];
			while(X[x].second!=_x){
				x++;
				blk[x][y]=1;
			}
		}else if(ch[i]=='U'){
			_y+=d[i];
			while(Y[y].second!=_y){
				y++;
				blk[x][y]=1;
			}
		}else{
			_y-=d[i];
			while(Y[y].first!=_y){
				y--;
				blk[x][y]=1;
			}
		}
	}
	was[0][0]=1;
	queue<pii> q;
	q.push({0,0});
	while(q.size()){
		int x,y;
		tie(x,y)=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int nx=x+mv[i][0];
			int ny=y+mv[i][1];
			if(nx>=0&&nx<X.size()&&ny>=0&&ny<Y.size()){
				if(!blk[nx][ny]){
					if(!was[nx][ny]){
						was[nx][ny]=1;
						q.push({nx,ny});
					}
				}
			}
		}
	}
	/*for(int i=0;i<X.size();i++){
		printf("(%i %i) ",X[i].first,X[i].second);
	}
	printf("\n");
	for(int i=0;i<Y.size();i++){
		printf("(%i %i) ",Y[i].first,Y[i].second);
	}
	printf("\n");*/
	ll ans=0;
	for(int i=0;i<X.size();i++){
		for(int j=0;j<Y.size();j++){
			if(!was[i][j]){
				ans+=(ll)(X[i].second-X[i].first+1)*(Y[j].second-Y[j].first+1);
			}
			//printf("%i",blk[i][j]);
		}
		//printf("\n");
	}
	/*printf("\n");
	for(int i=0;i<X.size();i++){
		for(int j=0;j<Y.size();j++){
			printf("%i",was[i][j]);
		}
		printf("\n");
	}*/
	printf("%lld\n",ans);
	return 0;
}