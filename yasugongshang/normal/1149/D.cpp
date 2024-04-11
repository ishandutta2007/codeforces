#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define ull unsigned long long
#define mp make_pair
#define ld long double
#define fi first
#define se second
#define PI pair<int,int>
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
const int inf=1e9,N=75;
int e[N][N],be[N],ans[N],fa[N],dq;
int dis[70<<17|2];
vector<PI> v[N];
priority_queue<PI,vector<PI>,greater<PI> > q;
#define id(x,y) ((x)<<dq|(y))
int main(){
	int n=read(),m=read(),a=read(),b=read();
	for(int i=0;i<n;i++)for(int j=0;j<i;j++)e[i][j]=e[j][i]=inf;
	for(int i=1;i<=m;i++){
		int s=read()-1,t=read()-1,w=read();
		if(w==a)e[s][t]=e[t][s]=a;
		v[s].push_back(mp(t,w)); v[t].push_back(mp(s,w));
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				e[i][j]=min(e[i][k]+e[k][j],e[i][j]);
			}
		}
	}
	memset(be,-1,sizeof(be)); memset(fa,-1,sizeof(fa));
	for(int i=0;i<n;i++)if(fa[i]==-1){
		int cnt=0;
		for(int j=i;j<n;j++)if(e[i][j]!=inf) {cnt++; fa[j]=i; }
		if(cnt>=4){
			for(int j=i;j<n;j++)if(e[i][j]!=inf)be[j]=dq; dq++;
		}
	}
	for(int i=0;i<(n<<dq);i++)dis[i]=inf; int s;
	if(be[0]==-1)s=id(0,0); else s=id(0,1<<be[0]);
//	cout<<s<<" "<<dq<<endl;
	q.push(mp(s,0)); dis[s]=0;
	while(q.size()){
		PI t=q.top(); q.pop();// cout<<t.se<<" "<<dis[t.fi]<<endl; 
		if(dis[t.fi]<t.se)continue;
		int x=t.fi>>dq,y=t.fi&((1<<dq)-1);// cout<<x<<" "<<y<<" "<<v[x].size()<<" "<<be[1]<<endl;
		for(auto i:v[x])if(i.se==a||(fa[i.fi]!=fa[x]&&(be[i.fi]==-1||(y>>be[i.fi]&1)==0))){
			//if(i.se==b)cout<<fa[i.fi]<<" "<<fa[x]<<endl;
			int Y=y; if(be[i.fi]!=-1)Y|=1<<be[i.fi];// cout<<i.fi<<" "<<Y<<" "<<dis[id(i.fi,Y)]<<endl;
			if(dis[id(i.fi,Y)]>t.se+i.se){
				dis[id(i.fi,Y)]=t.se+i.se;
				q.push(mp(id(i.fi,Y),t.se+i.se));
			}
		}
	}
	for(int i=0;i<n;i++)ans[i]=inf;
	for(int i=0;i<(n<<dq);i++)ans[i>>dq]=min(ans[i>>dq],dis[i]);
	for(int i=0;i<n;i++)wri(ans[i]);
}