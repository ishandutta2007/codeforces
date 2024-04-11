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

const int N=500005;
int n,Q,c,t,a[N],GG[N];
int fa[N],sz[N],fav[N],v[N];
int qx[N],qy[N];
pii q[N];
bool cmp(pii x,pii y){
	if (a[x.fi]!=a[y.fi])
		return a[x.fi]<a[y.fi];
	return a[x.se]<a[y.se];
}
int get(int x){
	if (fa[x]==x){
		v[x]=0;
		return x;
	}
	int p=get(fa[x]);
	v[x]=v[fa[x]]^fav[x];
	return p;
}
int main(){
	scanf("%d%d%d",&n,&Q,&c);
	For(i,1,n) fa[i]=i,sz[i]=1,fav[i]=v[i]=0;
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,Q){
		int x,y;
		scanf("%d%d",&x,&y);
		if (a[x]>a[y]) swap(x,y);
		if (a[x]==a[y]){
			int px=get(x);
			int py=get(y);
			if (px!=py){
				if (sz[px]>sz[py]) swap(px,py);
				fa[px]=py; sz[py]+=sz[px];
				fav[px]=v[x]^v[y]^1;
			}
			else
				if (v[x]^v[y]^1)
					if (!GG[a[x]]){
						GG[a[x]]=1;
						--c;
					}
		}
		else
			q[++t]=pii(x,y);
	}
	//cout<<c<<endl;
	sort(q+1,q+t+1,cmp);
	int flg=0,top=0;
	ll ans=1ll*c*(c-1)/2;
	For(i,1,t){
		if (a[q[i].fi]!=a[q[i-1].fi]||
			a[q[i].se]!=a[q[i-1].se]){
				for (;top;--top){
					int x=qx[top],y=qy[top];
					fa[x]=x; fav[x]=v[x]=0; sz[y]-=sz[x];
				}
				flg=0;
			}
		int x=q[i].fi,y=q[i].se;
		int px=get(x);
		int py=get(y);
		if (px!=py){
			if (sz[px]>sz[py]) swap(px,py);
			qx[++top]=px; qy[top]=py;
			fa[px]=py; sz[py]+=sz[px];
			fav[px]=v[x]^v[y]^1;
		}
		else
			if (v[x]^v[y]^1){
				//cout<<a[x]<<' '<<a[y]<<endl;
				if (!flg&&!GG[a[x]]&&!GG[a[y]]) --ans;
				flg=1;
			}
	}
	cout<<ans<<endl;
}