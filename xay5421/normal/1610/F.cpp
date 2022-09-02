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
int n,m,deg[N],tt[N],ans[N];
bool ban[N*2];
vector<tuple<int,int,int> >e[2][N];
void euler(int u,int lst){
	rep(o,0,1){
		if(o)lst^=1;
		while(SZ(e[lst][u])){
			int v,id,rev;
			tie(v,id,rev)=e[lst][u].back();
			e[lst][u].pop_back();
			if(ban[id])continue;
			ban[id]=1;
			if(id<=m)ans[id]=rev?1:2;
			euler(v,lst);
		}
	}
}
int main(){
	rd(n),rd(m);
	rep(i,1,m){
		int u,v,w;
		rd(u),rd(v),rd(w);
		e[w-1][u].eb(v,i,0);
		e[w-1][v].eb(u,i,1);
		if(w==1){
			++deg[u],++deg[v];
		}
		if(w==2){
			++tt[u],++tt[v];
		}
	}
	int ans1=0;
	vector<int>v;
	rep(i,1,n)if(deg[i]&1){
		++ans1;
		if(~tt[i]&1){
			v.pb(i);
		}
	}
	rep(i,1,n)if(~deg[i]&1){
		if(tt[i]&1){
			v.pb(i);
		}
	}
	assert(~SZ(v)&1);
	int cur=m;
	for(int i=0;i<SZ(v);i+=2){
		e[0][v[i]].eb(v[i+1],++cur,0);
		e[0][v[i+1]].eb(v[i],cur,1);
	}
	rep(i,1,n)euler(i,0);
	printf("%d\n",ans1);
	rep(i,1,m)printf("%d",ans[i]);
	return 0;
}