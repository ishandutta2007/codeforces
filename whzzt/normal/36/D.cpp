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

int T,k,n,m;
bool fl;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	gi(T),gi(k);
	while(T--){
		gi(n),gi(m);
		if(n>m)swap(n,m);
		if(k==1)fl=(~n&1)|(~m&1);
		else if(n%(k+1)==0)fl=true;
		else fl=(n/(k+1)-n-m)&1;
		putc("-+"[fl]),putc('\n');
	}
	io::cbuf();
	return 0;
}