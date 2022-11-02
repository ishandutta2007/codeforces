#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
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
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=500005,mod=1e9+7,inf=1e9;
queue<int> q;
vector<PI> v[N];
int ycl[10],len[N],dis[N];
ll ans[N];
void dfs(vector<int> dq){
	vector<int> to[10];
	for(auto i:dq){
		for(auto j:v[i])to[j.fi].pb(j.se);
	}
	For(i,0,9){
		vector<int> zs;
		for(auto j:to[i])if(ans[j]==-1&&dis[j]==dis[dq[0]]+1){ans[j]=(ans[dq[0]]*10+i)%mod; zs.pb(j);}
		if(zs.size())dfs(zs);
	}
}
int main(){
	int n=read(),m=read(),cnt=n;
	For(i,1,m){
		int x=read(),y=read();
		if(i<10){v[x].pb(mp(i,y)); v[y].pb(mp(i,x));}
		else{
			int id,lst=++cnt,fir=lst;
			for(id=i/10;id>=10;id/=10){v[++cnt].pb(mp(id%10,lst)); lst=cnt;}
			v[x].pb(mp(id,lst));
			v[y].pb(mp(id,lst));
			v[fir].pb(mp(i%10,x));
			v[fir].pb(mp(i%10,y));
		}
	}
	For(i,1,cnt)sort(v[i].begin(),v[i].end());
	q.push(1);
	For(i,2,cnt)dis[i]=1e9;
	while(q.size()){
		int t=q.front(); q.pop();
		for(auto i:v[t])if(dis[i.se]==inf){
			dis[i.se]=dis[t]+1; q.push(i.se);
		}
	}
	memset(ans,-1,sizeof(ans)); ans[1]=0; 
	vector<int> dq(1); dq[0]=1;
	dfs(dq);
	For(i,2,n)writeln(ans[i]);
}