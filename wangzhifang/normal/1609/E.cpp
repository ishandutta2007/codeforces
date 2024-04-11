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
	tpl<tpn T>struct bit{//Binary Indexed Tree
		typedef cs T& cT;
		T*tr;
		bit(cst l=0):tr(new T[l]){}
		il ~bit(){
			delete[]tr;
		}
		il void construct(cst l=0){
			tr=new T[l];
		}
		il void destruct(){
			delete[]tr;
		}
		il void rebuild(cst l=0){
			destruct();
			construct(l);
		}
		void build(T*a,cst n){
			memcpy(tr+1,a+1,sizeof(T)*n);
			T*ed=tr+n;
			for(int i=1,d=1; (i<<=1)<=n; d=i)
				for(T*j=tr; (j+=i)<=ed; *j+=*(j-d));
		}
		void build_(cst n){
			T*ed=tr+n;
			for(int i=1,d=1; (i<<=1)<=n; d=i)
				for(T*j=tr; (j+=i)<=ed; *j+=*(j-d));
		}
		void update_add(size_t pos,cT val,cst n){
			for(tr[pos]+=val; (pos+=lowbit(pos))<=n; tr[pos]+=val);
		}
		T query(size_t pos)cs{
#if validator1
			if(pos){
#endif
				T ret=tr[pos];
				for(; pos-=lowbit(pos); ret+=tr[pos]);
				return ret;
#if validator1
			}
			return 0;
#endif
		}
		T query(size_t l,size_t r){
#if validator1
			if(l<=r){
#endif
				T ret=tr[r];
				for(; r-=lowbit(r); ret+=tr[r]);
				if(--l)
					for(ret-=tr[l]; l-=lowbit(l); ret-=tr[l]);
				return ret;
#if validator1
			}
			return 0;
#endif
		}
		size_t lower_bound(T sum,cst n){//every element should be unsigned
			unsigned pos=0,d=1,tmp;
			for(; d<=n&&sum>tr[d]; d<<=1);
			do{
				if((tmp=pos|d)<=n){
					if(sum>tr[tmp])
						sum-=tr[tmp],pos=tmp;
					else
						break;
				}
			}
			while(d>>=1);
			for(; d>>=1; sum>tr[tmp=pos|d]&&(sum-=tr[tmp],pos=tmp));
			return pos+1;
		}
		private:
			st T lowbit(cT x){
				return x&(-x);
			}
	};
	tpl<tpn T>struct array1{
		bit<size_t>*tr;
		T*v;
		size_t siz,len,now;
		array1(cst l=0):tr(new bit<size_t>(l)),v(new T[l]),siz(l-1){}
		il ~array1(){
			delete[]v;
		}
		void construct(cst l=0){
			siz=l-1,tr->construct(l),v=new T[l];
		}
		il void destruct(){
			tr->destruct(),delete[]v;
		}
		il void rebuild(cst l=0){
			destruct();
			construct(l);
		}
		il void build(cst n,cst m,T*a){
			memcpy(v+1,a+1,n*sizeof(T));
			for(size_t*i=tr->tr+n; i>tr->tr; --i)
				*i=1;
			memset(tr->tr+n+1,0,(n-m)*sizeof(size_t));
			tr->build_(m),len=now=n;
		}
		il void build_(cst n,cst m){
			for(size_t*i=tr->tr+n; i>tr->tr; --i)
				*i=1;
			memset(tr->tr+n+1,0,(m-n)*sizeof(size_t));
			tr->build_(m),len=now=n;
		}
		il size_t get_vp(cst pos){
			return tr->lower_bound(pos,siz);
		}
		il T&operator[](cst pos){
			return v[get_vp(pos)];
		}
		il cs T&operator[](cst pos)cs{
			return v[get_vp(pos)];
		}
		il void erase(cst pos){
			tr->update_add(get_vp(pos),-1,siz),--len;
		}
		il void erase_(cst p){
			tr->update_add(p,-1,siz),--len;
		}
		il void push_back(cs T&val){
			v[++now]=val,++len;
			tr->update_add(now,1,siz);
		}
	};
	tpl<tpn T_node>struct segment_tree{
		T_node*tr;
		segment_tree(cst l=0):tr(new T_node[l]){}
		il ~segment_tree(){
			delete[]tr;
		}
		il void construct(cst l=0){
			tr=new T_node[l];
		}
		il void destruct(){
			delete[]tr;
		}
		il void rebuild(cst l=0){
			destruct();
			construct(l);
		}
		tpl<tpn T_arr>void build(cst now,cst l,cst r,T_arr*a){
			if(l==r){
				tr[now].init(l,a[l]);
				return;
			}
			cst mdl=(l+r)>>1,mdr=mdl+1,lsn=now<<1,rsn=lsn|1;
			build(lsn,l,mdl,a),build(rsn,mdr,r,a);
			tr[now].init_pushup(tr[lsn],tr[rsn],l,mdl,mdr,r);
		}
		tpl<tpn T_arr>il void build(cst n,T_arr*a){
			build(1,1,n,a);
		}
		void build_from_input(cst now,cst l,cst r){
			if(l==r){
				tr[now].init_from_input();
				return;
			}
			cst mdl=l+r>>1,mdr=mdl+1,lsn=now<<1,rsn=lsn|1;
			build_from_input(lsn,l,mdl),build_from_input(rsn,mdr,r);
			tr[now].init_pushup(tr[lsn],tr[rsn],l,mdl,mdr,r);
		}
		il void build_from_input(cst n){
			build_from_input(1,1,n);
		}
		tpl<tpn T_tg>void update_position(cst now,cst l,cst r,cst pos,cs T_tg&tg){
			if(l==r){
				tr[now].pushtag(l,r,tg);
				return;
			}
			cst mdl=(l+r)>>1,mdr=mdl+1,lsn=now<<1,rsn=lsn|1;
			tr[now].pushdown(tr[lsn],tr[rsn],l,mdl,mdr,r);
			pos<=mdl?(update_position(lsn,l,mdl,pos,tg),1):(update_position(rsn,mdr,r,pos,tg),0);
			tr[now].pushup(tr[lsn],tr[rsn],l,mdl,mdr,r);
		}
		tpl<tpn T_tg>void update_position(cst n,cst pos,cs T_tg&tg){
#if validator1
			if(1<=pos&&pos<=n)
#endif
				update_position(1,1,n,pos,tg);
		}
		tpl<tpn T_tg>void update_range(cst now,cst l,cst r,cst lft,cst rgt,cs T_tg&tg){
			if(lft<=l&&r<=rgt){
				tr[now].pushtag(l,r,tg);
				return;
			}
			cst mdl=l+r>>1,mdr=mdl+1,lsn=now<<1,rsn=lsn|1;
			tr[now].pushdown(tr[lsn],tr[rsn],l,mdl,mdr,r);
			lft<=mdl&&(update_range(lsn,l,mdl,lft,rgt,tg),1),mdl<rgt&&(update_range(rsn,mdr,r,lft,rgt,tg),1);
			tr[now].pushup(tr[lsn],tr[rsn],l,mdl,mdr,r);
		}
		tpl<tpn T_tg>void update_range(cst n,cst lft,cst rgt,cs T_tg&tg){
#if validator1
			if(1<=lft&&lft<=rgt&&rgt<=n)
#endif
				update_range(1,1,n,lft,rgt,tg);
		}
		tpl<tpn T_val>T_val query(cst now,cst l,cst r,cst lft,cst rgt){
			if(lft<=l&&r<=rgt)
				return tr[now].query(l,r);
			cst mdl=(l+r)>>1,mdr=mdl+1,lsn=now<<1,rsn=lsn|1;
			tr[now].pushdown(tr[lsn],tr[rsn],l,mdl,mdr,r);
			return lft<=mdl?(mdl<rgt?T_val::merge(query<T_val>(lsn,l,mdl,lft,rgt),query<T_val>(rsn,mdr,r,lft,rgt)):query<T_val>(lsn,l,mdl,lft,rgt)):query<T_val>(rsn,mdr,r,lft,rgt);
		}
		tpl<tpn T_val>T_val query(cst n,cst lft,cst rgt){
#if validator1
			if(1<=lft&&lft<=rgt&&rgt<=n)
#endif
				return query<T_val>(1,1,n,lft,rgt);
#if validator1
			return 0;
#endif
		}
	};
	#undef cs
	#undef st
	#undef il
	#undef tpl
	#undef tpn
}
#include <cstdio>
#include <algorithm>
#define max_n 100000
#define cs const
#define il inline
using templates::segment_tree;
using namespace std;
struct T{
	int a[3][3];
	friend T operator*(cs T&x,cs T&y){
		T z;
		memset(z.a,63,sizeof(z.a));
		for(int i=0; i<3; ++i)
			for(int j=0; j<3; ++j){
				cs int t=y.a[i][j];
				cs int*b=x.a[j];
				for(int k=0; k<3; ++k)
					if(t+b[k]<z.a[i][k])
						z.a[i][k]=t+b[k];
			}
		return z;
	}
};
typedef long long ll;
typedef cs unsigned& cst;
typedef cs T& cT;
struct node{
	typedef cs node& cnode;
	T sum;
	il void init(cst pos[[maybe_unused]],cT x){
		sum=x;
	}
	il void init_pushup(cnode lsn,cnode rsn,cst l[[maybe_unused]],cst mdl[[maybe_unused]],cst mdr[[maybe_unused]],cst r[[maybe_unused]]){
		sum=lsn.sum*rsn.sum;
	}
	il void pushtag(cst l[[maybe_unused]],cst r[[maybe_unused]],cT x){
		sum=x;
	}
	void pushdown(node&lsn[[maybe_unused]],node&rsn[[maybe_unused]],cst l[[maybe_unused]],cst mdl[[maybe_unused]],cst mdr[[maybe_unused]],cst r[[maybe_unused]]){
	}
	il void pushup(cnode lsn[[maybe_unused]],cnode rsn[[maybe_unused]],cst l[[maybe_unused]],cst mdl[[maybe_unused]],cst mdr[[maybe_unused]],cst r[[maybe_unused]]){
		sum=lsn.sum*rsn.sum;
	}
	il T query(cst l[[maybe_unused]],cst r[[maybe_unused]])cs{
		return sum;
	}
};
struct T_val{
	typedef cs T_val& cT_val;
	T sum;
	il T_val(){}
	il T_val(cT s):sum(s){}
	il operator T()cs{
		return sum;
	}
	il static T_val merge(cT_val x,cT_val y){
		return T_val(x.sum*y.sum);
	}
};
T tmp[4];
T a[max_n+1];
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1; i<4; ++i){
		memset(tmp[i].a,63,sizeof(tmp[i].a));
		tmp[i].a[0][0]=(i==1);
		tmp[i].a[1][1]=(i==2);
		tmp[i].a[2][2]=(i==3);
		tmp[i].a[1][0]=(i!=1);
		tmp[i].a[2][1]=(i!=2);
//		for(int j=0; j<3; ++j,puts(""))
//			for(int k=0; k<3; ++k)
//				printf("%d ",tmp[i].a[j][k]);
	}
	segment_tree<node>tr((n-1)<<2);
	scanf("\n");
	for(T*i=a,*ed=a+n; ++i<=ed; ){
		char x;
		scanf("%c",&x);
		*i=tmp[x-96];
	}
	/*T ans=a[1];
	for(int i=2; i<=n; ++i){
		ans=ans*a[i];
		printf("%d: \n",i);
		for(int i=0; i<3; ++i,puts(""))
			for(int j=0; j<3; ++j)
				printf("%d ",ans.a[i][j]);
	}*/
	tr.build(n,a);
	do{//q>0
		int x;
		char ch;
		scanf("%d %c",&x,&ch);
		tr.update_position(n,x,tmp[ch-96]);
		T ret=tr.query<T_val>(n,1,n);
//		for(int i=0; i<3; ++i,puts(""))
//			for(int j=0; j<3; ++j)
//				printf("%d ",ret.a[i][j]);
		printf("%d\n",min({ret.a[0][0],ret.a[1][0],ret.a[2][0]}));
	}while(--q);
	return 0;
}