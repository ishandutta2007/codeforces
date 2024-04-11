#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
#define data pair<int,pair<int,int> > 
#define mem(a) memset((a),0,sizeof(a))
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x.size()))
#define re resize
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
ll rnd(){
	ull ans=0;
	For(i,0,4)ans=ans<<15^rand();
	return ans%((ull)1<<63);
}
const int N=105,M=52;
const ull inf=(ull)1<<63;
int a[N],go[M][2],vis[M],tot=1;
vector<int> v[N];
ull dis[N][M][M],dd[M],ee[M];
int q[M],fail[M];
void buildfail(){
    int l=0,r=1; q[0]=1; fail[1]=0; go[0][1]=go[0][0]=1;
    while(l<r){
    	int now=q[l++]; vis[now]|=vis[fail[now]];
    	For(i,0,1)if(!go[now][i])go[now][i]=go[fail[now]][i];
    	else fail[q[r++]=go[now][i]]=go[fail[now]][i];
	}
}
int main(){
	#ifdef Brollan
		//freopen("1.in","r",stdin);
	#endif
	int g=read()-1,n=read(),m=read();
	For(i,1,n){
		a[i]=read();
		int k=read();
		while(k--)v[i].pb(read());
		//for(auto j:v[i])cx[i][j]=1;
	}
	For(i,1,m){
		int len=read(),p=1;
		For(j,1,len){
			int t=read();
			if(!go[p][t])go[p][t]=++tot;
			p=go[p][t];
		}
		vis[p]=1;
	}
	buildfail();
	For(i,0,g)For(j,1,tot)For(k,1,tot)dis[i][j][k]=inf;
	//priority_queue<data> q;
	For(i,0,1)For(j,1,tot)if(!vis[go[j][i]])dis[i][j][go[j][i]]=1;
	//For(i,1,tot)cout<<i<<" "<<go[i][0]<<" "<<go[i][1]<<endl;
	int f=1;
	while(f){
		f=0;
		For(i,1,n){
			For(o,1,tot)if(!vis[o]){
				For(j,1,tot)dd[j]=inf;
				dd[o]=0;
				for(auto k:v[i]){
					For(j,1,tot)ee[j]=inf;
					For(j,1,tot)if(dd[j]<inf)For(o,1,tot)ee[o]=min(ee[o],dd[j]+dis[k][j][o]);
					memcpy(dd,ee,sizeof(ee));
				}
				For(j,1,tot)if(ee[j]<dis[a[i]][o][j]){
					assert(!vis[j]);
					//if(i==3&&o==1)cout<<i<<" "<<o<<" "<<j<<" "<<ee[j]<<endl;
					dis[a[i]][o][j]=ee[j]; f=1;
				}
			}
		}
	}
	For(o,2,g){
		ull ans=inf;
		For(i,1,tot)ans=min(ans,dis[o][1][i]);
		if(ans==inf)puts("YES"); else cout<<"NO "<<ans<<endl;
	}
}