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
const int N=200005;
int T,n,m,a[N],deg[N],lb[N],rb[N];
LL sum[N];
vector<int>e[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n),rd(m);
		rep(i,0,n)e[i].clear();
		rep(i,1,n)rd(a[i]);
		rep(i,1,n){int x;rd(x);a[i]-=x;sum[i]=sum[i-1]+a[i];}
		rep(_,1,m){
			int l,r;
			rd(l),rd(r);
			lb[_]=l,rb[_]=r;
			deg[_]=2;
			e[l-1].pb(_);
			e[r].pb(_);
		}
		set<int>S;
		rep(i,0,n)S.insert(i);
		queue<int>q;
		rep(i,0,n)if(!sum[i])S.erase(i),q.push(i);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			each(x,e[u])if(!--deg[x]){
				for(auto it=S.lower_bound(lb[x]);it!=S.end()&&*it<=rb[x];){
					q.push(*it);
					S.erase(it++);
				}
			}
		}
		puts(S.empty()?"YES":"NO");
	}
	return 0;
}