#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

namespace io{
	const int L=(1<<19)+1;
	char ibuf[L],*iS,*iT,obuf[L],*oS=obuf,*oT=obuf+L-1,c,st[55];int f,tp;
	char gc(){
		if(iS==iT){
			iT=(iS=ibuf)+fread(ibuf,1,L,stdin);
			return iS==iT?EOF:*iS++;
		}
		return*iS++;
	}
	void cbuf(){fwrite(obuf,1,oS-obuf,stdout);oS=obuf;}
	void putc(char x){*oS++=x;if(oS==oT)cbuf();}
	void gs(char*s){
		for(c=gc();c>'z'||c<'a';c=gc());
		for(;c>='a'&&c<='z';c=gc())*s++=c;
	}
	template<class I>void gi(I&x){
		for(f=1,c=gc();c<'0'||c>'9';c=gc())if(c=='-')f=-1;
		for(x=0;c<='9'&&c>='0';c=gc())x=x*10+(c&15);x*=f;
	}
	void ps(char*s){while(*s)putc(*s++);}
	template<class I>void print(I x){
		if(!x)putc('0');if(x<0)putc('-'),x=-x;
		while(x)st[++tp]=x%10+'0',x/=10;
		while(tp)putc(st[tp--]);
	}
	void scan(int l,...){
		va_list scan;
		va_start(scan,l);
		while(l)gi(*va_arg(scan,int*)),l--;
		va_end(scan);
	}
};
using io::putc;
using io::gi;
using io::gs;
using io::ps;
using io::scan;
using io::print;

const int N=3E5+5;
ll inf=1E18;

namespace ST{
	ll minv[N<<2],tag[N<<2];
	void build(int x,int l,int r){
		minv[x]=inf;
		if(l==r){tag[x]=inf;return;}
		int ls=x<<1,rs=ls|1,mid=(l+r)>>1;
		build(ls,l,mid),build(rs,mid+1,r);
	}
	void pushdown(int x){
		int ls=x<<1,rs=ls|1;
		if(tag[x]){
			tag[ls]+=tag[x],minv[ls]+=tag[x];
			tag[rs]+=tag[x],minv[rs]+=tag[x];
			tag[x]=0;
		}
	}
	void update(int x,int l,int r,int s,int t,ll u){
		if(s>t) return;
		if(l==s&&r==t){tag[x]+=u,minv[x]+=u;return;}
		int ls=x<<1,rs=ls|1,mid=(l+r)>>1;
		if(t<=mid) update(ls,l,mid,s,t,u);
		else if(s>mid) update(rs,mid+1,r,s,t,u);
		else update(ls,l,mid,s,mid,u),update(rs,mid+1,r,mid+1,t,u);
		minv[x]=min(minv[ls],minv[rs])+tag[x];
	}
	void change(int x,int l,int r,int p,ll u){
		if(l==r){minv[x]=tag[x]=u;return;}
		pushdown(x);
		int ls=x<<1,rs=ls|1,mid=(l+r)>>1;
		if(p<=mid) change(ls,l,mid,p,u);
		else change(rs,mid+1,r,p,u);
		minv[x]=min(minv[ls],minv[rs]);
	}
	ll ask(int x,int l,int r,int s,int t){
		if(s>t) return inf;
		if(l==s&&r==t) return minv[x];
		int ls=x<<1,rs=ls|1,mid=(l+r)>>1;
		if(t<=mid) return ask(ls,l,mid,s,t)+tag[x];
		if(s>mid) return ask(rs,mid+1,r,s,t)+tag[x];
		return min(ask(ls,l,mid,s,mid),ask(rs,mid+1,r,mid+1,t))+tag[x];
	}
}
using ST::update;
using ST::change;
using ST::ask;

int n,m,c[N],dfn[N],ldfn[N],rdfn[N],dfc;
vector<int>e[N],ic[N],dc[N];
ll F[N];

void dfs(int x,int fa){
	ldfn[x]=dfc+1;
	for (auto v:ic[x]) dfn[v]=++dfc;
	for (auto v:e[x]) if(v!=fa) dfs(v,x);
	rdfn[x]=dfc;
}

void get(int x,int fa){
	ll sum=0;
	for (auto v:e[x]) if(v!=fa) {
		get(v,x), sum+=F[v];
		if (sum>(inf<<1)) sum=inf<<1;
	}
	if (x==1) {F[x]=sum<inf?sum:-1; return;}
	for (auto v:ic[x]) change(1,1,dfc,dfn[v],c[v]+sum);
	for (auto v:dc[x]) change(1,1,dfc,dfn[v],inf);
	for (auto v:e[x]) if(v!=fa) update(1,1,dfc,ldfn[v],rdfn[v],sum-F[v]);
	F[x]=ask(1,1,dfc,ldfn[x],rdfn[x]);
}

int main(){
	gi(n),gi(m);
	for(int i=1,u,v;i<n;i++){
		gi(u),gi(v);
		e[u].push_back(v);
		e[v].push_back(u); 
	}
	for(int i=1,u,v;i<=m;i++){
		gi(u),gi(v),gi(c[i]);
		ic[u].push_back(i);
		dc[v].push_back(i);
	}
	dfs(1,0);
	ST::build(1,1,dfc);
	get(1,0);
	printf("%lld\n",F[1]);
	return 0;
}