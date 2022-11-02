#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
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
int n,k,dp[N][N],zs;
bool vis[N][N];
char ch[N][N];
signed main(){
	n=read(); k=read();
	for(int i=1;i<=n;i++){
		scanf("%s",ch[i]+1);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=max(dp[i-1][j],dp[i][j-1])+(ch[i][j]=='a');
		}
	}
	zs=2*n; vis[0][1]=1;
	for(int i=1;i<2*n;i++){
		if(i<=n){
			int x=i,y=1,flag=0;
			for(int j=1;j<=i;j++){
				if(i-dp[x][y]<=k){flag=1; vis[x][y]=1;}
				x--; y++;
			}
			if(!flag){
				zs=i; break;
			}
		}else{
			int x=n,y=i-n+1,flag=0;
			for(int j=1;j<=2*n-i;j++){
				if(i-dp[x][y]<=k){flag=1; vis[x][y]=1;}
				x--; y++;
			}
			if(!flag){
				zs=i; break;
			}
		}
	}
	for(int i=1;i<zs;i++)putchar('a');
	for(int i=zs;i<2*n;i++){
		if(i<=n){
			int x=i,y=1; char mn='z';
			for(int j=1;j<=i;j++){
				vis[x][y]=vis[x-1][y]||vis[x][y-1];
				if(vis[x][y])mn=min(mn,ch[x][y]);
				x--; y++;
			}
			x=i; y=1;
			for(int j=1;j<=i;j++){
				vis[x][y]&=ch[x][y]==mn; 
				x--; y++;
			}
			putchar(mn);
		}else{
			int x=n,y=i-n+1; char mn='z';
			for(int j=1;j<=2*n-i;j++){
				vis[x][y]=vis[x-1][y]||vis[x][y-1];
				if(vis[x][y])mn=min(mn,ch[x][y]);
				x--; y++;
			}
			x=n; y=i-n+1;
			for(int j=1;j<=2*n-i;j++){
				vis[x][y]&=ch[x][y]==mn;
				x--; y++;
			}
			putchar(mn);
		}
	}
}