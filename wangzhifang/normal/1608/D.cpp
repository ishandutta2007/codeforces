#define _USE_MATH_DEFINES
#include <cmath>//pi, std::cos, std::sin
#include <cstdio>//std::fread, std::fwrite, stdin, stdout
#include <cstring>
#include <utility>//std::swap
#include <algorithm>//std::reverse, std::max
#define rg //register
#define cs const
#if __cplusplus>=201103L
#define csexpr constexpr
#else
#define csexpr cs
#endif
#define il __inline__ __attribute__((always_inline))
#define il_ inline
#define likely_bool(x) __builtin_expect((x),1)
#define unlikely_bool(x) __builtin_expect((x),0)
#ifdef M_PI
csexpr double pi=M_PI;
#else
csexpr double pi=acos(-1.0);
#endif
typedef unsigned long long ull;
typedef cs double&cd;
typedef cs unsigned& cst;
typedef unsigned int uint;
typedef cs uint& cu;
typedef uint* pu;
typedef cs uint* cpu;
typedef pu uarr;
typedef cpu cuarr;
struct cp{
	double a,b;
#if __cplusplus>=201103L
	il cp()=default;
#else
	il cp(){}
#endif
	il cp(cd x,cd y):a(x),b(y){}
	il cp operator +(cs cp &o)cs{return cp(a+o.a,b+o.b);}
	il cp operator -(cs cp &o)cs{return cp(a-o.a,b-o.b);}
	il cp operator *(cs cp &o)cs{return cp(a*o.a-b*o.b,b*o.a+a*o.b);}
	il cp operator *(cd o)cs{return cp(a*o,b*o);}
	il cp operator !()cs{return cp(a,-b);}
};
typedef cp*pcp;
typedef cs cp* cpcp;
typedef pcp cparr;
typedef cpcp ccparr;
namespace cpoly{
	il void fft(cs cparr&x,cst k,cs cparr&w){
		if(unlikely_bool(k==1))
			return;
		for(uint i=0,j=0; i<k; ++i){
			if(i>j)
				std::swap(x[i],x[j]);
			for(uint l=k>>1; (j^=l)<l; l>>=1);
		}
		w[0]=cp(1,0);
		cs cpcp xk=x+k;
		{
			for(cp *a=x,*b=x+1; a<xk; a+=2,b+=2){
				cs cp o=*b;
				*b=*a-o;
				*a=*a+o;
			}
		}
		for(uint i=2; i<k; i<<=1){
			cs cp g=cp(std::cos(pi/i),std::sin(pi/i));
			for(uint j=i; j-=2; w[j|1]=(w[j]=w[j>>1])*g);
			w[1]=g;
			for(cp *a=x,*b=x+i; a<xk; a+=i,b+=i){
				cs cp*wl=w;
				for(cs pcp c=b; a<c; ++a,++b,++wl){
					cs cp o=*b**wl;
					*b=*a-o;
					*a=*a+o;
				}
			}
		}
	}
	il void ifft(cs cparr&x,cst k,cs cparr&w){
		if(unlikely_bool(k==1))
			return;
		for(uint i=0,j=0; i<k; i++){
			if(i>j)
				std::swap(x[i],x[j]);
			for(uint l=k>>1; (j^=l)<l; l>>=1);
		}
		w[0]=cp(1,0);
		cs cpcp xk=x+k;
		{
			for(cp *a=x,*b=x+1; a<xk; a+=2,b+=2){
				cs cp o=*b;
				*b=*a-o;
				*a=*a+o;
			}
		}
		for(uint i=2; i<k; i<<=1){
			cs cp g=cp(std::cos(pi/i),-std::sin(pi/i));
			for(uint j=i; j-=2; w[j|1]=(w[j]=w[j>>1])*g);
			w[1]=g;
			for(cp *a=x,*b=x+i; a<xk; a+=i,b+=i){
				cp*wl=w;
				for(cs pcp c=b; a<c; ++a,++b,++wl){
					cs cp o=*b**wl;
					*b=*a-o;
					*a=*a+o;
				}
			}
		}
		for(uint i=0; i<k; i++)
			x[i]=cp(x[i].a/k,x[i].b/k);
	}
}
namespace zpoly{
	using cpoly::fft;
	using cpoly::ifft;
	using std::memset;
	using std::memcpy;
	il void times(cs cuarr&a,cs cuarr&b,cs uarr&c,cu n,cu m){
		uint l=(n+m)>>1,len=1;
		for(; len<=l; len<<=1);
		cp*x=new cp[len],*y=new cp[len];
		{
			cp*ed=x+(n>>1);
			cs uint*ai=a;
			for(cp*i=x; i<ed; ++ai,++i){
				i->a=*ai;
				i->b=*++ai;
			}
			ed->a=*ai;
			ed->b=(n&1)?*++ai:0;
			cs pcp xk=x+len-1;
			if(likely_bool(ed<xk))
				memset(ed+1,0,(xk-ed)*sizeof(cp));
		}
		{
			cp*ed=y+(m>>1);
			cs uint*bi=b;
			for(cp*i=y; i<ed; ++bi,++i){
				i->a=*bi;
				i->b=*++bi;
			}
			ed->a=*bi;
			ed->b=(m&1)?*++bi:0;
			cs pcp yk=y+len-1;
			if(likely_bool(ed<yk))
				memset(ed+1,0,(yk-ed)*sizeof(cp));
		}
		cp*w=new cp[len];
		fft(x,len,w);
		fft(y,len,w);
		uint hl=len>>1;
		x[0]=x[0]*y[0]+cp(x[0].b*y[0].b*2,0);
		if(len>1){
			x[hl]=x[hl]*y[hl];
			for(uint i=1,j; i<hl; ++i){
				j=len-i;
				cs cp tmp=x[i]*y[i]-(x[i]-!x[j])*(y[i]-!y[j])*(w[i]+cp(1,0))*0.25;
				x[j]=x[j]*y[j]-(x[j]-!x[i])*(y[j]-!y[i])*(cp(1,0)-w[j^len>>1])*0.25;
				x[i]=tmp;
			}
		}
		ifft(x,len,w);
		uint*now=c+(n+m);
		if((n+m)&1){
			*now=uint(x[l].b+0.5);
			--now;
		}
		*now=uint(x[l].a+0.5);
		for(cs cp*i=x+l; --i>=x; ){
			*--now=uint(i->b+0.5);
			*--now=uint(i->a+0.5);
		}
	}
	il void times_eq(cs uarr&a,cs cuarr&b,cu n,cu m){
		uint l=(n+m)>>1,len=1;
		for(; len<=l; len<<=1);
		cp*x=new cp[len],*y=new cp[len];
		{
			cp*ed=x+(n>>1);
			cs uint*ai=a;
			for(cp*i=x; i<ed; ++ai,++i){
				i->a=*ai;
				i->b=*++ai;
			}
			ed->a=*ai;
			ed->b=(n&1)?*++ai:0;
			cs pcp xk=x+len-1;
			if(likely_bool(ed<xk))
				memset(ed+1,0,(xk-ed)*sizeof(cp));
		}
		{
			cp*ed=y+(m>>1);
			cs uint*bi=b;
			for(cp*i=y; i<ed; ++bi,++i){
				i->a=*bi;
				i->b=*++bi;
			}
			ed->a=*bi;
			ed->b=(m&1)?*++bi:0;
			cs pcp yk=y+len-1;
			if(likely_bool(ed<yk))
				memset(ed+1,0,(yk-ed)*sizeof(cp));
		}
		cp*w=new cp[len];
		fft(x,len,w);
		fft(y,len,w);
		uint hl=len>>1;
		x[0]=x[0]*y[0]+cp(x[0].b*y[0].b*2,0);
		if(len>1){
			x[hl]=x[hl]*y[hl];
			for(uint i=1,j; i<hl; ++i){
				j=len-i;
				cs cp tmp=x[i]*y[i]-(x[i]-!x[j])*(y[i]-!y[j])*(w[i]+cp(1,0))*0.25;
				x[j]=x[j]*y[j]-(x[j]-!x[i])*(y[j]-!y[i])*(cp(1,0)-w[j^len>>1])*0.25;
				x[i]=tmp;
			}
		}
		ifft(x,len,w);
		uint*now=a+(n+m);
		if((n+m)&1){
			*now=uint(x[l].b+0.5);
			--now;
		}
		*now=uint(x[l].a+0.5);
		for(cs cp*i=x+l; --i>=x; ){
			*--now=uint(i->b+0.5);
			*--now=uint(i->a+0.5);
		}
	}
}
namespace f_998244353_poly{
	#define tpl template
	#define tpn typename
	#define mod 998244353
	#define lim 8388608
	#define blk 4194304
	using std::memset;
	using std::memcpy;
	il ull quickpow(ull x,uint k,ull ret=1){
		for(; k; k>>=1,x=x*x%mod)
			if(k&1)
				ret=ret*x%mod;
		return ret;
	}
	il_ void mod1(uint&x){
		x>=mod&&(x-=mod);
	}
	il_ void mod2(uint&x){
		int(x)<0&&(x+=mod);
	}
	il_ void getw(cs uarr&w,cu l){
		for(uint i=l>>1,wi; i; w[i>>=1]=wi)
			wi=quickpow(3,499122176/i);
		for(uint i=1,ed=l>>1; i<ed; i<<=1){
			cs cpu c=w+i;
			cs ull wi=*c;
			for(pu a=w,b=w+i; (++b,++a)<c; *b=*a*wi%mod);
		}
		w[0]=1;
	}
	il_ void getiw_with_w(cs uarr&w,cu l){
		if(l>=4){
			w[1]=mod-w[1];
			for(uint i=2,ed=l>>1; i<ed; i<<=1)
				for(pu a=w+i,b=w+(i<<1); --b>a; ++a){
					cs uint o=*a;
					*a=mod-*b;
					*b=mod-o;
				}
		}
	}
	il_ void ntt_with_w(cs uarr&x,cu l,cs cuarr&w){
		cs cpu xl=x+l;
		for(uint i=l; i>>=1; ){
			cpu wl=w;
			for(pu a=x,b=x+i; a<xl; a+=i,b+=i,++wl){
				cs ull w=*wl;
				for(cs cpu c=b; a<c; ++a,++b){
					cs uint o=*b*w%mod;
					mod2(*b=*a-o);
					mod1(*a+=o);
				}
			}
		}
	}
	il_ void intt_with_iw(cs uarr&x,cu l,cs cuarr&w){
		cs cpu xl=x+l;
		for(uint i=1; i<l; i<<=1){
			cpu wl=w;
			for(pu a=x,b=x+i; a<xl; a+=i,b+=i,++wl){
				cs ull w=*wl;
				for(cs cpu c=b; a<c; ++a,++b){
					cs uint o=*b;
					*b=(*a-o+mod)*w%mod;
					mod1(*a+=o);
				}
			}
		}
		ull iv=quickpow(l,998244351);
		for(uint*i=x+l; --i>=x; *i=*i*iv%mod);
	}
	il_ void ntt(cs uarr&x,cu l,cs uarr&w){
		getw(w,l);
		ntt_with_w(x,l,w);
	}
	il_ void intt(cs uarr&x,cu l,cs uarr&w){
		getw(w,l);
		getiw_with_w(w,l);
		intt_with_iw(x,l,w);
	}
	il uint getl(uint l){
		if(unlikely_bool(!l))
			l=1;
		else{
			for(uint tmp; (tmp=l&(l-1)); l=tmp);
			l<<=1;
		}
		return l;
	}
	il void times_eq_non_const_wel_small_1(cs uarr&a,cs uarr&b,cu l){//with enough length, small enough (l <= 2^23)
		cs pu w=new uint[l];
		getw(w,l);
		ntt_with_w(a,l,w);
		ntt_with_w(b,l,w);
		for(uint*ai=a+l,*bi=b+l; (--bi,--ai)>=a; *ai=ull(*ai)**bi%mod);
		getiw_with_w(w,l);
		intt_with_iw(a,l,w);
		delete[]w;
	}
	il void times_eq_non_const_wel_small(cs uarr&a,cs uarr&b,cu n,cu m,cu l){//with enough length, small enough (l <= 2^23)
		memset(a+n+1,0,(l-n-1)<<2);
		memset(b+m+1,0,(l-m-1)<<2);
		times_eq_non_const_wel_small_1(a,b,l);
	}
	il void times_eq_non_const_wel_small(cs uarr&a,cs uarr&b,cu n,cu m){//with enough length, small enough (l <= 2^23)
		times_eq_non_const_wel_small(a,b,n,m,getl(n+m));
	}
	il void times_non_const_wel_small(cs uarr&a,cs uarr&b,cs uarr&c,cu n,cu m,cu l){//with enough length, small enough (l <= 2^23)
		times_eq_non_const_wel_small(a,b,n,m,l);
		memcpy(c,a,(n+m+1)<<2);
	}
	il void times_non_const_wel_small(cs uarr&a,cs uarr&b,cs uarr&c,cu n,cu m){//with enough length, small enough (l <= 2^23)
		times_non_const_wel_small(a,b,c,n,m,getl(n+m));
	}
	tpl<tpn T_iita,tpn T_iitb,tpn T_oitc>il void times_big(cu n,cu m,T_iita&iita,T_iitb&iitb,T_oitc&oitc){//with enough length, big enough (l > 2^23)
		uint nb=n/blk,mb=m/blk;
		cs uarr a=new uint[(nb+1)*lim],b=new uint[(mb+1)*lim];
		cs uarr w=new uint[lim];
		getw(w,lim);
		cs pu anb=a+nb*lim,bmb=b+mb*lim;
		{
			cs pu an=a+((n<<1)-n%blk);
			uint*x=a;
			for(; (x+blk)<=an; x+=blk){
				for(cs pu ed=x+blk; x<ed; ++x,++iita)
					*x=*iita;
				memset(x,0,blk<<2);
				ntt_with_w(x-blk,lim,w);
			}
			for(; x<=an; ++x,++iita)
				*x=*iita;
			memset(x,0,lim-(x-anb));
			ntt_with_w(anb,lim,w);
		}
		{
			cs pu bm=b+((m<<1)-m%blk);
			uint*x=b;
			for(; (x+blk)<=bm; x+=blk){
				for(cs pu ed=x+blk; x<ed; ++x,++iitb)
					*x=*iitb;
				memset(x,0,blk<<2);
				ntt_with_w(x-blk,lim,w);
			}
			for(; x<=bm; ++x,++iitb)
				*x=*iitb;
			memset(x,0,lim-(x-bmb));
			ntt_with_w(bmb,lim,w);
		}
		cs pu now=new uint[lim],prv=new uint[blk];
		memset(prv,0,blk<<2);
		getiw_with_w(w,lim);
		if(nb<=mb){
			for(uint i=0; i<=nb; ++i){
				memset(now,0,lim<<2);
				for(uint*x=a,*y=b+i*lim; y>=b; y-=lim<<1)
					for(pu ed=x+lim,t=now; x<ed; ++x,++y,++t)
						*t=(*t+ull(*x)**y)%mod;
				intt_with_iw(now,lim,w);
				for(uint i=0; i<blk; ++i,++oitc){
					uint x=now[i]+prv[i];
					mod1(x);
					*oitc=x;
				}
				memcpy(prv,now+blk,blk<<2);
			}
			if(likely_bool(nb)){
				for(uint i=1,ed=mb-nb; i<=ed; ++i){
					memset(now,0,lim<<2);
					for(uint*x=anb,*y=b+i*lim; x>=a; x-=lim<<1)
						for(pu ed=x+lim,t=now; x<ed; ++x,++y,++t)
							*t=(*t+ull(*x)**y)%mod;
					intt_with_iw(now,lim,w);
					for(uint i=0; i<blk; ++i,++oitc){
						uint x=now[i]+prv[i];
						mod1(x);
						*oitc=x;
					}
					memcpy(prv,now+blk,blk<<2);
				}
				for(uint i=nb; --i; ){
					memset(now,0,lim<<2);
					for(uint*x=anb-i*lim,*y=bmb; x<=anb; y-=lim<<1)
						for(pu ed=x+lim,t=now; x<ed; ++x,++y,++t)
							*t=(*t+ull(*x)**y)%mod;
					intt_with_iw(now,lim,w);
					for(uint i=0; i<blk; ++i,++oitc){
						uint x=now[i]+prv[i];
						mod1(x);
						*oitc=x;
					}
					memcpy(prv,now+blk,blk<<2);
				}
			}
			else{
				for(uint i=1,ed=mb-nb; i<ed; ++i){
					memset(now,0,lim<<2);
					for(uint*x=anb,*y=b+i*lim; x>=a; x-=lim<<1)
						for(pu ed=x+lim,t=now; x<ed; ++x,++y,++t)
							*t=(*t+ull(*x)**y)%mod;
					intt_with_iw(now,lim,w);
					for(uint i=0; i<blk; ++i,++oitc){
						uint x=now[i]+prv[i];
						mod1(x);
						*oitc=x;
					}
					memcpy(prv,now+blk,blk<<2);
				}
			}
			for(uint*x=anb,*y=bmb,*t=now,*ed=anb+lim; x<ed; ++x,++y,++t)
				*t=ull(*x)**y%mod;
			intt_with_iw(now,lim,w);
			uint exl=n+m-blk*(nb+mb);
			if(exl<blk){
				for(uint i=0; i<=exl; ++i,++oitc){
					uint x=now[i]+prv[i];
					mod1(x);
					*oitc=x;
				}
			}
			else{
				for(uint i=0; i<blk; ++i,++oitc){
					uint x=now[i]+prv[i];
					mod1(x);
					*oitc=x;
				}
				for(uint*i=now+blk,*ed=now+exl; i<=ed; ++i,++oitc)
					*oitc=*i;
			}
		}
		else{
			for(uint i=0; i<=mb; ++i){
				memset(now,0,lim<<2);
				for(uint*x=b,*y=a+i*lim; y>=a; y-=lim<<1)
					for(pu ed=x+lim,t=now; x<ed; ++x,++y,++t)
						*t=(*t+ull(*x)**y)%mod;
				intt_with_iw(now,lim,w);
				for(uint i=0; i<blk; ++i,++oitc){
					uint x=now[i]+prv[i];
					mod1(x);
					*oitc=x;
				}
				memcpy(prv,now+blk,blk<<2);
			}
			if(likely_bool(mb)){
				for(uint i=1,ed=nb-mb; i<=ed; ++i){
					memset(now,0,lim<<2);
					for(uint*x=bmb,*y=a+i*lim; x>=b; x-=lim<<1)
						for(pu ed=x+lim,t=now; x<ed; ++x,++y,++t)
							*t=(*t+ull(*x)**y)%mod;
					intt_with_iw(now,lim,w);
					for(uint i=0; i<blk; ++i,++oitc){
						uint x=now[i]+prv[i];
						mod1(x);
						*oitc=x;
					}
					memcpy(prv,now+blk,blk<<2);
				}
				for(uint i=mb; --i; ){
					memset(now,0,lim<<2);
					for(uint*x=bmb-i*lim,*y=anb; x<=bmb; y-=lim<<1)
						for(pu ed=x+lim,t=now; x<ed; ++x,++y,++t)
							*t=(*t+ull(*x)**y)%mod;
					intt_with_iw(now,lim,w);
					for(uint i=0; i<blk; ++i,++oitc){
						uint x=now[i]+prv[i];
						mod1(x);
						*oitc=x;
					}
					memcpy(prv,now+blk,blk<<2);
				}
			}
			else{
				for(uint i=1,ed=nb-mb; i<ed; ++i){
					memset(now,0,lim<<2);
					for(uint*x=bmb,*y=a+i*lim; x>=b; x-=lim<<1)
						for(pu ed=x+lim,t=now; x<ed; ++x,++y,++t)
							*t=(*t+ull(*x)**y)%mod;
					intt_with_iw(now,lim,w);
					for(uint i=0; i<blk; ++i,++oitc){
						uint x=now[i]+prv[i];
						mod1(x);
						*oitc=x;
					}
					memcpy(prv,now+blk,blk<<2);
				}
			}
			for(uint*x=bmb,*y=anb,*t=now,*ed=bmb+lim; x<ed; ++x,++y,++t)
				*t=ull(*x)**y%mod;
			intt_with_iw(now,lim,w);
			uint exl=n+m-blk*(mb+nb);
			if(exl<blk){
				for(uint i=0; i<=exl; ++i,++oitc){
					uint x=now[i]+prv[i];
					mod1(x);
					*oitc=x;
				}
			}
			else{
				for(uint i=0; i<blk; ++i,++oitc){
					uint x=now[i]+prv[i];
					mod1(x);
					*oitc=x;
				}
				for(uint*i=now+blk,*ed=now+exl; i<=ed; ++i,++oitc)
					*oitc=*i;
			}
		}
		delete[]w,
		delete[]now,delete[]prv;
	}
	il void times_big_fbstd(cu n,cu m){//big enough (l > 2^23)
		using std::fread;
		using std::fwrite;
		uint nb=n/blk,mb=m/blk;
		cs uarr a=new uint[(nb+1)*lim],b=new uint[(mb+1)*lim];
		cs uarr w=new uint[lim];
		getw(w,lim);
		cs pu anb=a+nb*lim,bmb=b+mb*lim;
		{
			cs pu an=a+((n<<1)-n%blk);
			uint*x=a;
			for(; (x+blk)<=an; x+=lim){
				fread(x,4,blk,stdin);
				memset(x+blk,0,blk<<2);
				ntt_with_w(x,lim,w);
			}
			fread(x,4,an-x+1,stdin);
			memset(an+1,0,lim-(an-x+1));
			ntt_with_w(x,lim,w);
		}
		{
			cs pu bm=b+((m<<1)-m%blk);
			uint*x=b;
			for(; (x+blk)<=bm; x+=lim){
				fread(x,4,blk,stdin);
				memset(x+blk,0,blk<<2);
				ntt_with_w(x,lim,w);
			}
			fread(x,4,bm-x+1,stdin);
			memset(bm+1,0,lim-(bm-x+1));
			ntt_with_w(x,lim,w);
		}
		cs pu now=new uint[lim],prv=new uint[blk];
		memset(prv,0,blk<<2);
		getiw_with_w(w,lim);
		if(nb<=mb){
			for(uint i=0; i<=nb; ++i){
				memset(now,0,lim<<2);
				for(uint*x=a,*y=b+i*lim; y>=b; y-=lim<<1)
					for(pu ed=x+lim,t=now; x<ed; ++x,++y,++t)
						*t=(*t+ull(*x)**y)%mod;
				intt_with_iw(now,lim,w);
				for(uint i=0; i<blk; ++i)
					mod1(now[i]+=prv[i]);
				fwrite(now,4,blk,stdout);
				memcpy(prv,now+blk,blk<<2);
			}
			if(likely_bool(nb)){
				for(uint i=1,ed=mb-nb; i<=ed; ++i){
					memset(now,0,lim<<2);
					for(uint*x=anb,*y=b+i*lim; x>=a; x-=lim<<1)
						for(pu ed=x+lim,t=now; x<ed; ++x,++y,++t)
							*t=(*t+ull(*x)**y)%mod;
					intt_with_iw(now,lim,w);
					for(uint i=0; i<blk; ++i)
						mod1(now[i]+=prv[i]);
					fwrite(now,4,blk,stdout);
					memcpy(prv,now+blk,blk<<2);
				}
				for(uint i=nb; --i; ){
					memset(now,0,lim<<2);
					for(uint*x=anb-i*lim,*y=bmb; x<=anb; y-=lim<<1)
						for(pu ed=x+lim,t=now; x<ed; ++x,++y,++t)
							*t=(*t+ull(*x)**y)%mod;
					intt_with_iw(now,lim,w);
					for(uint i=0; i<blk; ++i)
						mod1(now[i]+=prv[i]);
					fwrite(now,4,blk,stdout);
					memcpy(prv,now+blk,blk<<2);
				}
			}
			else{
				for(uint i=1,ed=mb-nb; i<ed; ++i){
					memset(now,0,lim<<2);
					for(uint*x=anb,*y=b+i*lim; x>=a; x-=lim<<1)
						for(pu ed=x+lim,t=now; x<ed; ++x,++y,++t)
							*t=(*t+ull(*x)**y)%mod;
					intt_with_iw(now,lim,w);
					for(uint i=0; i<blk; ++i)
						mod1(now[i]+=prv[i]);
					fwrite(now,4,blk,stdout);
					memcpy(prv,now+blk,blk<<2);
				}
			}
			for(uint*x=anb,*y=bmb,*t=now,*ed=anb+lim; x<ed; ++x,++y,++t)
				*t=ull(*x)**y%mod;
			intt_with_iw(now,lim,w);
			uint exl=n+m-blk*(nb+mb);
			if(exl<blk){
				for(uint i=0; i<=exl; ++i)
					mod1(now[i]+=prv[i]);
				fwrite(now,4,exl+1,stdout);
			}
			else{
				for(uint i=0; i<blk; ++i)
					mod1(now[i]+=prv[i]);
				fwrite(now,4,exl+1,stdout);
			}
		}
		else{
			for(uint i=0; i<=mb; ++i){
				memset(now,0,lim<<2);
				for(uint*x=b,*y=a+i*lim; y>=a; y-=lim<<1)
					for(pu ed=x+lim,t=now; x<ed; ++x,++y,++t)
						*t=(*t+ull(*x)**y)%mod;
				intt_with_iw(now,lim,w);
				for(uint i=0; i<blk; ++i)
					mod1(now[i]+=prv[i]);
				fwrite(now,4,blk,stdout);
				memcpy(prv,now+blk,blk<<2);
			}
			if(likely_bool(mb)){
				for(uint i=1,ed=nb-mb; i<=ed; ++i){
					memset(now,0,lim<<2);
					for(uint*x=bmb,*y=a+i*lim; x>=b; x-=lim<<1)
						for(pu ed=x+lim,t=now; x<ed; ++x,++y,++t)
							*t=(*t+ull(*x)**y)%mod;
					intt_with_iw(now,lim,w);
					for(uint i=0; i<blk; ++i)
						mod1(now[i]+=prv[i]);
					fwrite(now,4,blk,stdout);
					memcpy(prv,now+blk,blk<<2);
				}
				for(uint i=mb; --i; ){
					memset(now,0,lim<<2);
					for(uint*x=bmb-i*lim,*y=anb; x<=bmb; y-=lim<<1)
						for(pu ed=x+lim,t=now; x<ed; ++x,++y,++t)
							*t=(*t+ull(*x)**y)%mod;
					intt_with_iw(now,lim,w);
					for(uint i=0; i<blk; ++i)
						mod1(now[i]+=prv[i]);
					fwrite(now,4,blk,stdout);
					memcpy(prv,now+blk,blk<<2);
				}
			}
			else{
				for(uint i=1,ed=nb-mb; i<ed; ++i){
					memset(now,0,lim<<2);
					for(uint*x=bmb,*y=a+i*lim; x>=b; x-=lim<<1)
						for(pu ed=x+lim,t=now; x<ed; ++x,++y,++t)
							*t=(*t+ull(*x)**y)%mod;
					intt_with_iw(now,lim,w);
					for(uint i=0; i<blk; ++i)
						mod1(now[i]+=prv[i]);
					fwrite(now,4,blk,stdout);
					memcpy(prv,now+blk,blk<<2);
				}
			}
			for(uint*x=bmb,*y=anb,*t=now,*ed=bmb+lim; x<ed; ++x,++y,++t)
				*t=ull(*x)**y%mod;
			intt_with_iw(now,lim,w);
			uint exl=n+m-blk*(mb+nb);
			if(exl<blk){
				for(uint i=0; i<=exl; ++i)
					mod1(now[i]+=prv[i]);
				fwrite(now,4,exl+1,stdout);
			}
			else{
				for(uint i=0; i<blk; ++i)
					mod1(now[i]+=prv[i]);
				fwrite(now,4,exl+1,stdout);
			}
		}
		delete[]w,
		delete[]now,delete[]prv;
	}
	il void inv_small(cs cuarr&a,cs uarr&b,cu n,cu m){//small enough (l <= 2^23)
	    if(unlikely_bool(m==1))
	        b[0]=quickpow(a[0],998244351);
	    else{
	        uint l=2;
	        for(; l<m; l<<=1);
	        cs pu w=new uint[l],iw=new uint[l],f=new uint[l],g=new uint[l];
	        b[0]=quickpow(a[0],998244351);
	        getw(w,l);
	        memcpy(iw,w,(l>>1)<<2);
	        getiw_with_w(iw,l);
	        for(l=1; ; l<<=1){
	            cs uint dl=l<<1;
	            if(dl<=n)
	                memcpy(f,a,dl<<2);
	            else{
	                memcpy(f,a,(n+1)<<2);
	                memset(f+n+1,0,(dl-n-1)<<2);
	            }
	            ntt_with_w(f,dl,w);
	            memcpy(g,b,l<<2);
	            memset(g+l,0,l<<2);
	            ntt_with_w(g,dl,w);
	            for(uint*fi=f+dl,*gi=g+dl; (--gi,--fi)>=f; *fi=ull(*fi)**gi%mod);
	            intt_with_iw(f,dl,iw);
	            memset(f,0,l<<2);
	            ntt_with_w(f,dl,w);
	            for(uint*fi=f+dl,*gi=g+dl; (--gi,--fi)>=f; *fi=ull(*fi)**gi%mod);
	            intt_with_iw(f,dl,w);
	            if(dl>=m)
	                break;
	            for(uint i=l; i<dl; ++i)
	                b[i]=likely_bool(f[i])?mod-f[i]:0;
	        }
	        for(uint i=l; i<m; ++i)
	            b[i]=likely_bool(f[i])?mod-f[i]:0;
	        delete[]w,
	        delete[]iw,
	        delete[]f,
	        delete[]g;
	    }
	}
	il void derivative_eq(cs uarr&a,cu n){
		for(uint*i=a+1,*ed=a+n; i<=ed; ++i)
			*(i-1)=ull(i-a)**i%mod;
		a[n]=0;
	}
	il void integration_eq(cs uarr&a,cu n){
		ull now=1;
		for(uint i=2; i<=n; ++i)
			a[i]=a[i]*(now=now*i%mod)%mod;
		now=quickpow(now*(n+1)%mod,998244351);
		for(uint i=n+1; i; --i){
			a[i]=a[i-1]*now%mod;
			now=now*i%mod;
		}
		a[0]=0;
	}
	il void ln_eq_non_const_wel_small(cs uarr&a,cu n,cu m){
		if(unlikely_bool(!n)){
			memset(a,0,(m+1)<<2);
			return;
		}
		cs uint l=getl(n+m-2);
		cs uarr b=new uint[l];
		inv_small(a,b,n,m);
		derivative_eq(a,n);
		times_eq_non_const_wel_small(a,b,n-1,m-1,l);
		integration_eq(a,m-1);
	}
	il void kth_derivative_value_eq_wel_small(cs uarr&a,cu n,cu p){
		cs uint l=getl(n<<1);
		cs uarr b=new uint[l];
		ull now=1;
		for(uint i=2; i<=n; ++i)
			a[i]=a[i]*(now=now*i%mod)%mod;
		b[n]=now=quickpow(now,mod-2);
		for(uint i=n; i; --i)
			b[i-1]=now=now*i%mod;
		now=1;
		for(uint i=1; i<=n; ++i)
			b[i]=b[i]*(now=now*p%mod)%mod;
		std::reverse(a,a+n+1);
		times_eq_non_const_wel_small(a,b,n,n,l);
		std::reverse(a,a+n+1);
		delete[]b;
	}
	il void taylor_series_eq_wel_small(cs uarr&a,cu n,cu p){
		cs uint l=getl(n<<1);
		cs uarr b=new uint[l];
		ull now=1;
		for(uint i=2; i<=n; ++i)
			a[i]=a[i]*(now=now*i%mod)%mod;
		cs uint ifacn=b[n]=now=quickpow(now,mod-2);
		for(uint i=n; i; --i)
			b[i-1]=now=now*i%mod;
		now=1;
		for(uint i=1; i<=n; ++i)
			b[i]=b[i]*(now=now*p%mod)%mod;
		std::reverse(a,a+n+1);
		times_eq_non_const_wel_small(a,b,n,n,l);
		std::reverse(a,a+n+1);
		a[n]=a[n]*(now=ifacn)%mod;
		for(uint i=n,*j=a+n-1; i; --i,--j)
			*j=*j*(now=now*i%mod)%mod;
		delete[]b;
	}
	il void division_eq_non_const_wel_small(cs uarr&a,cs uarr&b,cu n,cu m){
		if(unlikely_bool(n<m)){
			a[0]=0;
			return;
		}
		if(unlikely_bool(!m)){
			ull iv=quickpow(b[0],mod-2);
			for(pu i=a+n; i>=a; --i)
				*i=*i*iv%mod;
			return;
		}
		cs uint n1=n-m;
		cs uint l=getl(n1<<1);
		cs uarr c=new uint[l];
		std::reverse(b,b+m+1);
		inv_small(b,c,m,n1+1);
		std::reverse(a,a+n+1);
		times_eq_non_const_wel_small(a,c,n1,n1,l);
		std::reverse(a,a+n1+1);
		delete[]c;
	}
	il void modulo_eq_non_const_wel_small(cs uarr&a,cs uarr&b,cs uarr&d,cu n,cu m){
		if(unlikely_bool(n<m)){
			d[0]=0;
			return;
		}
		if(unlikely_bool(!m)){
			ull iv=quickpow(b[0],mod-2);
			for(pu i=d+n,j=a+n; i>=d; --i,--j)
				*i=*j*iv%mod;
			a[0]=0;
			return;
		}
		cs uint n1=n-m;
		cs uint l1=getl(n1<<1);
		cs uarr c=new uint[l1];
		std::reverse(b,b+m+1);
		inv_small(b,c,m,n1+1);
		for(pu i=d,j=a+n,ed=d+n1; i<=ed; ++i,--j)
			*i=*j;
		times_eq_non_const_wel_small(d,c,n1,n1,l1);
		std::reverse(d,d+n1+1);
		std::reverse(b,b+m+1);
		cs uint l2=getl(n);
		cs uarr e=new uint[l2];
		memcpy(e,d,(n1+1)<<2);
		times_eq_non_const_wel_small(b,e,m,n1,l2);
		if(likely_bool(m))
			for(pu i=a+m-1,j=b+m-1; i>=a; --i,--j)
				mod2(*i-=*j);
		else
			a[0]=0;
		delete[]c;
		delete[]e;
	}
	il void modulo_eq_non_const_wel_small(cs uarr&a,cs uarr&b,cu n,cu m){
		if(unlikely_bool(n<m))
			return;
		if(unlikely_bool(!m)){
			a[0]=0;
			return;
		}
		cs uint n1=n-m;
		cs uint l1=getl(n1<<1);
		cs uint l2=getl(n);
		cs uarr c=new uint[l1];
		std::reverse(b,b+m+1);
		inv_small(b,c,m,n1+1);
		cs uarr d=new uint[std::max(l1,l2)];
		for(pu i=d,j=a+n,ed=d+n1; i<=ed; ++i,--j)
			*i=*j;
		times_eq_non_const_wel_small(d,c,n1,n1,l1);
		std::reverse(d,d+n1+1);
		std::reverse(b,b+m+1);
		times_eq_non_const_wel_small(b,d,m,n1,l2);
		for(pu i=a+m-1,j=b+m-1; i>=a; --i,--j)
			mod2(*i-=*j);
		delete[]c;
		delete[]d;
	}
	#undef mod
}
using namespace std;
using namespace f_998244353_poly;
constexpr int max_n=100000;
typedef unsigned int uint;
constexpr int max_l=1048576;
uint a[max_l];
uint b[max_l];
uint c[max_l];
uint w[max_l];
uint iw[max_l];
int main(){
	int n;
	scanf("%d",&n);
	int now=0,cnt1=0,cnt2=0,cnt3=0,ans=1,ans1=1,ans2=1;
	#define mod 998244353
	for(int i=1; i<=n; ++i){
		char str[5];
		scanf("\n%s",str);
		if(str[1]=='B')
			str[1]='W';
		else
			if(str[1]=='W')
				str[1]='B';
		if(str[0]==str[1]){
			if(str[0]=='?')
				++cnt3,++now,ans=ans*2%mod;
			if(str[0]=='B')
				ans2=0;
			else
				if(str[0]=='W')
					ans1=0;
		}
		else{
			if(str[0]=='?')
				if(str[1]=='W')
					++cnt1,++now,ans1=0;
				else
					++cnt2,++now,ans2=0;
			else
				if(str[1]=='?')
					if(str[0]=='B')
						++cnt1,++now,ans2=0;
					else
						++cnt2,++now,ans1=0;
				else{
					if(str[0]=='B')
						--now;
					else
						++now;
					ans=ans1=ans2=0;
				}
		}
	}
	if(now<0){
		puts("0");
		return 0;
	}
	int l=f_998244353_poly::getl(n*2);
	memset(a,0,sizeof(a)),
	memset(b,0,sizeof(b)),
	memset(c,0,sizeof(c));
	a[1]=a[2]=1;
	b[0]=b[1]=1;
	c[0]=c[2]=1,c[1]=2;
	f_998244353_poly::getw(w,l);
	f_998244353_poly::ntt_with_w(a,l,w);
	f_998244353_poly::ntt_with_w(b,l,w);
	f_998244353_poly::ntt_with_w(c,l,w);
	for(int i=0; i<l; ++i)
		a[i]=quickpow(a[i],cnt1)*quickpow(b[i],cnt2)%mod*quickpow(c[i],cnt3)%mod;
	f_998244353_poly::getiw_with_w(w,l);
	intt_with_iw(a,l,w);
	printf("%llu\n",(mod*10000ll+a[now]-ans+ans1+ans2)%mod);
	return 0;
}