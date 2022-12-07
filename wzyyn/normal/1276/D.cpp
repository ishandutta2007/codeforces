#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=200005;
const int mo=998244353;
struct edge{
	int to,next,v;
}e[N*2];
int head[N],val[N],tot,n;
vector<vector<pii> > tg1[N];
vector<int> tg2[N],tg3[N];
vector<int> f[N],vec[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
struct Int{
	int x,y;
	Int(){}
	Int(int _x){
		x=max(_x,1);
		y=(_x==0);
	}
	Int(int _x,int _y){
		x=_x; y=_y;
	}
	Int operator *(const Int &a)const{
		return Int(1ll*x*a.x%mo,y+a.y);
	}
	Int operator /(const Int &a)const{
		return Int(1ll*x*power(a.x,mo-2)%mo,y-a.y);
	}
};
void add(int x,int y,int id){
	e[++tot]=(edge){y,head[x],id};
	head[x]=tot;
}
void dfs(int x,int fa){
	//printf("%d %d\n",x,fa);
	int sz=vec[x].size();
	tg1[x].resize(sz);
	tg2[x].resize(sz);
	f[x].resize(sz);
	For(i,0,sz-1) tg2[x][i]=f[x][i]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			dfs(e[i].to,x);
			int S0=0,S1=0,S2=0;
			int at=lower_bound(vec[x].begin(),vec[x].end(),e[i].v)-vec[x].begin();
			//printf("%d %d\n",x,e[i].to);
			Rep(j,vec[e[i].to].size()-1,0){
				if (vec[e[i].to][j]<=e[i].v) S0=(S0+f[e[i].to][j])%mo;
				if (vec[e[i].to][j]!=e[i].v) S1=(S1+f[e[i].to][j])%mo;
				if (vec[e[i].to][j]==e[i].v) f[x][at]=1ll*f[x][at]*S1%mo;
				/*if (j==0||vec[e[i].to][j-1]<=e[i].v){
					int pos=min(at,(int)(lower_bound(vec[x].begin(),vec[x].end(),vec[e[i].to][j])-vec[x].begin()-1));
					//printf("%d %d %d %d %d\n",x,e[i].to,vec[e[i].to][j],pos,S1);
					if (pos>=0) tg1[x][pos].PB(pii(e[i].to,S1));
				}*/
			}
			//puts("233");
			//printf("%d\n",sz);
			if (at) tg1[x][at-1].PB(pii(e[i].to,S1));
			tg2[x][at+1]=1ll*tg2[x][at+1]*S0%mo;
			val[e[i].to]=1;
		}
	Int tmp(1);
	Rep(i,sz-1,0){
		For(j,0,tg1[x][i].size()-1){
			tmp=tmp/Int(val[tg1[x][i][j].fi]);
			tmp=tmp*Int(val[tg1[x][i][j].fi]=tg1[x][i][j].se);
		}
		f[x][i]=1ll*f[x][i]*(tmp.y?0:tmp.x)%mo;
	}
	For(i,1,sz-1) tg2[x][i]=1ll*tg2[x][i]*tg2[x][i-1]%mo;
	For(i,0,sz-1) f[x][i]=1ll*f[x][i]*tg2[x][i]%mo;
}
/*
<=edge*edge
=edge*>edge 
>edge*edge 
*/
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y,i); add(y,x,i);
		vec[x].PB(i); vec[y].PB(i);
	}
	For(i,1,n) vec[i].PB(n+1);
	For(i,1,n) sort(vec[i].begin(),vec[i].end());
	dfs(1,0);
	int ans=0;
	For(i,0,f[1].size()-1)
		ans=(ans+f[1][i])%mo;
	printf("%d\n",ans); 
}
/*
f[i][j]ij 
4
1 2
3 4
2 3
*/