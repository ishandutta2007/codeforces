#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N=250050;
const int M=750050;
const int inf=1e9+7;

int u[M],v[M];

int fa[M],go[M][2],cnt[M],sum[M],val[M],lzy[M],tag[M],type[M],mn[M];
void upd(int x,int v){
	if(!x)return;
	sum[x]+=cnt[x]*v;
	if(type[x]==1)val[x]+=v;
	lzy[x]+=v;
}
void rev(int x){
	swap(go[x][0],go[x][1]);
	tag[x]^=1;
}
void push(int x){
	if(lzy[x]){
		upd(go[x][0],lzy[x]);
		upd(go[x][1],lzy[x]);
		lzy[x]=0;
	}
	if(tag[x]){
		rev(go[x][0]);
		rev(go[x][1]);
		tag[x]=0;
	}
}
void pull(int x){
	if(!x)return;
	cnt[x]=cnt[go[x][0]]+type[x]+cnt[go[x][1]];
	sum[x]=sum[go[x][0]]+val[x]+sum[go[x][1]];
	mn[x]=min(min(mn[go[x][0]],x),mn[go[x][1]]);
}
int pd(int x){return go[fa[x]][0]==x?0:go[fa[x]][1]==x?1:-1;}
void rot(int x){
	int y=fa[x],z=fa[y],p=pd(x),q=pd(y),w=go[x][p^1];
	if(~q)go[z][q]=x;go[x][p^1]=y;go[y][p]=w;
	if(w)fa[w]=y;fa[y]=x;fa[x]=z;
	pull(y);pull(x);
}
void cl(int x){if(~pd(x))cl(fa[x]);push(x);}
void splay(int x,int y=0){
	for(cl(x);~pd(x)&&fa[x]!=y;rot(x))
		if(~pd(fa[x])&&fa[fa[x]]!=y)
			rot(pd(x)==pd(fa[x])?fa[x]:x);
}
void fix(int x,int c){
	splay(x);
	go[x][1]=c;
	pull(x);
}
void access(int x){
	for(fix(x,0);fa[x];rot(x))fix(fa[x],x);
}
void mkrt(int x){access(x);rev(x);}
void path(int x,int y){
	mkrt(x);access(y);splay(x,y);
}
bool link(int x,int y,int i){
	path(x,y);
	if(!fa[x]){
		fa[x]=i;
		fa[i]=y;
		return true;
	}
	if(sum[y]>0)return false;
	int mne=mn[y];
	splay(mne);
	fa[go[mne][0]]=0;go[mne][0]=0;
	fa[go[mne][1]]=0;go[mne][1]=0;
	path(x,y);
	fa[x]=i;
	fa[i]=y;
	path(u[mne],v[mne]);
	upd(v[mne],1);
	return true;
}
void cut(int x,int y,int i){
	path(x,y);
	if(sum[y]>0){
		upd(y,-1);
	}else{
		fa[go[x][1]]=0;go[x][1]=0;pull(x);
		fa[x]=0;go[y][0]=0;pull(y);
	}
}

int main(){
	mn[0]=inf;
	int n,m;
	scanf("%i %i",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%i %i",&u[i],&v[i]);
		u[i]+=m;
		v[i]+=m;
		type[i]=1;
	}
	int ptr=1;
	ll ans=0;
	for(int i=1;i<=m;i++){
		while(ptr<=m&&link(u[ptr],v[ptr],ptr)){
			ptr++;
		}
		ans+=ptr-i;
		cut(u[i],v[i],ptr);
	}
	printf("%lld\n",ans);
	return 0;
}