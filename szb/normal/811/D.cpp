#include<cstdio>
#include<algorithm>
#include<cmath>
#include<memory.h>
#include<map>
#define ll int
#define maxn 10100
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
using namespace std;
inline ll read(){ll x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline void write(ll x){if (x<0) putchar('-'),x=-x;if (x>=10) write(x/10);putchar(x%10+'0');  }
inline void writeln(ll x){  write(x); puts("");}
ll n,m,mp[111][111],ex,ey,pre[111][111][2],qx[10010],qy[10010],hh[10010][2],tot;
char s[111];
bool vis[111][111];
ll a[]={0,0,-1,1};
ll b[]={-1,1,0,0};
char zyy[]={'L', 'R', 'U', 'D'};
ll get(ll x,ll y){
	For(i,0,3)	if (x==a[i]&&y==b[i])	return i;
}
void dfs(ll x,ll y){
	if (x!=1||y!=1)	dfs(pre[x][y][0],pre[x][y][1]);
	hh[++tot][0]=x;	hh[tot][1]=y;
}
int main(){
	n=read();	m=read();
	For(i,1,n){
		scanf("%s",s+1);
		For(j,1,m){
			if (s[j]=='.')	mp[i][j]=0;
			else if (s[j]=='F')	mp[ex=i][ey=j]=0;
			else mp[i][j]=1;
		}
	}ll l=0,r=1;	qx[1]=qy[1]=vis[1][1]=1;	bool flag=0;
	while(l<r){
		ll xx=qx[++l],yy=qy[l];
		For(i,0,3){
			ll xxx=xx+a[i],yyy=yy+b[i];
			if (xxx<1||xxx>n||yyy<1||yyy>m||vis[xxx][yyy]||mp[xxx][yyy])	continue;
			vis[xxx][yyy]=1;
			qx[++r]=xxx;	qy[r]=yyy;
			pre[xxx][yyy][0]=xx;	pre[xxx][yyy][1]=yy;
			if (xxx==ex&&yyy==ey){	flag=1;	break;}
		}
		if (flag)	break;
	}dfs(ex,ey);
	For(i,1,tot-1){
		ll szb=get(hh[i+1][0]-hh[i][0],hh[i+1][1]-hh[i][1]);
		printf("%c\n",zyy[szb]);	fflush(stdout);
		ll x=read(),y=read();
		if (x==hh[i][0]&&y==hh[i][1]){
			swap(a[szb^1],a[szb]);	swap(b[szb^1],b[szb]);	szb^=1;
			printf("%c\n",zyy[szb]);
			fflush(stdout);
			x=read();	y=read();
		}
	}
}