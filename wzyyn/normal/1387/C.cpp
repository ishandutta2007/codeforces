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
namespace ACM{
	int ch[55][2],nd=1;
	int fa[55],gg[55],q[55];
	void init(){
		int l,x=1,c;
		scanf("%d",&l);
		For(i,1,l){
			scanf("%d",&c);
			if (!ch[x][c]) ch[x][c]=++nd;
			x=ch[x][c];
		}
		gg[x]=1;
	}
	void build(){
		int h=0,t=0;
		For(i,0,1)
			if (ch[1][i]){
				fa[ch[1][i]]=1;
				q[++t]=ch[1][i];
			}
			else
				ch[1][i]=1;
		while (h!=t){
			int x=q[++h];
			gg[x]|=gg[fa[x]];
			For(i,0,1)
				if (ch[x][i]){
					fa[ch[x][i]]=ch[fa[x]][i];
					q[++t]=ch[x][i];
				}
				else
					ch[x][i]=ch[fa[x]][i];
		}
	}
}
int G,n,m;
int to[105];
int f1[105],f2[105];
vector<int> op[105];
ull d1[55][55];
ull d2[55][55];
ull dis[105][55][55];
int main(){
	scanf("%d%d%d",&G,&n,&m);
	For(i,1,n){
		int l,x;
		scanf("%d%d",&to[i],&l);
		For(j,1,l) scanf("%d",&x),op[i].PB(x);
	}
	For(i,1,m) ACM::init();
	ACM::build();
	m=ACM::nd;
	For(i,0,G-1) For(j,1,m) For(k,1,m)
		dis[i][j][k]=1ull<<63;
	For(i,0,1) For(j,1,m){
		int to=ACM::ch[j][i];
		if (!ACM::gg[to])
			dis[i][j][to]=1;
	}
	f1[0]=f1[1]=1;
	for (;;){
		bool fllag=0;
		memset(f2,0,sizeof(f2));
		For(i,1,n){
			bool flag=0;
			for (auto p:op[i])
				flag|=f1[p]&&(!f2[p]);
			if (!flag) continue;
			For(j,1,m) For(k,1,m)
				d1[j][k]=(j==k?0:(1ull<<63));
			for (auto p:op[i]){
				For(j,1,m) For(k,1,m) d2[j][k]=1ull<<63;
				For(j,1,m) For(k,1,m) For(l,1,m)
					if (d1[j][k]<-dis[p][k][l])
						d2[j][l]=min(d2[j][l],d1[j][k]+dis[p][k][l]);
				For(j,1,m) For(k,1,m) d1[j][k]=d2[j][k];
			}
			For(j,1,m) For(k,1,m)
				if (d1[j][k]<dis[to[i]][j][k]){
					//if (!d1[j][k]) cout<<i<<' '<<to[i]<<' '<<j<<' '<<k<<endl;
					dis[to[i]][j][k]=d1[j][k],fllag=1,f2[to[i]]=1;
				}
		}
		if (!fllag) break;
		For(i,0,G-1) swap(f1[i],f2[i]);
	}
	For(i,2,G-1){
		ull ans=1ull<<63;
		For(j,1,m) ans=min(ans,dis[i][1][j]);
		if (ans==(1ull<<63)) puts("YES");
		else printf("NO %llu\n",ans);
	}
}
/*
:50
:100
:100
:^3*
        *^2* 
*/