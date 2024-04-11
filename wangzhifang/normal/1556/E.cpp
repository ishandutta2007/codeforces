#include <cstring>
namespace templates{
	#define cs const
	#define st static
	#define il inline
	#define tpl template
	#define tpn typename
	typedef unsigned size_t;
	typedef cs size_t&cst;
	using std::memcpy;
	tpl<tpn T_node>struct segment_tree{
		T_node*tr;
		segment_tree(cst l=0):tr(new T_node[l]){}
		il ~segment_tree(){
			delete[]tr;
		}
		void build_from_input(cst now,cst l,cst r){
			if(l==r){
				tr[now].init_from_input(l);
				return;
			}
			cs size_t mdl=l+r>>1,mdr=mdl+1,lsn=now<<1,rsn=lsn|1;
			build_from_input(lsn,l,mdl),build_from_input(rsn,mdr,r);
			tr[now].init_pushup(tr[lsn],tr[rsn],l,mdl,mdr,r);
		}
		il void build_from_input(cst n){
			build_from_input(1,1,n);
		}
		tpl<tpn T_val>T_val query_range(cst now,cst l,cst r,cst lft,cst rgt){
			if(lft<=l&&r<=rgt)
				return tr[now].template query_range<T_val>(l,r);
			cs size_t mdl=l+r>>1,mdr=mdl+1,lsn=now<<1,rsn=lsn|1;
			tr[now].pushdown(tr[lsn],tr[rsn],l,mdl,mdr,r);
			return lft<=mdl?(mdl<rgt?T_val::merge(query_range<T_val>(lsn,l,mdl,lft,rgt),query_range<T_val>(rsn,mdr,r,lft,rgt)):query_range<T_val>(lsn,l,mdl,lft,rgt)):query_range<T_val>(rsn,mdr,r,lft,rgt);
		}
		tpl<tpn T_val>T_val query_range(cst n,cst lft,cst rgt){
			return query_range<T_val>(1,1,n,lft,rgt);
		}
	};
	#undef cs
	#undef st
	#undef il
	#undef tpl
	#undef tpn
}
#include <cstdio>
#include <cctype>
namespace io{
	#define cs const
	#define il inline
	#define tpl template
	#define tpn typename
	typedef cs int&ci;
	typedef unsigned size_t;
	typedef cs size_t&cst;
#ifndef ONLINE_JUDGE
	using std::getchar;
	using std::putchar;
	using std::isdigit;
#else
	const size_t _I_Buffer_Size = 1 << 23, _O_Buffer_Size = 1 << 23;
	char _I_Buffer[_I_Buffer_Size],*_I_pos=_I_Buffer-1;
    const char *_I_end=_I_Buffer + _I_Buffer_Size;
    char _O_Buffer[_O_Buffer_Size],*_O_pos=_O_Buffer-1;
    const char *_O_end=_O_Buffer + _O_Buffer_Size,*_O_preend=_O_end-1;
    struct io{
		~io(){
			fwrite(_O_Buffer,1,_O_pos-_O_Buffer+1,stdout);
		}
	}ios;
    il char getchar(){
        return *((++_I_pos==_I_end)?fread(_I_Buffer,1,_I_Buffer_Size,stdin),_I_pos=_I_Buffer:_I_pos);
    }
    il bool isdigit(ci ch){
		return '0'<=ch;
	}
    il void putchar(ci x){
        *((_O_pos==_O_preend)?fwrite(_O_Buffer,1,_O_end-_O_Buffer,stdout),_O_pos = _O_Buffer:++_O_pos)=x;
    }
#endif
	template<typename T1>void readdigit(T1&ch){
		while(!isdigit(ch=getchar()));
	}
	template<typename T1>il void readuint(T1&x){
		int ch;
		while(!isdigit(ch=getchar()));
		for(x=ch^'0'; isdigit(ch=getchar()); x=x*10+(ch^'0'));
	}
	template<typename T1,typename T2>il void readuint(T1&x,T2&y){
		int ch;
		while(!isdigit(ch=getchar()));
		for(x=ch^'0'; isdigit(ch=getchar()); x=x*10+(ch^'0'));
		while(!isdigit(ch=getchar()));
		for(y=ch^'0'; isdigit(ch=getchar()); y=y*10+(ch^'0'));
	}
	template<typename T1,typename T2,typename T3>il void readuint(T1&x1,T2&x2,T3&x3){
		int ch;
		while(!isdigit(ch=getchar()));
		for(x1=ch^'0'; isdigit(ch=getchar()); x1=x1*10+(ch^'0'));
		while(!isdigit(ch=getchar()));
		for(x2=ch^'0'; isdigit(ch=getchar()); x2=x2*10+(ch^'0'));
		while(!isdigit(ch=getchar()));
		for(x3=ch^'0'; isdigit(ch=getchar()); x3=x3*10+(ch^'0'));
	}
	template<typename T1>il void readint(T1&x){
		int ch;
		while(!isdigit(ch=getchar())&&ch!='-');
		if(ch!='-')
			for(x=ch^'0'; isdigit(ch=getchar()); x=x*10+(ch^'0'));
		else{
			for(x=getchar()^'0'; isdigit(ch=getchar()); x=x*10+(ch^'0'));
			x=-x;
		}
	}
    il void writechar(ci x){
    	putchar(x);
    }
	template<typename T>void writeuint(cs T&x){
		if(x>9)
			writeuint(x/10);
		putchar((x%10)|'0');
	}
	template<typename T>il void writelnuint(cs T&x){
		writeuint(x);
		putchar('\n');
	}
	template<typename T>void writelnint(cs T&x){
		if(x>=0)
			writeuint(x);
		else{
			putchar('-');
			writeuint(-x);
		}
		putchar('\n');
	}
	#undef cs
	#undef il
	#undef tpl
	#undef tpn
}
#include <algorithm>
using std::max;
using std::min;
using templates::segment_tree;
using io::readuint;
#define cs const
#define il inline
#define max_n 500000
typedef cs unsigned& cst;
//typedef cs int& ci;
typedef long long ll;
typedef cs ll& cll;
template<typename T>T min_(cs T&x,cs T&y){
	return x>y?y:x;
}
template<typename T>T max_(cs T&x,cs T&y){
	return x<y?y:x;
}
struct T_val1{
	typedef cs T_val1& cT_val1;
	ll lmx,lmn,rmx,amx,sum;
	il T_val1(){}
	il T_val1(cll l,cll x,cll r,cll a,cll s):lmx(l),lmn(x),rmx(r),amx(a),sum(s){}
	il static T_val1 merge(cT_val1 x,cT_val1 y){
		return T_val1(max(x.lmx,y.lmx+x.sum),min(x.lmn,x.sum+y.lmn),max(x.rmx+y.sum,y.rmx),max(max_(x.amx,y.amx),x.rmx+y.lmx),x.sum+y.sum);
	}
};
int a[max_n+1];
struct node{
	typedef cs node& cnode;
	ll lmx,lmn,rmx,amx,sum;
	il void init_from_input(cst pos){
		if(a[pos]>0)
			lmx=lmn=rmx=amx=sum=a[pos];
		else
			lmx=rmx=amx=0,lmn=sum=a[pos];
	}
	il void init_pushup(cnode lsn,cnode rsn,cst l,cst mdl,cst mdr,cst r){
		lmx=max(lsn.lmx,rsn.lmx+lsn.sum),lmn=min(lsn.lmn,lsn.sum+rsn.lmn),rmx=max(lsn.rmx+rsn.sum,rsn.rmx),sum=lsn.sum+rsn.sum,amx=max(max_(lsn.amx,rsn.amx),max_(lsn.rmx,0ll)+max_(rsn.lmx,0ll));
	}
	il void pushdown(node&lsn,node&rsn,cst l,cst mdl,cst mdr,cst r){}
	il void pushup(cnode lsn,cnode rsn,cst l,cst mdl,cst mdr,cst r){
		lmx=max(lsn.lmx,rsn.lmx+lsn.sum),lmn=min(lsn.lmn,lsn.sum+rsn.lmn),rmx=max(lsn.rmx+rsn.sum,rsn.rmx),sum=lsn.sum+rsn.sum,amx=max(max_(lsn.amx,rsn.amx),max_(lsn.rmx,0ll)+max_(rsn.lmx,0ll));
	}
	template<typename T>il T query_range(cst l,cst r)cs{}
};
template<>il T_val1 node::query_range<T_val1>(cst l,cst r)cs{
	return T_val1(lmx,lmn,rmx,amx,sum);
}
int main(){
	int n,m,l,r;
	readuint(n,m);
	for(int i=1; i<=n; ++i)
		readuint(a[i]);
	for(int i=1,x; i<=n; ++i){
		readuint(x);
		a[i]=x-a[i];
	}
	segment_tree<node>tr(n-1<<2);
	tr.build_from_input(n);
	do{//m>0
		readuint(l,r);
		const T_val1 now=tr.query_range<T_val1>(n,l,r);
		if(now.lmn<0||now.sum)
			puts("-1");
		else
			printf("%lld\n",now.amx);
	}while(--m);
	return 0;
}