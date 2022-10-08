#include<bits/stdc++.h>
#define pb push_back
#define last last_

using namespace std;

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
	bool okch(char x){return x>='a'&&x<='z';}
	void gs(char*s){
		for(c=gc();!okch(c);c=gc());
		for(;okch(c);c=gc())*s++=c;
		*s=0;
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

const int N=1E5+5;
int n,q,p[N],m,dfn[N],bel[N],dfc,fa[N],dep[N],sz[N],son[N],st[N],tp;
bool mark[N];
vector<int>e[N],E[N],id;

int Get(int x){
	int ret=0,num=0;
	for(int v:E[x]){
		ret+=Get(v);
		if(mark[v])num++;
	}
	if(mark[x])ret+=num,num=0;
	else if(num>1)ret++,num=0;
	else if(num)mark[x]=true;
	return ret;
}

void dfs(int x){
	dep[x]=dep[fa[x]]+1,sz[x]=1;
	for(int v:e[x])if(v!=fa[x]){
		fa[v]=x,dfs(v),sz[x]+=sz[v];
		if(sz[v]>sz[son[x]])son[x]=v;
	}
}

void dfs(int x,int b){
	dfn[x]=++dfc,bel[x]=b;
	if(son[x])dfs(son[x],b);
	for(int v:e[x])if(v!=fa[x]&&v!=son[x])dfs(v,v);
}

int lca(int u,int v){
	while(bel[u]!=bel[v])if(dep[bel[u]]>dep[bel[v]])u=fa[bel[u]];else v=fa[bel[v]];
	return dep[u]<dep[v]?u:v;
}

bool comp(const int&x,const int&y){
	return dfn[x]<dfn[y];
}

int main(){
	gi(n);
	for(int i=1,u,v;i<n;i++)gi(u),gi(v),e[u].pb(v),e[v].pb(u);
	dfs(1),dfs(1,1);
	gi(q);
	while(q--){
		gi(m);
		for(int i=1;i<=m;i++)gi(p[i]),mark[p[i]]=true;
		sort(p+1,p+m+1,comp);
		st[++tp]=1,id.pb(1);
		for(int i=1+(p[1]==1);i<=m;i++){
			int f=lca(st[tp],p[i]),last=0;
			while(dep[st[tp]]>dep[f]){
				if(last)E[st[tp]].pb(last);
				last=st[tp],st[tp--]=0;
			}
			if(st[tp]!=f)st[++tp]=f,id.pb(f);
			if(last)E[st[tp]].pb(last);
			st[++tp]=p[i],id.pb(p[i]);
		}
		for(int last=0;tp;last=st[tp],st[tp--]=0)if(last)E[st[tp]].pb(last);
		for(int x:id)if(mark[x])for(int v:E[x])if(dep[v]==dep[x]+1&&mark[v]){print(-1);goto skip;}
		print(Get(1));
		skip:putc('\n');
		for(int x:id)E[x].clear(),mark[x]=false;id.clear();
	}
	io::cbuf();
	return 0;
}