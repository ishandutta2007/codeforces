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
const int N=100005;
const int mo=1000000007;
struct edge{
	int to,next,v;
}e[N*2];
int head[N],tot=1,n,m;
int f[N][2][2],d[N];
int px,py,pid,vx,vy;
int ans0,ans1,fl[N];
void add(int x,int y,int f1,int f2){
	x=abs(x); y=abs(y);
	e[++tot]=(edge){y,head[x],f1};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],f2};
	head[y]=tot;
}
void dfs(int x,int fa){
	//cout<<x<<' '<<fa<<endl;
	for (int i=head[x];i;i=e[i].next)
		if ((i^fa)>1)
			if (!d[e[i].to]){
				d[e[i].to]=d[x]+1;
				dfs(e[i].to,i);
			}
			else if (d[e[i].to]<=d[x])
				px=x,py=e[i].to,pid=i;
}
bool check(int v1,int v2,int fl){
	if (!(fl&2)) v1^=1;
	if (!(fl&1)) v2^=1;
	return v1|v2;
}
void DP(int x,int fa){
	for (int i=head[x];i;i=e[i].next)
		if ((i^fa)>1&&(i^pid)>1)
			DP(e[i].to,i);
	memset(f[x],0,sizeof(f[x]));
	For(v,0,1){
		if (x==px&&v!=vx) continue;
		if (x==py&&v!=vy) continue;
		int res0=1,res1=0;
		for (int i=head[x];i;i=e[i].next)
			if ((i^fa)>1&&(i^pid)>1){
				int y=e[i].to;
				int val0=0,val1=0;
				For(vv,0,1){
					int tmp0=f[y][vv][0],tmp1=f[y][vv][1];
					if (check(v,vv,e[i].v))	swap(tmp0,tmp1);
					val0=(val0+1ll*res0*tmp0+1ll*res1*tmp1)%mo;
					val1=(val1+1ll*res0*tmp1+1ll*res1*tmp0)%mo;
				}
				res0=val0; res1=val1;
			}
		if (fl[x]&(1<<v))
			swap(res0,res1);
		f[x][v][0]=res0;
		f[x][v][1]=res1;
	}
}
void solve(int x){
	px=-1; py=-1;
	d[x]=1; dfs(x,0);
	int res0=0,res1=0;
	if (px==-1){
		px=x;
		for (vx=0;vx<2;vx++){
			DP(x,0);
			res0=(res0+f[x][vx][0])%mo;
			res1=(res1+f[x][vx][1])%mo;
		}
	}
	else{
		for (vx=0;vx<2;vx++)
			for (vy=0;vy<2;vy++){
				DP(x,0);
				if (check(vx,vy,e[pid].v)){
					swap(f[x][0][0],f[x][0][1]);
					swap(f[x][1][0],f[x][1][1]);
				}
				res0=(1ll*res0+f[x][0][0]+f[x][1][0])%mo;
				res1=(1ll*res1+f[x][0][1]+f[x][1][1])%mo;
			}
	}
	//cout<<res0<<' '<<res1<<' '<<px<<' '<<py<<' '<<pid<<' '<<x<<endl;
	int tmp0=ans0,tmp1=ans1;
	ans0=(1ll*tmp0*res0+1ll*tmp1*res1)%mo;
	ans1=(1ll*tmp0*res1+1ll*tmp1*res0)%mo;
}
int main(){
	scanf("%d%d",&m,&n);
	for (;m--;){
		int x,y;
		scanf("%d",&x);
		if (x==1){
			scanf("%d",&y);
			fl[abs(y)]|=(y>0?2:1); 
		}
		else{
			scanf("%d%d",&x,&y);
			if (x<0&&y<0) add(x,y,0,0);
			if (x<0&&y>0) add(x,y,1,2);
			if (x>0&&y<0) add(x,y,2,1);
			if (x>0&&y>0) add(x,y,3,3);
		}
	}
	ans0=1; ans1=0;
	For(i,1,n) if (!d[i]) solve(i);
	printf("%d\n",ans1);
}