#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<int>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
const int N=2005;
const ll inf=1e18;
int n,m,w[N],c[N][N];
ll dp[N][N][2],s[N][N],X[N],Y[N],p[N],q[N];
vector<PI> v[N];
void solve(int s,ll* dis){
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
	For(i,1,n)dis[i]=inf;
	dis[s]=0;
	q.push(mp(0,s));
	while(q.size()){
		pair<ll,int> t=q.top(); q.pop(); if(t.fi>dis[t.se])continue;
		for(auto i:v[t.se])if(dis[i.fi]>t.fi+i.se){
			dis[i.fi]=t.fi+i.se;//cout<<t.fi<<" "<<i.se<<" "<<dis[i.fi]<<" "<<t.fi+t.se<<endl;
			q.push(mp(dis[i.fi],i.fi));
		}
	}
	//For(i,1,n)wri(dis[i]); puts("");
}
int main(){
	n=read(),m=read();
	int S=read(),T=read();
	For(i,1,n)w[i]=read();
	For(i,1,m){
		int x=read(),y=read(),z=read();
		v[x].pb(mp(y,z)); v[y].pb(mp(x,z));
	}
	solve(S,X);
	solve(T,Y);
	For(i,1,n){p[i]=X[i]; q[i]=Y[i];}
	sort(p+1,p+n+1); int P=unique(p+1,p+n+1)-p-1;
	sort(q+1,q+n+1); int Q=unique(q+1,q+n+1)-q-1;
	For(i,1,n){
		int x=lower_bound(p+1,p+P+1,X[i])-p,y=lower_bound(q+1,q+Q+1,Y[i])-q;
		s[x][0]+=w[i]; s[0][y]+=w[i]; s[x][y]-=w[i];
		c[x][0]++; c[0][y]++; c[x][y]--;
	}
	For(i,0,P)For(j,0,Q){
		if(i){s[i][j]+=s[i-1][j];c[i][j]+=c[i-1][j];}
		if(j){s[i][j]+=s[i][j-1];c[i][j]+=c[i][j-1];}
		if(i&&j){s[i][j]-=s[i-1][j-1];c[i][j]-=c[i-1][j-1];}
	}
	Rep(i,P-1,0)Rep(j,Q-1,0){
		if(c[i+1][j]!=c[i][j]){
			dp[i][j][0]=max(dp[i+1][j][0],-dp[i+1][j][1])+s[i+1][j]-s[i][j];
		}else{
			dp[i][j][0]=dp[i+1][j][0];
		}
		if(c[i][j+1]!=c[i][j]){
			dp[i][j][1]=max(dp[i][j+1][1],-dp[i][j+1][0])+s[i][j+1]-s[i][j];
		}else{
			dp[i][j][1]=dp[i][j+1][1];
		}
	}
	ll ans=dp[0][0][0];
	puts(ans>0?"Break a heart":(ans<0?"Cry":"Flowers"));
}
/*
4 5
1 4
3 -8 -9 -6 
2 1 7
2 4 2
3 1 4
3 4 6
1 4 9

*/