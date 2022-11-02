#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
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
inline void wri(ll a){write(a); putchar(' ');}
inline void writeln(ll a){write(a); puts("");}
const int N=2005;
int n,m,R,C,x,y,dp[N*N*4],ans;
PI q[N*N*4];
int vis[N][N];
char ch[N][N];
signed main(){
	n=read(); m=read(); R=read(); C=read(); x=read(); y=read();
	for(int i=1;i<=n;i++){
		scanf("%s",ch[i]+1);
	}
	for(int i=0;i<=n+1;i++)for(int j=0;j<=m+1;j++)vis[i][j]=-1e9;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(ch[i][j]!='*')vis[i][j]=-1;
	int l=N*N*2,r=N*N*2;
	q[r]=mp(R,C); vis[R][C]=0; 
	while(l<=r){
		PI t=q[l]; int jb=dp[l]; l++;
		if(vis[t.first][t.second]<jb)continue; 
		//cout<<l<<" "<<jb<<" "<<t.first<<" "<<t.second<<" "<<vis[t.first][t.second]<<" "<<vis[2][5]<<endl;
		if(jb<=x&&t.second-C+jb<=y)ans++; 
		if(vis[t.first+1][t.second]==-1||vis[t.first+1][t.second]>jb){
			q[--l]=mp(t.first+1,t.second); dp[l]=jb; vis[t.first+1][t.second]=jb;
		}
		if(vis[t.first-1][t.second]==-1||vis[t.first-1][t.second]>jb){
			q[--l]=mp(t.first-1,t.second); dp[l]=jb; vis[t.first-1][t.second]=jb;
		}
		if(vis[t.first][t.second+1]==-1||vis[t.first][t.second+1]>jb){
			q[--l]=mp(t.first,t.second+1); dp[l]=jb; vis[t.first][t.second+1]=jb;
		}
		if(vis[t.first][t.second-1]==-1){
			q[++r]=mp(t.first,t.second-1); dp[r]=jb+1; vis[t.first][t.second-1]=jb+1;
		}
	}
	cout<<ans<<endl;
}