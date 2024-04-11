#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
using LL=long long;
using ULL=unsigned long long;
class dsu{
public:
	int n;
	vector<int>fa;
	vector<int>sz;
	dsu(){}
	dsu(int n_):n(n_),fa(n_),sz(n_,0){
		iota(fa.begin(),fa.end(),0);
	}
	void assign(int n_){
		*this=dsu(n_);
	}
	int find(int u){
		return fa[u]==u?u:fa[u]=find(fa[u]);
	}
	bool check(int u,int v){
		return find(u)==find(v);
	}
	bool unite(int u,int v){
		int u_=find(u);
		int v_=find(v);
		if(u_!=v_){
			sz[v_]+=sz[u_];
			fa[u_]=v_;
			return 1;
		}
		return 0;
	}
};
const int N=300005;
int n,x[N],y[N],a[N],b[N];
vector<pair<int,int> >e[N*2];
int dep[N*2];
vector<vector<int> >all;
bool tmp;
void to_x(int i,int z){
	if(y[i]==z)swap(x[i],y[i]);
}
int dfs(int u,int f,bool is){
	// DD(u);
	vector<int>v;
	if(f){
		v.pb(f);
	}
	int to=-1;
	each(x,e[u])if(get<1>(x)!=f){
		if(!dep[get<0>(x)]){
			dep[get<0>(x)]=dep[u]+1;
			if(dfs(get<0>(x),get<1>(x),0)){
				v.pb(get<1>(x));
				to=get<0>(x);
			}
		}else if(dep[get<0>(x)]<=dep[u]){
			v.pb(get<1>(x));
		}
	}
	// DD(u,v);
	if(SZ(v)>=3&&tmp){
		tmp=0;
		int k1=v.back();
		v.pop_back();
		int k2=v.back();
		v.pop_back();
		int k3=v.back();
		v.pop_back();
		to_x(k1,u);
		to_x(k2,u);
		to_x(k3,u);
		all.pb(vector<int>{k1,k2,k3});
	}
	while(SZ(v)>=2){
		int k1=v.back();
		v.pop_back();
		int k2=v.back();
		v.pop_back();
		to_x(k1,u);
		to_x(k2,u);
		all.pb(vector<int>{k1,k2});
	}
	// DD(u,v);
	if(SZ(v)&&is){
		assert(tmp);
		if(!all.empty()){
			int k1=-1,k2=-1,ok=0;
			each(i,all.back()){
				if(x[i]==u||y[i]==u){
					k2=k1;
					k1=i;
					ok=1;
				}else{
					if(k1==-1)k1=i;
					else k2=i;
				}
			}
			if(!ok){
				k1=k2=-1;
				each(i,all.back()){
					if(x[i]==to||y[i]==to){
						k2=k1;
						k1=i;
						ok=1;
					}else{
						if(k1==-1)k1=i;
						else k2=i;
					}
				}
				if(!ok)return 1;
				if(ok){
					all.back()={v[0],k1,k2};
					to_x(v[0],to);
					swap(x[k1],y[k1]);
					swap(x[k2],y[k2]);
				}
			}else{
				all.back()={v[0],k1,k2};
				to_x(v[0],u);
				swap(x[k1],y[k1]);
				swap(x[k2],y[k2]);
			}
			return 0;
		}
	}
	return SZ(v)==1;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n);
	dsu o(n*2+1);
	rep(i,1,n){
		rd(x[i]),rd(y[i]);
		e[x[i]].eb(y[i],i);
		if(x[i]!=y[i])e[y[i]].eb(x[i],i);
		o.unite(x[i],y[i]);
		++o.sz[o.find(x[i])];
	}
	rep(i,1,n*2)if(o.find(i)==i){
		dep[i]=1;
		if(o.sz[i]&1)tmp=1;else tmp=0;
		if(dfs(i,0,1)){
			puts("-1"),exit(0);
		}
	}
	printf("%d %d\n\n",2,n);
	int u=0;
	each(v,all){
		if(SZ(v)==2){
			a[u+1]=x[v[0]];
			a[u+2]=y[v[0]];
			b[u+1]=y[v[1]];
			b[u+2]=x[v[1]];
			u+=2;
		}else{
			a[u+1]=x[v[0]];
			a[u+2]=y[v[0]];
			a[u+3]=x[v[1]];
			b[u+3]=y[v[1]];
			b[u+2]=x[v[2]];
			b[u+1]=y[v[2]];
			u+=3;
		}
	}
	rep(i,1,n)printf("%d%c",a[i],i==n?'\n':' ');
	rep(i,1,n)printf("%d%c",b[i],i==n?'\n':' ');
	puts("");
	
	each(v,all){
		if(SZ(v)==2){
			printf("LR");
		}else{
			printf("LRU");
		}
	}
	puts("");
	each(v,all){
		if(SZ(v)==2){
			printf("LR");
		}else{
			printf("LRD");
		}
	}
	puts("");
	puts("");
	each(v,all){
		if(SZ(v)==2){
			printf("UU");
		}else{
			printf("ULR");
		}
	}
	puts("");
	each(v,all){
		if(SZ(v)==2){
			printf("DD");
		}else{
			printf("DLR");
		}
	}
	puts("");
	
	return 0;
}