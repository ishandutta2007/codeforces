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
const int N=25;
int n,ans,co[2][N][N];
struct node{
	int matl[N],matr[N];
	int w[N][N],from[N];
	int vx[N],vy[N],v[N];
	int lx[N],ly[N],q[N];
	void extend(int x){
		for (;x;swap(x,matr[from[x]]))
			matl[x]=from[x];
	}
	void KM(int id){
		For(i,1,n) lx[id]=max(lx[id],w[id][i]-ly[i]);
		memset(vx,0,sizeof(vx));
		memset(vy,0,sizeof(vy));
		memset(v,30,sizeof(v));
		int h=0,t=1; q[1]=id; vx[id]=1;
		for (;;){
			for (;h!=t;){
				int x=q[++h];
				For(i,1,n) if (!vy[i]){
					int tmp=lx[x]+ly[i]-w[x][i];
					if (tmp>v[i]) continue;
					from[i]=x;
					if (!tmp){
						if (!matl[i]) return extend(i);
						vy[i]=vx[matl[i]]=1;
						q[++t]=matl[i];
					}
					else v[i]=tmp;
				}
			}
			int val=1<<30,p;
			For(i,1,n)
				if (!vy[i]&&val>v[i])
					val=v[i],p=i;
			For(i,1,n){
				if (vx[i]) lx[i]-=val;
				if (vy[i]) ly[i]+=val;
				else v[i]-=val;
			}
			if (!matl[p]) return extend(p);
			h=0; t=1; vy[p]=vx[matl[p]]=1;
			q[1]=matl[p];
		}
	}
	int VAL(){
		int ans=0;
		For(i,1,n)
			ans+=lx[i]+ly[i];
		return ans; 
	}
}D[N];
void dfs(int x,int cnt){
	if (x>n){
		ans=max(ans,D[n].VAL());
		return;
	}
	For(c,0,1){
		cnt+=c;
		if (cnt*2>n||(x-cnt)*2>n) continue;
		D[x]=D[x-1];
		For(j,1,n) D[x].w[x][j]=co[c][x][j];
		D[x].KM(x); dfs(x+1,cnt);
	}
}
int main(){
	scanf("%d",&n);
	For(T,0,1) For(i,1,n) For(j,1,n)
		scanf("%d",&co[T][i][j]);
	dfs(1,0);
	printf("%d\n",ans);
}