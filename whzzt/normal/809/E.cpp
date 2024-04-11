#include"bits/stdc++.h"
#define last last_

#define DEBUG(...) fprintf(stderr,__VA_ARGS__)

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
		while(l){
			int*w=va_arg(scan,int*); 
			gi(*w),l--;
		}
	}
};
using io::putc;
using io::gi;
using io::gs;
using io::ps;
using io::scan;
using io::print;

const int N=2E5+5,P=1E9+7,M=3E4+5;
typedef long long ll;

int n,a[N],b[N],eu[N],mu[N],func[N],pri[M],pcnt,inv[N],dfn[N],bel[N],fa[N],dfc,sz[N],son[N],dep[N],res,ans,st[N],tp,SUMF[N],SUMG[N],F[N];
bool fl[N],col[N];
vector<int>e[N],E[N],ve,id;

int power(int a,int t){
	int r=1;
	while(t){
		if(t&1)r=(ll)r*a%P;
		a=(ll)a*a%P;t>>=1;
	}
	return r;
}

void dfs(int x){
	sz[x]=1,dep[x]=dep[fa[x]]+1;
	for(auto v:e[x])if(v!=fa[x]){
		fa[v]=x,dfs(v),sz[x]+=sz[v];
		if(sz[v]>sz[son[x]])son[x]=v;
	}
}

void dfs(int x,int b){
//	DEBUG("%d %d\n",x,b);
	dfn[x]=++dfc,bel[x]=b;
	if(son[x])dfs(son[x],b);
	for(auto v:e[x])if(v!=fa[x]&&v!=son[x])dfs(v,v);
}

int lca(int u,int v){
//	DEBUG("%d %d ",u,v);
	while(bel[u]!=bel[v])dep[bel[u]]>dep[bel[v]]?u=fa[bel[u]]:v=fa[bel[v]];
//	DEBUG("%d\n",dep[u]<dep[v]?u:v);
	return dep[u]<dep[v]?u:v;
}

void solve(int x){
	if(col[x])SUMF[x]=F[x],SUMG[x]=(ll)F[x]*dep[x]%P;
	else SUMF[x]=SUMG[x]=0;
	for(auto v:E[x]){
		solve(v);
		res=(res+(ll)SUMF[x]*SUMG[v]+(ll)SUMF[v]*SUMG[x]-(ll)SUMF[x]*SUMF[v]%P*dep[x]*2)%P;
		(SUMF[x]+=SUMF[v])%=P,(SUMG[x]+=SUMG[v])%=P;
	}
//	DEBUG("%d %d\n",x,res);
}

bool comp(const int&x,const int&y){return dfn[x]<dfn[y];}
int calc(){
	res=0;
	sort(ve.begin(),ve.end(),comp);
	st[++tp]=1,id.push_back(1),col[1]=ve[0]==1;
	for(int i=ve[0]==1,l=ve.size();i<l;i++){
		int f=lca(st[tp],ve[i]),last=0;
		while(dep[st[tp]]>dep[f]){
			if(last)E[st[tp]].push_back(last);
			last=st[tp],st[tp--]=0;
		}
		if(st[tp]!=f)st[++tp]=f,id.push_back(f);
		if(last)E[st[tp]].push_back(last);
		st[++tp]=ve[i],id.push_back(ve[i]);
		col[ve[i]]=true;
	}
	int last=0;
	while(tp){
		if(last)E[st[tp]].push_back(last);
		last=st[tp],st[tp--]=0;
	}
	solve(1);
	for(auto x:id)E[x].clear();
	for(auto x:ve)col[x]=false;
	ve.clear(),id.clear();
//	DEBUG("\n");
	return res;
}

int main(){
	gi(n);
	for(int i=1;i<=n;i++)gi(a[i]),b[a[i]]=i;
	for(int i=1,u,v;i<n;i++){
		gi(u),gi(v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1);
	dfs(1,1);
//	for(int i=1;i<=n;i++)DEBUG("%d\n",bel[i]);
	eu[1]=mu[1]=inv[1]=1;
	for(int i=2;i<=n;i++)inv[i]=P-(ll)(P/i)*inv[P%i]%P;
	for(int i=2;i<=n;i++){
		if(!fl[i]){
			pri[++pcnt]=i;
			eu[i]=i-1;
			mu[i]=-1;
		}
		for(int j=1;i*pri[j]<=n;j++){
			fl[i*pri[j]]=true;
			if(i%pri[j]==0){
				mu[i*pri[j]]=0;
				eu[i*pri[j]]=eu[i]*pri[j];
				break;
			}
			mu[i*pri[j]]=-mu[i];
			eu[i*pri[j]]=eu[i]*(pri[j]-1);
		}
	}
	for(int i=1;i<=n;i++){
		int w=(ll)i*inv[eu[i]]%P;
		for(int j=1;j<=n/i;j++)func[i*j]=(func[i*j]+mu[j]*w)%P;
		if(func[i]<0)func[i]+=P;
	}
	for(int d=1;d<=n;d++){
		for(int i=d;i<=n;i+=d)ve.push_back(b[i]),F[b[i]]=eu[i];
		ans=(ans+(ll)func[d]*calc())%P;
//		DEBUG("%d\n",ans);
	}
	if(ans<0)ans+=P;
	ans=(ll)(ans<<1)%P*power(n,P-2)%P*power(n-1,P-2)%P;
	print(ans),putc('\n'),io::cbuf();
	return 0;
}