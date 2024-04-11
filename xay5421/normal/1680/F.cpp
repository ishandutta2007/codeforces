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
const int N=1000005;
int T,n,m;
struct ufs{
	int fa[N],dis[N];
	void init(int n){
		rep(i,1,n)fa[i]=i,dis[i]=0;
	}
	int fd(int k1){
		if(k1!=fa[k1]){
			int k2=fa[k1];
			fa[k1]=fd(fa[k1]);
			dis[k1]^=dis[k2];
		}
		return fa[k1];
	}
	void mer(int k1,int k2,int k3){
		int k1_=fd(k1),k2_=fd(k2);
		if(k1_!=k2_){
			fa[k1_]=k2_;
			dis[k1_]=dis[k1]^dis[k2]^k3;
		}else{
			if((dis[k1]^dis[k2])!=k3){
				//throw 0;
			}
		}
	}
}o;
vector<int>e[N];
int U,V;
vector<int>nds;
int mate[N];
bool dfs1(int k1,int k2,int k3){
	if(k1==k3){nds.pb(k1);return 1;}
	each(x,e[k1])if(x!=k2)if(dfs1(x,k1,k3)){nds.pb(k1),mate[k1]=x;return 1;}
	return 0;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n),rd(m);
		o.init(n);
		rep(i,1,n)e[i].clear(),mate[i]=0;
		U=-1,V=-1;
		vector<pair<int,int> >es;
		int ddl=m+1;
		rep(i,1,m){
			int u,v;
			rd(u),rd(v);
			es.eb(u,v);
			if(o.fd(u)!=o.fd(v)){
				e[u].pb(v),e[v].pb(u);
				o.mer(u,v,1);
			}else{
				if((o.dis[u]^o.dis[v])!=1){
					nds.clear();
					dfs1(u,0,v);
					ddl=i;
					mate[v]=u;
					break;
				}
			}
		}
		if(ddl>m){
			puts("YES");
			rep(i,1,n)o.fd(i),putchar(o.dis[i]+'0');
			putchar('\n');
			continue;
		}
		o.init(n);
		each(x,es){
			if(mate[get<0>(x)]!=get<1>(x)&&mate[get<1>(x)]!=get<0>(x)){
				o.mer(get<0>(x),get<1>(x),1);
			}
		}
		bool gg=0;
		rep(i,ddl+1,m){
			int u,v;
			rd(u),rd(v);
			if(o.fd(u)!=o.fd(v)){
				o.mer(u,v,1);
			}else{
				if((o.dis[u]^o.dis[v])!=1){
					gg=1;
				}
			}
		}
		if(gg){puts("NO");continue;}
		vector<int>cf(SZ(nds),0);
		auto deal=[&](int l,int r){
			if(l<=r){
				++cf[l],--cf[r];
			}else{
				++cf[l],++cf[0],--cf[r];
			}
		};
		{
			vector<int>last(n+1,-1);
			rep(i,0,SZ(nds)-1){
				int u=o.fd(nds[i]);
				if(last[u]!=-1){
					if(o.dis[nds[last[u]]]^o.dis[nds[i]]^((i-last[u])&1)){
						deal(i,last[u]);
					}else{
						deal(last[u],i);
					}
				}
				last[u]=i;
			}
		}
		rep(i,1,SZ(nds)-1)cf[i]+=cf[i-1];
		int pos=-1;
		rep(i,0,SZ(nds)-1)if(cf[i]==0){
			pos=i;
		}
		if(pos==-1){puts("NO");continue;}
		int last=-1;
		rep(i,(pos+1)%SZ(nds),SZ(nds)-1){
			if(last!=-1){
				o.mer(last,nds[i],1);
			}
			last=nds[i];
		}
		rep(i,0,pos){
			if(last!=-1){
				o.mer(last,nds[i],1);
			}
			last=nds[i];
		}
		puts("YES");
		int root=nds[(pos+1)%SZ(nds)];
		o.fd(root);
		rep(i,1,n)o.fd(i),putchar((o.dis[i]^o.dis[root]^1)+'0');
		putchar('\n');
	}
	return 0;
}