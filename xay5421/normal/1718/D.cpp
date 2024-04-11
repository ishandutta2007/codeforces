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
const int N=300005,INF=0X3F3F3F3F;
int T,n,K,Q,p[N],a[N],num[N],st[N],top,lc[N],rc[N],low[N],high[N];
void dfs(int u,int high){
	if(!u)return;
	::high[u]=high;
	if(lc[u]){
		dfs(lc[u],a[u]?a[u]:high);
	}
	if(rc[u]){
		dfs(rc[u],a[u]?a[u]:high);
	}
	if(!a[u]){
		low[u]=max(low[lc[u]],low[rc[u]]);
	}else{
		low[u]=a[u];
	}
}
struct node{
	int l,r;
}A[N];
int len;
set<int>S;
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	low[0]=~INF;
	rd(T);
	while(T--){
		rd(n),rd(Q);
		top=0;
		rep(i,0,n)lc[i]=rc[i]=0;
		rep(i,1,n){
			rd(p[i]);
			while(top&&p[i]>p[st[top]])lc[i]=st[top--];
			rc[st[top]]=i;
			st[++top]=i;
		}
		K=0;
		rep(i,1,n)rd(a[i]),K+=a[i]==0;
		dfs(rc[0],INF);
		
		rep(i,1,K-1)rd(num[i]);
		
		bool ok=1;
		rep(i,1,n)ok&=low[i]<=high[i];
		
		len=0;
		rep(i,1,n)if(!a[i]){
			A[++len]=(node){low[i],high[i]};
		}
		assert(len==K);
		
		int lb=INF,rb=~INF;
		
		sort(A+1,A+len+1,[&](const node&lhs,const node&rhs){return lhs.r<rhs.r;});
		S.clear();
		rep(i,1,K-1)S.insert(num[i]);
		rep(i,1,len){
			auto it=S.lower_bound(A[i].l);
			if(it!=S.end()&&*it<=A[i].r){
				S.erase(it);
			}else{
				if(rb==~INF){
					rb=A[i].r;
				}else{
					ok=0;
				}
			}
		}
		
		if(ok){
			sort(A+1,A+len+1,[&](const node&lhs,const node&rhs){return lhs.l>rhs.l;});
			S.clear();
			rep(i,1,K-1)S.insert(num[i]);
			rep(i,1,len){
				auto it=S.upper_bound(A[i].r);
				if(it!=S.begin()&&*prev(it)>=A[i].l){
					S.erase(prev(it));
				}else{
					if(lb==INF){
						lb=A[i].l;
					}else{
						ok=0;
					}
				}
			}
		}
		
		while(Q--){
			int x;
			rd(x);
			puts(ok&&lb<=x&&x<=rb?"YES":"NO");
		}
	}
	return 0;
}