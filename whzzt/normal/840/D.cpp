#include"bits/stdc++.h"

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

typedef pair<int,int>pii;
const int N=1200005,M=6;
struct data{
	int top[M],val[M];
	data();
	data(int*a,int*b);
};
data::data(){
	memset(top,0,M<<2);
	memset(val,0,M<<2);
}
bool comp(const pii&x,const pii&y){return x>y;}
map<int,int> dat[N];  

struct ST{
	int lm;
	pii ttp[M*2+1];int tl,pl;
	data merge(data x,data y){
		int xl=0,yl=0,i;
		while(xl<lm&&x.top[xl])xl++;
		while(yl<lm&&y.top[yl])yl++;
		tl=0;
		for(i=0;i<xl;i++)ttp[tl++]=make_pair(x.top[i],x.val[i]);
		for(i=0;i<yl;i++)ttp[tl++]=make_pair(y.top[i],y.val[i]);
		if(!tl)return data();
		sort(ttp,ttp+tl);
		for(pl=0,i=1;i<tl;i++){
			if(ttp[i].first==ttp[pl].first)ttp[pl].second+=ttp[i].second;
			else ttp[++pl]=ttp[i];
		}
		for(i=0,pl++;i<pl;i++)swap(ttp[i].first,ttp[i].second);
		sort(ttp,ttp+pl,comp);
		for(pl--;pl>=lm;){
			for(i=pl-lm;i<=pl;i++)ttp[i].first-=ttp[pl].first;
			while(~pl&&ttp[pl].first==0)pl--;
		}
		data res=data();
		for(i=0;i<=pl;i++)res.top[i]=ttp[i].second,res.val[i]=ttp[i].first;
		return res;
	}
	data num[N];int tag[N];
	void addtag(int x,int l,int r,int u){
		tag[x]=u;
		num[x]=data();
		num[x].top[0]=u;
		num[x].val[0]=r-l+1;
	}
	void pushdown(int x,int l,int r){
		int ls=x<<1,rs=ls|1,mid=(l+r)>>1;
		if(tag[x]){
			addtag(ls,l,mid,tag[x]);
			addtag(rs,mid+1,r,tag[x]);
			tag[x]=0;
		}
	}
	void build(int x,int l,int r,int*a){
		if(l==r)return addtag(x,l,r,a[l]);
		int ls=x<<1,rs=ls|1,mid=(l+r)>>1;
		build(ls,l,mid,a),build(rs,mid+1,r,a);
		num[x]=merge(num[ls],num[rs]);
	}
	data ask(int x,int l,int r,int s,int t){
		if(l==s&&r==t)return num[x];
		pushdown(x,l,r);
		int mid=(l+r)>>1,ls=x<<1,rs=ls|1;
		if(t<=mid)return ask(ls,l,mid,s,t);
		if(s>mid)return ask(rs,mid+1,r,s,t);
		return merge(ask(ls,l,mid,s,mid),ask(rs,mid+1,r,mid+1,t));
	}
	void op(int L,int R,data x){
		int l=0,i,ret=1E9;
		while(x.top[l]&&l<lm)l++;
		for(i=0,l--;i<=l;i++){
			map<int,int> &q=dat[x.top[i]];
			auto lb=q.lower_bound(L),rb=q.upper_bound(R);
			rb--;
			int t=rb->second-lb->second+1;
			if(t*lm>R-L+1)ret=min(ret,x.top[i]);
		}
		if(ret==1E9)ret=-1;
		print(ret),putc('\n');
	}
}st[4];

int n,m,p,a[N];

int main(){
	gi(n),gi(m);
	st[0].lm=2,st[1].lm=3,st[2].lm=4,st[3].lm=5;
	for(int i=1;i<=n;i++)gi(a[i]),dat[a[i]].insert(make_pair(i,0));
	for(int i=1;i<=n;i++){
		int s=0;
		for(auto it=dat[i].begin();it!=dat[i].end();it++)it->second=++s;
	}
	for(int i=0;i<4;i++)st[i].build(1,1,n,a);
	for(int i=1,l,r,k;i<=m;i++){
		gi(l),gi(r),gi(k);
		st[k-2].op(l,r,st[k-2].ask(1,1,n,l,r));
	}
	io::cbuf();
	return 0;
}