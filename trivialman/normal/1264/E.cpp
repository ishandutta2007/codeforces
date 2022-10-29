#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 1e9+7;
const int INF = 1e9;
const int N = 1310, M = 2e4;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct edge{
	int to,nxt;
	int w,c;
}e[M];

int n, m, x, y, a[55][55];
int S, T, tot=1, head[N], d[N], path[N];
bool v[N];

void add(int x, int y, int w, int c){
	e[++tot]={y,head[x],w,c}, head[x]=tot;
	e[++tot]={x,head[y],0,c}, head[y]=tot;
}

bool spfa(){
	rep(i,0,N-1) d[i]=INF;
	memset(v,0,sizeof v);
	queue<int> Q;
	d[S] = 0, Q.push(S), v[S]=1;
	int i;
	
	while(!Q.empty()){
		x = Q.front(), Q.pop(), v[x]=0;
		for(i=head[x];i;i=e[i].nxt)
			if(e[i].w && d[y=e[i].to]>d[x]+e[i].c){
				d[y] = d[x]+e[i].c, path[y]=i;
				if(!v[y]) Q.push(y), v[y]=1;
			}
	}
	if(d[T]==INF) return false;
	
	for(y=T;y!=S;y=x){
		i=path[y], x=e[i^1].to;
		--e[i].w, ++e[i^1].w;
	}
	return true;
}

int calc(int x,int y){
	if(x>y) swap(x,y);
	return (n-1+n-x+1)*(x-1)/2+y-x;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>n>>m;
	S = 0, T = n*(n+1)/2+1;
	rep(i,1,n*(n-1)/2) add(S,i,1,0);
	rep(i,1,m){
		cin>>x>>y;
		a[x][y] = 1;
		add(calc(x,y),n*(n-1)/2+x,1,0);
	}
	rep(x,1,n) rep(y,x+1,n) if(!a[x][y] && !a[y][x]){
		int z = calc(x,y);
		add(z,n*(n-1)/2+x,1,0);
		add(z,n*(n-1)/2+y,1,0);
	}
	rep(i,1,n) rep(j,1,n) add(n*(n-1)/2+i,T,1,j*2-1);
	while(spfa());
	
	rep(x,1,n) rep(y,x+1,n) if(!a[x][y] && !a[y][x]){
		int z = calc(x,y), q;
		for(int i=head[z];i;i=e[i].nxt) 
			if( (q=e[i].to)>=T-n-1 && q<T && !e[i].w){
				q -= (T-n-1); a[q][x+y-q] = 1; break;
			}
	}
	rep(x,1,n){
		rep(y,1,n) cout<<a[x][y];
		cout<<endl;
	}
	return 0;
}