#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<ll,ll>
#define poly vector<ll>
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
const int N=100005,inf=1e9;
int n,dp[N][3],res[N],nxt[N]; //1 
vector<int> v[N];
vector<PI> jj[N][2];
void dfs(int p,int fa){
	For(j,0,1)dp[p][j]=inf;
	dp[p][1]=0;
	For(i,0,v[p].size()-1)if(v[p][i]==fa){v[p].erase(v[p].begin()+i); break;}
	
	for(auto i:v[p]){
		dfs(i,p);
		int zs[2];
		PI jb[2]; 
		For(j,0,1)zs[j]=inf;
		For(p2,0,1){
			For(q2,0,1){
				int t=dp[p][p2]+dp[i][q2];
				if(p2&&q2){
					if(t+2<zs[0]){
						zs[0]=t+2; jb[0]=mp(p2,q2);
					}
				}
				else {
					if(t+(p2+q2)*2<zs[p2+q2]){
						zs[p2+q2]=t+q2*2; jb[p2+q2]=mp(p2,q2);
					}
				}
				if(p2+q2==1){
					if(zs[0]>t+2){
						//cout<<zs[0]<<" fj "<<t+2<<endl;
						zs[0]=t+2; jb[0]=mp(p2,q2);
					}
				}
			}
		}
		memcpy(dp[p],zs,sizeof(zs));
		jj[p][0].pb(jb[0]);
		jj[p][1].pb(jb[1]);
	}
	//cout<<dp[p][0]<<" "<<dp[p][1]<<endl;
}
void ae(int x,int y){
	nxt[x]=y; nxt[y]=x;
}
void ins(int x,int y,int z){
	nxt[z]=y;
	nxt[x]=z;
	
}
void solve(int p,int i,int zt){
	if(i==v[p].size())res[p]=p;
	if(!i)return;
	int t=v[p][i-1],x=jj[p][zt][i-1].fi,y=jj[p][zt][i-1].se;
	//cout<<p<<" "<<t<<" "<<x<<" "<<y<<endl;
	solve(t,v[t].size(),y);
	solve(p,i-1,x);
	if(x&&y){ae(res[p],res[t]); }
	else if(x+y!=zt){if(x==1)ins(t,nxt[t],res[p]); else ins(p,nxt[p],res[t]);}
	else if(y)res[p]=res[t];
}
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	n=read();
	For(i,1,n-1){
		int x=read(),y=read();
		v[x].pb(y); v[y].pb(x);
	}
	dfs(1,0);
	cout<<dp[1][0]<<endl;
	solve(1,v[1].size(),0);
	For(i,1,n)wri(nxt[i]);
}