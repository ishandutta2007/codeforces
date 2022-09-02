#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=100005;
int n,m,c[N],eu[N],ev[N],ew[N],dep[N];
LL ans[N];
vector<tuple<int,int> >e[N];
struct ufs{
	int fa[N];
	ufs(){iota(fa,fa+N,0);}
	int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
	bool mer(int k1,int k2){
		k1=fd(k1),k2=fd(k2);
		if(k1==k2)return 0;
		fa[k1]=k2;
		return 1;
	}
}o;
LL w[N];
bool err;
void dfs1(int k1,int k2,int k3){
	dep[k1]=dep[k2]+1;
	for(auto&x:e[k1])if(get<0>(x)!=k2){
		dfs1(get<0>(x),k1,get<1>(x));
	}
	if(w[k1]!=c[k1]){
		if(k1==1){
			err=1;
		}else{
			ans[k3]=c[k1]-w[k1];
			w[k2]+=c[k1]-w[k1];
			w[k1]+=c[k1]-w[k1];
		}
	}
}
int pre[N],baba[N];
void dfs2(int k1,int k2,int k3){
	pre[k1]=k3,baba[k1]=k2;
	for(auto&x:e[k1])if(get<0>(x)!=k2){
		dfs2(get<0>(x),k1,get<1>(x));
	}
	if(w[k1]!=c[k1]){
		if(k2){
			ans[k3]=c[k1]-w[k1];
			w[k2]+=c[k1]-w[k1];
			w[k1]+=c[k1]-w[k1];
		}
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(m);
	rep(i,1,n)rd(c[i]);
	rep(i,1,m){
		rd(eu[i]),rd(ev[i]);
		if(o.mer(eu[i],ev[i])){
			e[eu[i]].eb(ev[i],i);
			e[ev[i]].eb(eu[i],i);
			ew[i]=1;
		}
	}
	dfs1(1,0,0);
	if(!err){
		puts("YES");
		rep(i,1,m){
			pt(ans[i],'\n');
		}
	}else{
		int pos=-1;
		rep(i,1,m)if(!ew[i]){
			if((dep[eu[i]]&1)==(dep[ev[i]]&1)){
				pos=i;
			}
		}
		if(pos==-1){
			puts("NO");
			exit(0);
		}else{
			memset(w,0,sizeof(w));
			memset(ans,0,sizeof(ans));
			int U=eu[pos];
			int V=ev[pos];
			dfs2(U,0,0);
			if((w[U]&1)!=(c[U]&1)){
				puts("NO");
				exit(0);
			}
			LL dt=(c[U]-w[U])/2;
			ans[pos]=dt;
			while(V!=U){
				ans[pre[V]]-=dt;
				dt=-dt;
				V=baba[V];
			}
			puts("YES");
			rep(i,1,m){
				pt(ans[i],'\n');
			}
		}
	}
	return 0;
}