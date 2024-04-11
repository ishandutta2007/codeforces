// author: xay5421
// created: Sun Oct 17 19:38:39 2021
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=300005;
int n,m,Q,fa[N],deg[N],u[N],v[N],dep[N];
vector<int>e[N];
int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
void dfs1(int k1,int k2){
	fa[k1]=k2,dep[k1]=dep[k2]+1;
	for(auto x:e[k1])if(x!=k2)dfs1(x,k1);
}
int main(){
	rd(n),rd(m);
	rep(i,1,n)fa[i]=i;
	rep(i,1,m){
		int k1,k2;
		rd(k1),rd(k2);
		if(fd(k1)!=fd(k2)){
			e[k1].pb(k2),e[k2].pb(k1);
			fa[fd(k1)]=fd(k2);
		}
	}
	rd(Q);
	rep(_,1,Q){
		rd(u[_]),rd(v[_]);
		++deg[u[_]],++deg[v[_]];
	}
	int tot=0;
	rep(i,1,n)if(deg[i]&1)++tot;
	if(tot>0){
		printf("NO\n%d\n",tot/2);
		exit(0);
	}else{
		puts("YES");
		memset(fa,0,sizeof(fa));
		dfs1(1,0);
		rep(_,1,Q){
			int k1=u[_],k2=v[_];
			vector<int>v1,v2;
			while(k1!=k2){
				if(dep[k1]>dep[k2])v1.pb(k1),k1=fa[k1];
				else v2.pb(k2),k2=fa[k2];
			}
			v1.pb(k1);
			while(!v2.empty())v1.pb(v2.back()),v2.pop_back();
			printf("%d\n",SZ(v1));
			for(auto x:v1)printf("%d ",x);
			puts("");
		}
	}
	return 0;
}