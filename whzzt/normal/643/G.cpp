#include"bits/stdc++.h"

using namespace std;

namespace IO{
	const int L=(1<<18)+1,N=250005;
	char _buf[L],*S,*T,c;
	char gc(){
		if(S==T){
			T=(S=_buf)+fread(_buf,1,L,stdin);
			return*S++;
		}
		return*S++;
	}
	void gi(int&x){
	    for(c=gc();c<'0'||c>'9';c=gc());
	    for(x=c&15,c=gc();c>='0'&&c<='9';c=gc())x=x*10+(c&15);
	}
	char buf[25],*outs=buf+20,*outr=buf+20;
	inline void print(register int a,register char x=0){
	    if(x)*--outs=x;
	    if(!a)*--outs='0';
	    else while(a)*--outs=(a%10)+48,a/=10;
	    fwrite(outs,outr-outs,1,stdout);outs=outr;
	}
};

using IO::gi;
using IO::print;

int lm;

namespace ST{
	typedef pair<int,int>pii;
	const int N=600005,M=6;
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
	pii ttp[M*2+1];int tl,pl;
	data operator+(data x,data y){
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
		num[x]=num[ls]+num[rs];
	}
	void cover(int x,int l,int r,int s,int t,int u){
		if(l==s&&r==t)return addtag(x,l,r,u);
		pushdown(x,l,r);
		int ls=x<<1,rs=ls|1,mid=(l+r)>>1;
		if(t<=mid)cover(ls,l,mid,s,t,u);
		else if(s>mid)cover(rs,mid+1,r,s,t,u);
		else cover(ls,l,mid,s,mid,u),cover(rs,mid+1,r,mid+1,t,u);
		num[x]=num[ls]+num[rs];
	}
	data ask(int x,int l,int r,int s,int t){
		if(l==s&&r==t)return num[x];
		pushdown(x,l,r);
		int mid=(l+r)>>1,ls=x<<1,rs=ls|1;
		if(t<=mid)return ask(ls,l,mid,s,t);
		if(s>mid)return ask(rs,mid+1,r,s,t);
		return ask(ls,l,mid,s,mid)+ask(rs,mid+1,r,mid+1,t);
	}
};

using ST::data;
using ST::cover;
using ST::ask;
using ST::build;

const int N=150005;
int n,m,p,a[N];

void op(data x){
	int l=0,i;
	while(x.top[l]&&l<lm)l++;
	print(l,' ');
	for(i=0,l--;i<=l;i++)print(x.top[i]," \n"[i==l]);
}

int main(){
	gi(n),gi(m),gi(p);
	lm=100/p;
	for(int i=1;i<=n;i++)gi(a[i]);
	build(1,1,n,a);
	for(int i=1,o,l,r,x;i<=m;i++){
		gi(o),gi(l),gi(r);
		if(o==1)gi(x),cover(1,1,n,l,r,x);
		else op(ask(1,1,n,l,r));
	}
	return 0;
}