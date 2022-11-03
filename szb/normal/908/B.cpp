#include<ctime>
#include<algorithm>
#include<cstdio>
#include<set>
#include<memory.h>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
#define ll long long
#define For(i,x,y)  for(int i=x;i<=y;++i)
#define FOr(i,x,y)  for(int i=x;i>=y;--i)
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){ write(x);   puts("");   }
const ll mod=1e9+7,N=110;
ll a[]={1,0,-1,0};
ll b[]={0,1,0,-1};
char s[N];
ll mp[N][N],c[N],d[N],vis[N],sx,sy,tx,ty,ans,n,m;
bool check(){
	For(i,0,3)	c[i]=a[vis[i]],
				d[i]=b[vis[i]];
	ll nowx=sx,nowy=sy,len=strlen(s+1);
	For(i,1,len){
		nowx+=c[s[i]-'0'];
		nowy+=d[s[i]-'0'];
		if (mp[nowx][nowy])	return 0;
		if (nowx==tx&&nowy==ty)	return 1;
	}return 0;
}
void dfs(ll x){
	if (x==4){
			return ans+=check(),void(0); 
		}
	For(i,0,3)	if (!(~vis[i])){
		vis[i]=x;
		dfs(x+1);
		vis[i]=-1;
	}
}
int main(){
	n=read();	m=read();
	memset(mp,1,sizeof mp);
	memset(vis,-1,sizeof vis);
	For(i,1,n){
		scanf("%s",s+1);
		For(j,1,m){
			if (s[j]=='S')	sx=i,sy=j,mp[i][j]=0;
			else if (s[j]=='E')	tx=i,ty=j,mp[i][j]=0;
			else mp[i][j]=s[j]=='#';
		}
	}scanf("%s",s+1);
	dfs(0);writeln(ans);
}