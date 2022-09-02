#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=300005;
int n,m,Q,u[N],v[N],rr[N];
LL ans[N];
namespace LCT{
	int fa[N],ch[N][2],rev[N];
	int get(int u){return ch[fa[u]][1]==u;}
	int isroot(int u){return ch[fa[u]][0]!=u&&ch[fa[u]][1]!=u;}
	//void update(int u){mx[u]=max(val[u],max(mx[ch[u][0]],mx[ch[u][1]]));}
	void pushdown(int u){
		if(rev[u])std::swap(ch[u][0],ch[u][1]),rev[ch[u][0]]^=1,rev[ch[u][1]]^=1,rev[u]^=1;
	}
	void rotate(int u){
		int p=fa[u],gp=fa[p],x=get(u);
		if(!isroot(p))ch[gp][get(p)]=u;
		fa[u]=gp;
		ch[p][x]=ch[u][x^1],fa[ch[u][x^1]]=p;
		ch[u][x^1]=p,fa[p]=u;
		//update(p),update(u);
	}
	int st[N];
	void splay(int u){
		st[*st=1]=u;
		for(int i=u;!isroot(i);i=fa[i])st[++*st]=fa[i];
		for(int i=*st;i>=1;--i)pushdown(st[i]);
		for(;!isroot(u);rotate(u))
		    if(!isroot(fa[u]))
		        rotate(get(u)==get(fa[u])?fa[u]:u);
	}
	void access(int u){
		for(int i=0;u;i=u,u=fa[u]){
		    splay(u);
		    ch[u][1]=i;
		    //update(u);
		}
	}
	void makeroot(int u){
		access(u);
		splay(u),rev[u]^=1; 
	}
	void link(int u,int v){
		makeroot(u),fa[u]=v;
	}
	int findroot(int u){
		access(u),splay(u);
		while(ch[u][0])u=ch[u][0];
		return splay(u),u;
	}
	void cut(int u,int v){
		makeroot(u),access(v),splay(v);
		if(ch[u][1]||fa[u]!=v)return;
		fa[u]=ch[v][0]=0;
	}

}
vector<tuple<int,int,int> >asks[N];
vector<int>e[N];
struct BIT{
	LL t[N];
	LL all;
	void upd(int k1,int k2){
		all+=k2;
		for(int i=k1;i<=n;i+=i&-i)t[i]+=k2;
	}
	LL qry(int k1){
		LL k2=0;
		for(int i=k1;i;i&=i-1)k2+=t[i];
		return k2;
	}
	LL qry_(int k1){
		return all-qry(k1);
	}
}t1,t2;
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(m);
	rep(i,1,m){
		rd(u[i]),rd(v[i]);
		e[u[i]].pb(v[i]);
		e[v[i]].pb(u[i]);
	}
	for(int i=1,j=1,k=0;i<=n;++i){
		while(j<=n){
			while(k<SZ(e[j])&&(e[j][k]<i||e[j][k]>=j)){
				++k;
			}
			if(k>=SZ(e[j])){
				++j,k=0;
				continue;
			}
			int go=e[j][k];
			if(LCT::findroot(j)!=LCT::findroot(go)){
				LCT::link(j,e[j][k]);
				k+=1;
			}else{
				break;
			}
		}
		rr[i]=j-1;
		for(auto&x:e[i]){
			if(x>i&&x<j){
				LCT::cut(i,x);
			}
		}
	}
	rd(Q);
	rep(i,1,Q){
		int l,r;
		rd(l),rd(r);
		ans[i]-=1LL*(l+r-2)*(r-l+1)/2;
		asks[r].eb(r,i,1);
		asks[l-1].eb(r,i,-1);
	}
	rep(i,1,n){
		t1.upd(rr[i],1);
		t2.upd(rr[i],rr[i]);
		for(auto&x:asks[i]){
			int r,id,opt;
			tie(r,id,opt)=x;
			ans[id]+=1LL*opt*r*t1.qry_(r)+1LL*opt*t2.qry(r);
		}
	}
	rep(i,1,Q)printf("%lld\n",ans[i]);
	return 0;
}