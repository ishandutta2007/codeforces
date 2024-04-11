#include<bits/stdc++.h>

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

const int N=100005,W=10000005;
int n,a[N],xsm[2],b[2][W],k;
long long ans;
vector<int>e[N],ve[2];
void dfs(int x,int p){
	if(x==n)k=p;ve[p].push_back(a[x]);
	b[p][a[x]]++,xsm[p]^=a[x];
	for(int v:e[x])dfs(v,p^1);
}

int main(){
	gi(n);
	for(int u=1;u<=n;u++)gi(a[u]);
	for(int v=2,u;v<=n;v++)gi(u),e[u].push_back(v);
	dfs(1,0);
	if(xsm[k]==0){
		ans+=(long long)ve[0].size()*(ve[0].size()-1)>>1;
		ans+=(long long)ve[1].size()*(ve[1].size()-1)>>1;
	}
	for(int w:ve[k])if((xsm[k]^w)<W)ans+=b[k^1][xsm[k]^w];
	printf("%lld\n",ans);
	return 0;
}