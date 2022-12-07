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
const int N=50005;
map<pair<int,int>,int> mp;
map<pair<int,int>,int> at;
map<ll,bool> used;
int fa[N],nd,x1,x2,y1,y2;
int x[N],y[N],ans,n;
ll hsh[N];
pii q[N];
int getid(int x,int y){
	if (mp.find(pii(x,y))==mp.end()){
		++nd; fa[nd]=nd;
		return mp[pii(x,y)]=nd;
	}
	return mp[pii(x,y)];
}
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void add(int x,int y){
	//cout<<"ADD "<<x<<' '<<y<<endl;
	x=get(x); y=get(y);
	if (x!=y){
		if (x<y) swap(x,y);
		fa[x]=y;
	}
}
void insert(int sx,int sy,int tx,int ty){
	if (pii(sx,sy)>pii(tx,ty))
		swap(sx,tx),swap(sy,ty);
	if (sx==tx&&x1<sx&&sx<x2){
		if (ty<=y1||sy>=y2) return;
		int py1=max(y1,sy),py2=min(y2,ty);
		add(getid(sx,py1),getid(sx,py2));
	}
	if (sy==ty&&y1<sy&&sy<y2){
		if (tx<=x1||sx>=x2) return;
		int px1=max(x1,sx),px2=min(x2,tx);
		add(getid(px1,sy),getid(px2,sy));
	}
}
void UPDans(int px,int py,int qx,int qy){
	if (px!=-1&&py!=-1){
		ll val=hsh[getid(px,py)];
		if (used[val]) return;
		used[val]=1;
	}
	int flg=0;
	For(i,1,n){
		int sx=x[i],sy=y[i],tx=x[i%n+1],ty=y[i%n+1];
		if (sx!=tx||sx<=qx) continue;
		if ((sy<=qy)^(ty<=qy)) flg^=1;
	}
	//cout<<qx<<' '<<qy<<' '<<flg<<endl; 
	ans+=flg;
}
int main(){
	scanf("%d%d%d%d",&x1,&y2,&x2,&y1);
	For(i,x1+1,x2-1) getid(i,y1);
	For(i,y1+1,y2-1) getid(x2,i);
	Rep(i,x2-1,x1+1) getid(i,y2);
	Rep(i,y2-1,y1+1) getid(x1,i);
	int tmp=nd,top=0,flg=0;
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d",&x[i],&y[i]);
	For(i,1,n) flg|=(x[i]<x1||x[i]>x2||y[i]<y1||y[i]>y2);
	if (!flg) return puts("1"),0;
	For(i,1,n) insert(x[i],y[i],x[i%n+1],y[i%n+1]);
	For(i,1,tmp) if (get(i)!=i) q[++top]=pii(i,get(i));
	//cout<<top<<' '<<ans<<endl;
	//For(i,1,top) cout<<q[i].fi<<' '<<q[i].se<<endl;
	if (!top) UPDans(-1,-1,x1,y1);
	else{
		For(i,1,top){
			ll val=1ll*i*i*i;
			hsh[q[i].se+1]^=val;
			hsh[q[i].fi+1]^=val;
		}
		For(i,1,tmp) hsh[i]^=hsh[i-1];
		For(i,x1+1,x2-1) UPDans(i,y1,i-1,y1);
		For(i,x1+1,x2-1) UPDans(i,y2,i,y2-1);
		For(i,y1+1,y2-1) UPDans(x2,i,x2-1,i-1);
		For(i,y1+1,y2-1) UPDans(x1,i,x1,i);
	}
	printf("%d\n",ans);
}
/*
2 5 5 2
12
1 3
1 4
3 4
3 6
4 6
4 4
6 4
6 3
4 3
4 1
3 1
3 3
*/