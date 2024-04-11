#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc((x%10)+'0');}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=20;
const int MAXP=256;
const int MAXM=8;
const int INF=0x3f3f3f3f;
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
int n,m,sx,sy;char s[MAXN+3][MAXN+3];
int dp[MAXN+2][MAXN+2][MAXP+3];
int px[MAXM+2],py[MAXM+2],a[MAXM+2],c1=0,c2=0;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(s[i][j]=='S') sx=i,sy=j;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(isdigit(s[i][j])){
		px[s[i][j]^48]=i;py[s[i][j]^48]=j;c1++;
	} c2=c1;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(s[i][j]=='B') px[++c2]=i,py[c2]=j;
	for(int i=1;i<=c1;i++) scanf("%d",&a[i]);
	memset(dp,63,sizeof(dp));dp[sx][sy][0]=0;
	queue<pair<pii,int> > q;q.push(mp(mp(sx,sy),0));
	while(!q.empty()){
		pair<pii,int> p=q.front();q.pop();
		int x=p.fi.fi,y=p.fi.se,msk=p.se;
//		printf("%d %d %d %d\n",x,y,msk,dp[x][y][msk]);
		for(int i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			if(nx<1||nx>n||ny<1||ny>m) continue;
			if(s[nx][ny]!='.'&&s[nx][ny]!='S') continue;
			int nmsk=msk;
			for(int j=1;j<=c2;j++) if((!(px[j]^x)&&!(i^2)||!(px[j]^nx)&&!i)&&py[j]<ny)
				nmsk^=1<<j-1;
			if(dp[nx][ny][nmsk]==INF){
				dp[nx][ny][nmsk]=dp[x][y][msk]+1;
				q.push(mp(mp(nx,ny),nmsk));
			}
		}
	}
	int ans=-INF;
	for(int i=0;i<(1<<c1);i++) if(dp[sx][sy][i]!=INF){
		int sum=0;
		for(int j=0;j<c1;j++) sum+=a[j+1]*(i>>j&1);
		chkmax(ans,sum-dp[sx][sy][i]);
	} printf("%d\n",ans);
	return 0;
}