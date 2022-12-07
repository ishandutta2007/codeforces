#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=100005;
int n,nd,rt;
int sz[N],fa[N],ch[N][2];
ll tg1[N],tg2[N],val[N];
void update(int x,ll v1,ll v2){
	tg1[x]+=v1; tg2[x]+=v2;
	val[x]+=1ll*sz[ch[x][0]]*v1+v2;
}
void pushdown(int x){
	update(ch[x][0],tg1[x],tg2[x]);
	update(ch[x][1],tg1[x],tg2[x]+tg1[x]*(sz[ch[x][0]]+1));
	tg1[x]=tg2[x]=0;
}
void pushup(int x){
	sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
}
void rotate(int x){
	int y=fa[x],z=fa[y],l=(ch[y][1]==x),r=l^1;
	if (z) ch[z][ch[z][1]==y]=x;
	fa[x]=z; fa[y]=x; fa[ch[x][r]]=y;
	ch[y][l]=ch[x][r]; ch[x][r]=y;
	pushup(y); pushup(x);
}
void down(int x){
	if (x) down(fa[x]);
	pushdown(x);
}
void splay(int x){
	down(x);
	for (;fa[x];rotate(x)){
		int y=fa[x],z=fa[y];
		if (z) rotate((ch[y][1]==x)^(ch[z][1]==y)?x:y);
	}
	rt=x;
}
ll F(int S){
	int x=rt;
	for (;;){
		if (S==sz[ch[x][0]]+1){
			splay(x);
			return val[x];
		}
		if (S<=sz[ch[x][0]])
			x=ch[x][0];
		else{
			S-=sz[ch[x][0]]+1;
			x=ch[x][1];
		}
	}
}
ll getans(int x){
	pushdown(x);
	ll ans=val[x];
	if (ch[x][0]) ans=max(ans,getans(ch[x][0]));
	if (ch[x][1]) ans=max(ans,getans(ch[x][1]));
	return ans;
}
int main(){
	scanf("%d",&n);
	nd=rt=sz[1]=1;
	For(i,1,n){
		int x;
		scanf("%d",&x);
		int l=1,r=i-1,ans=i;
		while (l<=r){
			int mid=(l+r)/2;
			if (F(mid)+1ll*mid*x>=F(mid+1))
				ans=mid,r=mid-1;
			else l=mid+1;
		}
		F(ans);
		fa[++nd]=rt;
		fa[ch[rt][1]]=nd;
		ch[nd][1]=ch[rt][1];
		ch[rt][1]=nd;
		val[nd]=val[rt];
		update(nd,x,1ll*ans*x);
	}
	printf("%lld\n",getans(rt));
}