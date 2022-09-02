#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=200005;
int n,Q;
struct BIT{
	int t[N*2];
	void upd(int k1,int k2){
		//D("upd %d %d\n",k1,k2);
		for(int i=k1;i<N*2;i+=i&-i)t[i]+=k2;
	}
	int qry(int k1){
		assert(k1>=0);
		int k2=0;
		for(int i=k1;i;i&=i-1)k2+=t[i];
		return k2;
	}
}B;
struct LCT{	
	int fa[N],ch[N][2],rev[N],tg[N],col[N],sz[N],st[N],top;
	int isrt(int k1){return ch[fa[k1]][0]!=k1&&ch[fa[k1]][1]!=k1;}
	int get(int k1){return ch[fa[k1]][1]==k1;}
	void upd(int k1){
		sz[k1]=sz[ch[k1][0]]+sz[ch[k1][1]]+1;
	}
	void psrev(int k1){
		rev[k1]^=1,swap(ch[k1][0],ch[k1][1]);
	}
	void pstg(int k1,int k2){
		tg[k1]=k2,col[k1]=k2;
	}
	void psd(int k1){
		if(rev[k1]){
			psrev(ch[k1][0]);
			psrev(ch[k1][1]);
			rev[k1]^=1;
		}
		if(tg[k1]){
			pstg(ch[k1][0],tg[k1]);
			pstg(ch[k1][1],tg[k1]);
			tg[k1]=0;
		}
	}
	void rotate(int k1){
		assert(k1);
		int k2=fa[k1],x=get(k1);
		if(!isrt(k2))ch[fa[k2]][get(k2)]=k1;
		fa[k1]=fa[k2];
		fa[ch[k2][x]=ch[k1][x^1]]=k2;
		fa[ch[k1][x^1]=k2]=k1;
		upd(k2),upd(k1);
	}
	void splay(int k1){
		assert(k1);
		st[top=1]=k1;
		for(int i=k1;!isrt(i);i=fa[i])st[++top]=fa[i];
		per(i,top,1)psd(st[i]);
		for(;!isrt(k1);rotate(k1))if(!isrt(fa[k1]))
			rotate(get(fa[k1])==get(k1)?fa[k1]:k1);
	}
	void access(int k1,int now=0){
		int i=0;
		for(;k1;i=k1,k1=fa[k1]){
			splay(k1);
			if(now){
				if(col[k1])B.upd(col[k1],sz[ch[k1][1]]-sz[k1]);
			}
			ch[k1][1]=i;
			upd(k1);
		}
		if(now){
			pstg(i,now);
			B.upd(now,sz[i]);
		}
	}
	void link(int k1,int k2){
		access(k1);
		splay(k1);
		psrev(k1);
		fa[k1]=k2;
	}
}A;
int qry(int k1){
	A.splay(k1);
	return B.qry(A.col[k1]-1)+A.sz[A.ch[k1][1]]+1;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&Q);
	rep(i,1,n-1){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		//D("link %d %d\n",k1,k2);
		A.link(k1,k2);
	}
	int now=0;
	rep(i,1,n){
		A.access(i,++now);
		A.splay(i);
		A.psrev(i);
	}
	char o[10];
	rep(_,1,Q){
		//D("qid=%d\n",_);
		scanf("%s",o);
		if(*o=='u'){
			int k1;
			scanf("%d",&k1);
			A.access(k1,++now);
			A.splay(k1);
			A.psrev(k1);
		}else if(*o=='w'){
			int k1;
			scanf("%d",&k1);
			printf("%d\n",qry(k1));
		}else{
			int k1,k2;
			scanf("%d%d",&k1,&k2);
			int rk1=qry(k1),rk2=qry(k2);
			printf("%d\n",rk1<rk2?k1:k2);
		}
	}
	return 0;
}