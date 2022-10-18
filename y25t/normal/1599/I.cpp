#include <bits/stdc++.h>
using namespace std;
const int N=1000005;
const int M=1000005;
int go[M][4],fa[M],sum[M],val[M],lzy[M],hsc[M],tsz;
void pull(int x){
	if(!x)return;
	sum[x]=val[x]+sum[go[x][0]]+sum[go[x][1]];
	if(go[x][2])sum[x]+=min(sum[go[x][2]],sum[go[x][3]]);
	hsc[x]=go[x][2]||hsc[go[x][0]]||hsc[go[x][1]];
}
int make(int v){
	++tsz;
	val[tsz]=v;
	pull(tsz);
	return tsz;
}
void rev(int x){
	if(!x)return;
	swap(go[x][0],go[x][1]);
	lzy[x]^=1;
}
void push(int x){
	if(lzy[x]){
		rev(go[x][0]),rev(go[x][1]);
		if(go[x][2])rev(go[x][2]),rev(go[x][3]);
		lzy[x]=0;
	}
}
int is2(int x){return go[fa[x]][0]==x||go[fa[x]][1]==x;}
int pd2(int x){return go[fa[x]][0]==x?0:go[fa[x]][1]==x?1:-1;}
int is4(int x){return go[fa[x]][2]==x||go[fa[x]][3]==x;}
int pd4(int x){return go[fa[x]][2]==x?2:go[fa[x]][3]==x?3:-1;}
int isl(int x){return !go[x][0]&&!go[x][1];}
void rot(int x){
	int y=fa[x],z=fa[y],p=pd2(x),w=go[x][p^1];
	if(is2(y))go[z][pd2(y)]=x;
	else if(is4(y))go[z][pd4(y)]=x;
	fa[x]=z;
	go[x][p^1]=y;
	fa[y]=x;
	go[y][p]=w;
	if(w)fa[w]=y;
	pull(y);
}
void cl(int x){if(pd2(x)!=-1)cl(fa[x]);push(x);}
void splay(int x,int y=0){
	for(cl(x);pd2(x)!=-1&&fa[x]!=y;rot(x)){
		if(pd2(fa[x])!=-1&&fa[fa[x]]!=y)
			rot(pd2(fa[x])==pd2(x)?fa[x]:x);
	}
	pull(x);
}
int fir(int x){
	while(go[x][0])push(x),x=go[x][0];
	return x;
}
void cyc(int c,int x){
	int d=pd4(x);
	splay(c);push(x);
	int o=fir(go[c][1]);splay(o,c);go[c][1]=0;
	go[c][d]=go[x][0];fa[go[c][d]]=c;go[x][0]=0;
	rev(go[x][1]);go[o][1]=go[x][1];fa[go[o][1]]=o;go[x][1]=0;
	go[o][0]=go[c][d^1];fa[go[o][0]]=o;go[c][d^1]=o;fa[o]=c;
	pull(o);pull(c);
}
void access(int x){
	int y=0,z=x;
	for(;x;y=x,x=fa[x]){
		splay(x);
		if(fa[x]&&go[fa[x]][2])cyc(fa[x],x);
		go[x][1]=y;
		pull(x);
	}
	splay(z);
}
void mkrt(int x){
	access(x);
	rev(x);
}
void path(int x,int y){
	mkrt(x);
	access(y);
	splay(x,y);
}
int get(int x,int y){
	if(x==y)return 0;
	path(x,y);
	if(fa[x]!=y)return -1;
	return sum[y];
}
bool link(int x,int y,int w){
	if(x==y)return false;
	path(x,y);
	if(fa[x]!=y){
		int e=make(w);
		fa[x]=e;
		fa[e]=y;
		return true;
	}
	if(hsc[y])return false;
	int e=make(w),c=make(0);
	go[c][2]=go[x][1];fa[go[c][2]]=c;
	go[c][3]=e;fa[e]=c;
	go[x][1]=c;fa[c]=x;
	pull(c);pull(x);pull(y);
	return true;
}
bool cut(int x,int y,int w){
	if(x==y)return false;
	path(x,y);
	if(fa[x]!=y)return false;
	if(!isl(go[x][1]))return false;
	int c=go[x][1];
	push(c);
	if(go[c][2]){
		int d=0;
		if(isl(go[c][2])&&val[go[c][2]]==w)d=2;
		if(isl(go[c][3])&&val[go[c][3]]==w)d=3;
		if(!d)return false;
		go[x][1]=go[c][d^1];fa[go[x][1]]=x;
		pull(x);pull(y);
		return true;
	}else{
		if(val[c]!=w)return false;
		go[x][1]=0;go[y][0]=0;fa[x]=0;
		pull(x);pull(y);
		return true;
	}
}
int n,m;
int U[500005],V[500005]; 
long long ans;
int main(){
	scanf("%d%d",&n,&m);
	tsz=n;
	for(int i=1;i<=m;i++)scanf("%d%d",&U[i],&V[i]);
	for(int i=1,j=0;i<=m;i++){
		if(j<i){
			j=i;
			link(U[j],V[j],0);
		}
		while(j<m&&link(U[j+1],V[j+1],0))j++;
		cut(U[i],V[i],0);
		ans+=j-i+1;
	}
	printf("%lld\n",ans);
	return 0;
}