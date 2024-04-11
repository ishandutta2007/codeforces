#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define PB push_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=750005;
int n,deg[N],ind,uu[N],vv[N];
vector<int>e[N];
int fa[N],ch[N][2],rev[N],v[N],sum[N];
int isrt(int k1){return ch[fa[k1]][0]!=k1&&ch[fa[k1]][1]!=k1;}
int get(int k1){return ch[fa[k1]][1]==k1;}
void pst(int k1){
	rev[k1]^=1,swap(ch[k1][0],ch[k1][1]);
}
void psd(int k1){
	if(rev[k1]){
		pst(ch[k1][0]);
		pst(ch[k1][1]);
		rev[k1]=0;
	}
}
void upd(int k1){
	assert(k1);
	sum[k1]=sum[ch[k1][0]]+sum[ch[k1][1]]+v[k1];
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
	vector<int>st{k1};
	for(int i=k1;!isrt(i);i=fa[i])st.PB(fa[i]);
	per(i,SZ(st)-1,0)psd(st[i]);
	for(;!isrt(k1);rotate(k1))if(!isrt(fa[k1]))rotate(get(k1)==get(fa[k1])?fa[k1]:k1);
}
void access(int k1){
	assert(k1);
	for(int i=0;k1;i=k1,k1=fa[k1]){
		splay(k1);
		ch[k1][1]=i;
		upd(k1);
	}
}
void makert(int k1){
	assert(k1);
	access(k1);
	splay(k1);
	pst(k1);
}
void link(int k1,int k2){
	makert(k1);
	fa[k1]=k2;
}
void cut(int k1,int k2){
	assert(k1),assert(k2);
	makert(k1);
	access(k2);
	splay(k2);
	splay(k1);
	assert(ch[k1][1]==k2);
	assert(fa[k2]==k1);
	ch[k1][1]=0,fa[k2]=0;
	upd(k1);
}
void deal(int k1,int k2){
	makert(k1);
	access(k2);
	splay(k2);
	int k3=k2;
	while(1){
		while(psd(k3),ch[k3][0]&&sum[ch[k3][0]])k3=ch[k3][0];
		if(v[k3])break;
		k3=ch[k3][1];
	}
	//D("cut %d %d %d\n",k3,uu[k3],vv[k3]);
	assert(v[k3]);
	cut(k3,uu[k3]);
	cut(k3,vv[k3]);
	printf("%d %d\n",uu[k3],vv[k3]);
	link(k1,k2);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	ind=n;
	rep(i,1,n-1){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		e[k1].PB(k2),e[k2].PB(k1);
		++deg[k1],++deg[k2];
	}
	rep(i,1,n-1){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		++ind;
		uu[ind]=k1,vv[ind]=k2;
		//D("(%d,%d)->%d\n",k1,k2,ind);
		v[ind]=1;
		link(k1,ind);
		link(ind,k2);
		//rep(i,1,ind)D("fa[%d]=%d\n",i,fa[i]);
	}
	function<void(int,int)>dfs=[&](int k1,int k2){
		for(auto x:e[k1])if(x!=k2)dfs(x,k1);
		if(k2){
			printf("%d %d ",k1,k2);
			deal(k1,k2);
		}
	};
	printf("%d\n",n-1);
	dfs(1,0);
	return 0;
}