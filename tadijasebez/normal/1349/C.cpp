#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define mt make_tuple
#define ldb double
#define pii pair<int,int>
#define pll pair<ll,ll>
template<typename T>void ckmn(T &a,T b){a=min(a,b);}
template<typename T>void ckmx(T &a,T b){a=max(a,b);}
int ri(){int x;scanf("%i",&x);return x;}
void rd(){}
template<typename...T>void rd(int &x,T&...args){scanf("%i",&x);rd(args...);}
template<typename...T>void rd(ll &x,T&...args){scanf("%lld",&x);rd(args...);}
template<typename...T>void rd(ldb &x,T&...args){scanf("%lf",&x);rd(args...);}
template<typename...T>void rd(pii &x,T&...args){scanf("%i %i",&x.first,&x.second);rd(args...);}
const int N=1005;
const int inf=1e9+7;
char s[N][N];
bool was[N][N];
int mv[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int cnt,dist[N][N];
void DFS(int x,int y){
	was[x][y]=1;
	cnt++;
	for(int i=0;i<4;i++){
		int X=x+mv[i][0];
		int Y=y+mv[i][1];
		if(s[x][y]==s[X][Y] && !was[X][Y])DFS(X,Y);
	}
}
int main(){
	int n,m,t;rd(n,m,t);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	queue<int> q;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		if(was[i][j])dist[i][j]=0,q.push(i*N+j);
		else{
			cnt=0;
			DFS(i,j);
			if(cnt>1)dist[i][j]=0,q.push(i*N+j);
			else dist[i][j]=inf;
		}
	}
	while(q.size()){
		int x,y;tie(x,y)=mp(q.front()/N,q.front()%N);
		q.pop();
		for(int i=0;i<4;i++){
			int X=x+mv[i][0];
			int Y=y+mv[i][1];
			if(dist[X][Y]>dist[x][y]+1){
				dist[X][Y]=dist[x][y]+1;
				q.push(X*N+Y);
			}
		}
	}
	while(t--){
		int i,j;ll p;
		rd(i,j);rd(p);
		if(dist[i][j]==inf)printf("%c\n",s[i][j]);
		else{
			if(dist[i][j]<=p){
				int o=s[i][j]-'0';
				if((p-dist[i][j])%2==1)o^=1;
				printf("%i\n",o);
			}else{
				printf("%c\n",s[i][j]);
			}
		}
	}
	return 0;
}