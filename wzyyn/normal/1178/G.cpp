#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define y1 wzpakking
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=200005,BLK=200;
struct edge{
	int to,next;
}e[N*2];
int head[N],tot,n,Q;
int dfn[N],ed[N],a[N],b[N];
int A[N],B[N],fa[N];
struct Line{
	ll k,b;
	ll F(ll x){
		return k*x+b;
	}
};
bool cmp(Line a,Line b,Line c){
	if (b.k==c.k) return b.b<c.b;
	ll ins1=(a.b-b.b)/(b.k-a.k);
	ll ins2=(a.b-c.b)/(c.k-a.k);
	if ((b.k-a.k)*ins1<a.b-b.b) ++ins1;
	if ((c.k-a.k)*ins2<a.b-c.b) ++ins2;
	return ins1>=ins2;
}
struct BLOCK{
	int L,R,len,tp,vad,pos,tg;
	int va[BLK+5],vb[BLK+5],id[BLK+5];
	Line q[BLK+5];
	void build_que(){
		vad=1<<30; tp=0; pos=1;
		Rep(i,len,1) if (va[id[i]]<0){
			int x=id[i];
			vad=min(vad,-va[x]);
			Line tmp=(Line){-vb[x],-1ll*va[x]*vb[x]};
			for (;tp&&q[tp].k==tmp.k;tmp.b=max(tmp.b,q[tp--].b));
			for (;tp>1&&cmp(q[tp-1],q[tp],tmp);--tp);
			q[++tp]=tmp;
		}
		//printf("%d\n",len);
		For(i,1,len) if (va[id[i]]>=0){
			int x=id[i];
			Line tmp=(Line){vb[x],1ll*va[x]*vb[x]};
			for (;tp&&q[tp].k==tmp.k;tmp.b=max(tmp.b,q[tp--].b));
			for (;tp>1&&cmp(q[tp-1],q[tp],tmp);--tp);
			q[++tp]=tmp;
		}
		//For(i,1,tp) printf("%lld %lld\n",q[i].k,q[i].b);
		//For(i,1,len) printf("%d\n",id[i]);
	}
	void build(){
		//printf("%d %d\n",L,R);
		len=R-L+1;
		For(i,L,R) va[i-L+1]=A[i];
		For(i,L,R) vb[i-L+1]=abs(B[i]);
		For(i,1,len) id[i]=i;
		For(i,1,len) For(j,i+1,len)
			if (vb[id[i]]>vb[id[j]])
				swap(id[i],id[j]);
		build_que();
	}
	void change(int l,int r,int v){
		if (l==-1) l=1; else l=l-L+1;
		if (r==-1) r=len; else r=r-L+1;
		For(i,1,len) va[i]+=tg;
		For(i,l,r) va[i]+=v;
		tg=0; build_que();
	}
	void change(int v){
		if ((tg+=v)>vad)
			change(-1,-1,0);
	}
	ll ask(){
		for (;pos!=tp&&q[pos].F(tg)<q[pos+1].F(tg);++pos);
		return q[pos].F(tg);	
	}
	ll ask(int l,int r){
		if (l==-1) l=1; else l=l-L+1;
		if (r==-1) r=len; else r=r-L+1;
		ll ans=0;
		For(i,l,r)
			ans=max(ans,1ll*abs(va[i]+tg)*vb[i]);
		return ans;
	}
}BL[1005];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x){
	dfn[x]=++*dfn;
	//printf("%d %d %d\n",x,a[x],b[x]);
	A[*dfn]=a[x]; B[*dfn]=b[x];
	for (int i=head[x];i;i=e[i].next){
		a[e[i].to]+=a[x];
		b[e[i].to]+=b[x];
		dfs(e[i].to); 
	}
	ed[x]=*dfn;
}
void change(int l,int r,int v){
	int bl=(l-1)/BLK+1;
	int br=(r-1)/BLK+1;
	if (bl==br)
		BL[bl].change(l,r,v);
	else{
		BL[bl].change(l,-1,v);
		BL[br].change(-1,r,v);
		For(i,bl+1,br-1) BL[i].change(v);
	}
}
ll ask(int l,int r){
	ll ans=0;
	int bl=(l-1)/BLK+1;
	int br=(r-1)/BLK+1;
	if (bl==br)
		ans=max(ans,BL[bl].ask(l,r));
	else{
		ans=max(ans,BL[bl].ask(l,-1));
		ans=max(ans,BL[br].ask(-1,r));
		For(i,bl+1,br-1) ans=max(ans,BL[i].ask());
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,2,n){
		scanf("%d",&fa[i]);
		add(fa[i],i);
	}
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) scanf("%d",&b[i]);
	dfs(1);
	int cnt=(n-1)/BLK+1;
	For(i,1,cnt){
		BL[i].L=(i-1)*BLK+1;
		BL[i].R=min(n,i*BLK);
		BL[i].build();
	}
	while (Q--){
		int tp,x,y;
		scanf("%d%d",&tp,&x);
		if (tp==1){
			scanf("%d",&y);
			change(dfn[x],ed[x],y);
		}
		else
			printf("%lld\n",ask(dfn[x],ed[x]));
	}
}