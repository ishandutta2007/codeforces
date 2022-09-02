#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
template<class T>bool umin(T&x,const T&y){return y<x?x=y,1:0;}
template<class T>bool umax(T&x,const T&y){return x<y?x=y,1:0;}
const int P=1e9+7;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<class... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<class... T>int su(int k1,T... k2){return su(k1,ad(k2...));}
template<class... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
template<class... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<class... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=100005,INF=0X3F3F3F3F;
int n,full,sz[N],f[N],root;
bool ban[N];
vector<tuple<int,int,int> >e[N];
void getrt(int k1,int k2){
	sz[k1]=1,f[k1]=0;
	for(auto&x:e[k1])if(get<0>(x)!=k2&&!ban[get<0>(x)]){
		getrt(get<0>(x),k1);
		sz[k1]+=sz[get<0>(x)];
		umax(f[k1],sz[get<0>(x)]);
	}
	umax(f[k1],full-sz[k1]);
	if(f[k1]<f[root])root=k1;
}
int seq0,big0;
struct int0{
	int x;
	LL zero;
	int val()const{
		return zero?0:x;
	}
	int0(){}
	int0(int x_){
		if(x_){
			x=x_,zero=0;
		}else{
			x=1,zero=1;
		}
	}
	int0(int x_,LL zero_){
		x=x_,zero=zero_;
	}
	int0&operator*=(const int0&rhs){
		x=mu(x,rhs.x);
		zero+=rhs.zero;
		return *this;
	}
	int0&operator/=(const int0&rhs){
		x=mu(x,po(rhs.x,P-2));
		zero-=rhs.zero;
		return *this;
	}
	int0 operator*(const int0&rhs)const{
		int0 res=*this;
		res*=rhs;
		return res;
	}
	int0 operator/(const int0&rhs)const{
		int0 res=*this;
		res/=rhs;
		return res;
	}
	int0 pow(int k){
		return int0(po(x,k),zero*k);
	}
};
int0 ans(1);
struct node{
	int a,b;
	int0 prod;
}seq[N],big[N];
struct BIT{
	const static int M=N*3;
	int0 t[M];
	int tim[M],ind;
	void clear(){
		ind+=1;
	}
	void upd(int k1,int0 k2){
		for(int i=k1;i<=n*3;i+=i&-i){
			if(tim[i]!=ind){
				tim[i]=ind;
				t[i]=int0(1);
			}
			t[i]*=k2;
		}
	}
	int0 qry(int k1){
		int0 k2(1);
		for(int i=k1;i;i&=i-1){
			if(tim[i]==ind){
				k2*=t[i];
			}
		}
		return k2;
	}
	void upd2(int k1,int0 k2){
		for(int i=k1;i;i&=i-1){
			if(tim[i]!=ind){
				tim[i]=ind;
				t[i]=int0(1);
			}
			t[i]*=k2;
		}
	}
	int0 qry2(int k1){
		int0 k2(1);
		for(int i=k1;i<=n*3;i+=i&-i){
			if(tim[i]==ind){
				k2*=t[i];
			}
		}
		return k2;
	}
}t;
struct BIT2{
	const static int M=N*3;
	int t[M];
	int tim[M],ind;
	void clear(){
		ind+=1;
	}
	void upd(int k1,int k2){
		for(int i=k1;i<=n*3;i+=i&-i){
			if(tim[i]!=ind){
				tim[i]=ind;
				t[i]=0;
			}
			t[i]+=k2;
		}
	}
	int qry(int k1){
		int k2=0;
		for(int i=k1;i;i&=i-1){
			if(tim[i]==ind){
				k2+=t[i];
			}
		}
		return k2;
	}
	void upd2(int k1,int k2){
		for(int i=k1;i;i&=i-1){
			if(tim[i]!=ind){
				tim[i]=ind;
				t[i]=0;
			}
			t[i]+=k2;
		}
	}
	int qry2(int k1){
		int k2=0;
		for(int i=k1;i<=n*3;i+=i&-i){
			if(tim[i]==ind){
				k2+=t[i];
			}
		}
		return k2;
	}
	
}t2;
void dfs1(int k1,int k2,int k3,int k4,int0 k5){
	seq[++seq0]=(node){k4-k3*3,k3*3-k4*2,k5};
	for(auto&x:e[k1])if(get<0>(x)!=k2&&!ban[get<0>(x)]){
		dfs1(get<0>(x),k1,k3+get<2>(x),k4+1,k5*int0(get<1>(x)));
	}
}
int0 calc(node seq[N],int seq0){
	int0 tmp(1);
	rep(i,1,seq0)rep(j,i+1,seq0){
		if(seq[i].a+seq[j].a<=0&&seq[i].b+seq[j].b<=0){
			tmp*=seq[i].prod*seq[j].prod;
		}
	}
	vector<node>v[2][2];
	rep(i,1,seq0){
		v[seq[i].a>0][seq[i].b>0].pb(seq[i]);
	}
	int0 res(1);
	for(auto&x:v[0][0]){
		res*=x.prod.pow(SZ(v[0][0])-1);
	}
	{
		sort(v[0][0].begin(),v[0][0].end(),[&](node&lhs,node&rhs){return -lhs.b>-rhs.b;});
		sort(v[0][1].begin(),v[0][1].end(),[&](node&lhs,node&rhs){return lhs.b>rhs.b;});
		int i=0;
		int0 now(1);
		for(auto&x:v[0][1]){
			while(i<SZ(v[0][0])&&-v[0][0][i].b>=x.b){
				now*=v[0][0][i].prod;
				++i;
			}
			res*=now*x.prod.pow(i);
		}
	}
	{
		sort(v[0][0].begin(),v[0][0].end(),[&](node&lhs,node&rhs){return -lhs.a>-rhs.a;});
		sort(v[1][0].begin(),v[1][0].end(),[&](node&lhs,node&rhs){return lhs.a>rhs.a;});
		int i=0;
		int0 now(1);
		for(auto&x:v[1][0]){
			while(i<SZ(v[0][0])&&-v[0][0][i].a>=x.a){
				now*=v[0][0][i].prod;
				++i;
			}
			res*=now*x.prod.pow(i);
		}
	}
	{
		t.clear();
		t2.clear();
		sort(v[0][1].begin(),v[0][1].end(),[&](node&lhs,node&rhs){return -lhs.a>-rhs.a;});
		int i=0;
		for(auto&x:v[1][0]){
			while(i<SZ(v[0][1])&&-v[0][1][i].a>=x.a){
				t.upd(v[0][1][i].b,v[0][1][i].prod);
				t2.upd(v[0][1][i].b,1);
				++i;
			}
			res*=t.qry(-x.b)*x.prod.pow(t2.qry(-x.b));
		}
	}
	{
		t.clear();
		t2.clear();
		sort(v[1][1].begin(),v[1][1].end(),[&](node&lhs,node&rhs){return -lhs.a>-rhs.a;});
		int i=0;
		for(auto&x:v[1][1]){
			while(i<SZ(v[0][0])&&-v[0][0][i].a>=x.a){
				t.upd2(v[0][0][i].b,v[0][0][i].prod);
				t2.upd2(v[0][0][i].b,1);
				++i;
			}
			res*=t.qry2(x.b)*x.prod.pow(t2.qry2(x.b));
		}
	}
	/*if(tmp.x!=res.x||tmp.zero!=res.zero){
		D("!\n");
	}*/
	return res;
}
void sol(int u){
	ban[u]=1;
	big0=0;
	big[++big0]=(node){0,0,1};
	for(auto&x:e[u])if(!ban[get<0>(x)]){
		seq0=0;
		dfs1(get<0>(x),u,get<2>(x),1,int0(get<1>(x)));
		ans/=calc(seq,seq0);
		rep(i,1,seq0){
			big[++big0]=seq[i];
		}
	}
	ans*=calc(big,big0);
	int old=full;
	for(auto&x:e[u])if(!ban[get<0>(x)]){
		full=sz[get<0>(x)]<sz[u]?sz[get<0>(x)]:old-sz[u];
		root=0;
		getrt(get<0>(x),0);
		sol(root);
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	rep(i,2,n){
		int u,v,x,c;
		scanf("%d%d%d%d",&u,&v,&x,&c);
		e[u].eb(v,x,c);
		e[v].eb(u,x,c);
	}
	f[0]=INF;
	full=n;
	root=0;
	getrt(1,0);
	sol(root);
	printf("%d\n",ans.val());
	return 0;
}