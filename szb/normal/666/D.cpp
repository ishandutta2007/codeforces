#include<queue>
#include<set>
#include<map>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define ll long long
#define maxn 400010
#define mk make_pair
#define rep(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
#define For(i,x,y)	for(i=x;i<=y;++i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){ write(x);   puts("");   }
ll q[10][10],g[10][10],to[10],x[10],y[10],xx[10],yy[10],X[10],Y[10],a[10],sz[10],gg[10],cost;
map<ll,ll>s1,s2;
inline void change(){
				For(to[1],1,4)	For(to[2],1,4)	For(to[3],1,4)	For(to[4],1,4)	if (to[1]!=to[2]&&to[1]!=to[3]&&to[1]!=to[4]&&to[2]!=to[3]&&to[2]!=to[4]&&to[3]!=to[4]){
					bool fl=1;
					rep(k,1,4)	fl&=((x[k]-xx[to[k]])*(y[k]-yy[to[k]]))==0;
					if (!fl)	continue;
					ll cost_now=0;
					rep(i,1,4)	
					cost_now=max(cost_now,abs(x[i]-xx[to[i]])+abs(y[i]-yy[to[i]]));
					if (cost_now<cost){
						cost=cost_now;
						rep(i,1,4)	X[i]=xx[to[i]],Y[i]=yy[to[i]];
					}
				}
}
void work(ll x,ll y,ll k){
	xx[1]=x;	yy[1]=y;
	xx[2]=x+k;	yy[2]=y;
	xx[3]=x;	yy[3]=y+k;
	xx[4]=x+k;	yy[4]=y+k;
	change();
}
int main(){
//	freopen("base.in","r",stdin);
//	freopen("base.out","w",stdout);
	ll T=read();
	while(T--){
		ll mnx=1e18,mny=1e18,mxx=-1e18,mxy=-1e18;
		rep(i,1,4)	x[i]=read(),y[i]=read(),mnx=min(mnx,x[i]),mny=min(mny,y[i]),mxx=max(mxx,x[i]),mxy=max(mxy,y[i]);
		cost=1e18;
		For(a[1],0,1)	For(a[2],0,1)	For(a[3],0,1)	For(a[4],0,1){
			gg[0]=gg[1]=0;
			s1.clear();	s2.clear();
			rep(i,1,4){
				if (a[i]==0)	s1[x[i]]=1;
				else	s2[y[i]]=1; 
			}
			rep(i,1,4){
				if (a[i]==0&&s1[x[i]])	g[0][++gg[0]]=x[i],s1[x[i]]--;
				if (a[i]==1&&s2[y[i]])	g[1][++gg[1]]=y[i],s2[y[i]]--;
			}
			sort(g[0]+1,g[0]+gg[0]+1);
			sort(g[1]+1,g[1]+gg[1]+1);
			if (gg[0]==2&&gg[1]==0){
				ll dis=g[0][2]-g[0][1];
				rep(a,1,4)	rep(b,1,4){
					work(g[0][1],(y[a]+y[b])/2-dis,dis);
					work(g[0][1],(y[a]+y[b])/2+dis,dis);
					work(g[0][1],(y[a]+y[b])/2,dis);
					work(g[0][1],(y[a]+y[b]-dis)/2,dis);
					work(g[0][1],(y[a]+y[b]+dis)/2,dis);
				}
				continue;
			}
			if (gg[0]==0&&gg[1]==2){
				ll dis=g[1][2]-g[1][1];
				rep(a,1,4)	rep(b,1,4){
					work((x[a]+x[b])/2-dis,g[1][1],dis);
					work((x[a]+x[b])/2+dis,g[1][1],dis);
					work((x[a]+x[b])/2,g[1][1],dis);
					work((x[a]+x[b]-dis)/2,g[1][1],dis);
					work((x[a]+x[b]+dis)/2,g[1][1],dis);
				}
				continue;
			}
			if (gg[0]==2&&gg[1]==2){
				if (g[1][2]-g[1][1]!=g[0][2]-g[0][1])	continue;
				work(g[0][1],g[1][1],g[0][2]-g[0][1]);
				change();	continue;
			}
			if (gg[0]==1&&gg[1]==2){
				ll dis=g[1][2]-g[1][1];
				xx[1]=g[0][1]-dis;	yy[1]=g[1][1];
				xx[2]=g[0][1]-dis;	yy[2]=g[1][2];
				xx[3]=g[0][1];	yy[3]=yy[1];
				xx[4]=g[0][1];	yy[4]=yy[2];
				change();
				xx[1]+=dis;	xx[1]+=dis;
				xx[2]+=dis;	xx[2]+=dis;
				change();
				continue;
			}
			if (gg[1]==1&&gg[0]==2){
				ll dis=g[0][2]-g[0][1];
				yy[1]=g[1][1]-dis;	xx[1]=g[0][1];
				yy[2]=g[1][1]-dis;	xx[2]=g[0][2];
				yy[3]=g[1][1];	xx[3]=xx[1];
				yy[4]=g[1][1];	xx[4]=xx[2];
				change();
				yy[1]+=dis;	yy[1]+=dis;
				yy[2]+=dis;	yy[2]+=dis;
				change();
				continue;
			}
		}
		if (cost<1e18){
			writeln(cost);
			rep(i,1,4)	write(X[i]),putchar(' '),write(Y[i]),puts("");
		}else		puts("-1");
	}
}