#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<memory.h>
#include<algorithm>
#define ll int
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define F first
#define S second
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll maxn=1000010;
struct data{	ll id,l,r;	};
struct dt{	ll x,v;	};
vector<data>g[maxn][2];
ll n,m,ST[maxn][2];
bool operator < (data a,data b){	return a.l<b.l;	}
bool operator < (dt a,dt b){	return a.v>b.v;	}
priority_queue<dt>Q;
ll dij(){
	Q.push((dt){1,0});
	while(!Q.empty()){
		ll x=Q.top().x,now=Q.top().v,c=now&1,st=now,in;	Q.pop();
//		printf("%lld %lld\n",x,now);
		if (x==n)	return now;
		for(ll i=ST[x][c];i<g[x][c].size();i++){
			data to=g[x][c][i];
			if (to.l>now)	break;
			ST[x][c]=i+1;
			if (to.r<st)	continue;
			now=max(now,to.r);
			now-=now-c&1;
			in=max(st,to.l);
			in+=in-c&1;
			if ((in<to.r)&&(in>=to.l))	Q.push((dt){to.id,in+1});
		}
	}return -1;
}
int main(){
//	freopen("a.in","r",stdin);
	n=read();	m=read();
	For(i,1,m){
		ll x=read(),y=read(),l=read(),r=read();
		g[x][0].push_back((data){y,l,r});
		g[y][0].push_back((data){x,l,r});
		g[x][1].push_back((data){y,l,r});
		g[y][1].push_back((data){x,l,r});
	}
	For(i,1,n)	For(j,0,1)	sort(g[i][j].begin(),g[i][j].end());
	writeln(dij());
}
/*
5 6
1 2 0 1
2 5 2 3
2 5 0 1
1 3 0 1
3 4 1 2
4 5 2 3
*/