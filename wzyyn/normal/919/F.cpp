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
int id[10][10][10][10];
int fl[505][505];
int deg[505][505];
int tr[505][10][10];
vector<pii> e[505][505];
pii q[200005];
int nd,T,spe;
struct node{
	int a[10];
}st[505];
void init(){
	For(i,0,8) For(j,0,8-i)
		For(k,0,8-i-j) For(l,0,8-i-j-k){
			id[i][j][k][l]=++nd;
			st[nd].a[0]=i;
			st[nd].a[1]=j;
			st[nd].a[2]=k;
			st[nd].a[3]=l;
			st[nd].a[4]=8-i-j-k-l;
		}
	For(i,1,nd) For(j,0,4)
		if (st[i].a[j]){
			For(k,0,4){
				node tmp=st[i];
				--tmp.a[j];
				++tmp.a[(j+k)%5];
				tr[i][j][k]=id[tmp.a[0]][tmp.a[1]][tmp.a[2]][tmp.a[3]];
				assert(tr[i][j][k]<=nd&&tr[i][j][k]>0);
			}
		}
	For(i,1,nd) For(j,1,nd) fl[i][j]=-1;
	spe=id[8][0][0][0];
	//cout<<nd<<endl;
	int h=0,t=0;
	For(i,1,nd) For(j,1,nd)
		if ((i==spe)^(j==spe)){
			if (j==spe) q[++t]=pii(i,j);
			fl[i][j]=(j==spe?0:1);
		}
	For(i,1,nd) For(j,1,nd)
		For(k,0,4) if (st[j].a[k])
			For(l,0,4) if (k*l&&st[i].a[l]){
				++deg[i][j];
				e[j][tr[i][l][k]].PB(pii(i,j));
			}
	int tmpp=id[7][1][0][0];
	//cout<<deg[tmpp][tmpp]<<' '<<tmpp<<endl;
	while (h!=t){
		int x=q[++h].fi,y=q[h].se;
		//if (h%1000==0) cout<<h<<' '<<t<<' '<<x<<' '<<y<<' '<<fl[x][y]<<endl;
		if (fl[x][y]==0){
			for (auto i:e[x][y])
				if (fl[i.fi][i.se]==-1){
					fl[i.fi][i.se]=1;
					q[++t]=pii(i.fi,i.se);
				}
			}
		else{
			for (auto i:e[x][y])
				if (fl[i.fi][i.se]==-1)
					if (!--deg[i.fi][i.se]){
						fl[i.fi][i.se]=0;
						q[++t]=pii(i.fi,i.se);
					}
		}
	}
}
int read(){
	static int a[10];
	memset(a,0,sizeof(a));
	For(i,1,8){
		int x;
		scanf("%d",&x);
		++a[x];
	}
	return id[a[0]][a[1]][a[2]][a[3]];
}
int main(){
	init();
	//cout<<nd<<endl;
	int T;
	scanf("%d",&T);
	while (T--){
		int flg,x,y;
		scanf("%d",&flg);
		x=read(); y=read();
		if (flg) swap(x,y);
		if (fl[x][y]==-1) puts("Deal");
		else puts(fl[x][y]^flg?"Alice":"Bob");
	}
}