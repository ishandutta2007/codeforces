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
const int N=1005;
int n,a[N];
int vis[N];
set<pair<int,int> >S;
set<int>take;
int mate[N];
int dfs(int x){
	rep(i,1,n)if(x%a[i]==0){
		if(!vis[i]&&(!mate[i]||(vis[i]=1,dfs(mate[i])))){
			mate[i]=x;
			return 1;
		}
	}
	return 0;
}
int main(){
	rd(n);
	rep(i,1,n){
		rd(a[i]);
		S.emplace(a[i],a[i]);
	}
	LL ans=0;
	take.insert(0);
	int last=-1;
	while(!S.empty()){
		auto u=*S.begin();
		S.erase(S.begin());
		if(!take.count(get<0>(u)-get<1>(u))){
			continue;
		}
		if(last!=get<0>(u)){
			last=get<0>(u);
			fill(vis+1,vis+n+1,0);
			if(dfs(get<0>(u))){
				take.insert(get<0>(u));
				ans+=get<0>(u);
			}
		}
		S.insert(make_pair(get<0>(u)+get<1>(u),get<1>(u)));
	}
	printf("%lld\n",ans);
	return 0;
}