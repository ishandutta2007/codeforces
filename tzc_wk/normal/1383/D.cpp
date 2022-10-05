#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mt make_tuple
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
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
	template<typename T> void recursive_print(T x){return (!x)?void():(recursive_print(x/10),putc(x%10^48),void());}
	template<typename T> void print(T x){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);}
	template<typename T> void print(T x,char c){print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=250;
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
int n,m,a[MAXN+5][MAXN+5],vis1[MAXN*MAXN+5],vis2[MAXN*MAXN+5];
int X=0,Y=0,b[MAXN+5][MAXN+5];queue<pii> q;
bool check(int x,int y){
	if(x<1||x>n||y<1||y>m) return 0;
	if(b[x][y]) return 0;
	int cnt=0;
	for(int i=0;i<4;i++) cnt+=(b[x+dx[i]][y+dy[i]]>0);
	return cnt==2;
}
void relax(int x,int y){
	for(int i=0;i<4;i++) if(check(x+dx[i],y+dy[i])) q.push(mp(x+dx[i],y+dy[i]));
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++){
		int mx=0;
		for(int j=1;j<=m;j++) chkmax(mx,a[i][j]);
		vis1[mx]=1;
	}
	for(int i=1;i<=m;i++){
		int mx=0;
		for(int j=1;j<=n;j++) chkmax(mx,a[j][i]);
		vis2[mx]=1;
	}
	for(int i=n*m;i;i--){
		if(vis1[i]&&vis2[i]) b[++X][++Y]=i,relax(X,Y);
		else if(vis1[i]) b[++X][Y]=i,relax(X,Y);
		else if(vis2[i]) b[X][++Y]=i,relax(X,Y);
		else{
			while(1){
				pii p=q.front();q.pop();
				if(!b[p.fi][p.se]){
					b[p.fi][p.se]=i;
					relax(p.fi,p.se);
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
		printf("%d%c",b[i][j]," \n"[j==m]);
	return 0;
}