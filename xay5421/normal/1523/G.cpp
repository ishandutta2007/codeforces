// author: xay5421
// created: Mon May 31 00:06:14 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#pragma GCC optimize(2,3,"Ofast")
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=100005,M=100005,B=350;
int n,m,L[M],R[M];
namespace xay1{
	int t[N];
	void upd(int k1){
		for(int i=k1;i<=n;i+=i&-i)++t[i];
	}
	int qry(int k1){
		int k2=0;
		for(int i=k1;i;i&=i-1)k2+=t[i];
		return k2;
	}
	bool vis[N];
	int sum[N];
	void sol(int len){
		rep(i,1,n)t[i]=0;
		rep(i,1,m)if(R[i]-L[i]+1>=len){
			if(qry(R[i])==(L[i]==1?0:qry(L[i]-1))){
				rep(j,L[i],R[i])upd(j);
			}
		}
		printf("%d\n",qry(n));
	}
}
namespace xay2{
	vector<int>vec[N];
	int pre[N],nxt[N],ans;
	void del(int i){
		pre[nxt[i]]=pre[i];
		nxt[pre[i]]=nxt[i];
	}
	set<pair<int,int> >S;
	bool vis[N];
	void rebud(){
		S.clear();
		ans=0;
		for(int i=nxt[0];i<=m;i=nxt[i]){
			auto it=S.lower_bound(make_pair(L[i],-1));
			if(it!=S.end()&&it->first<=R[i]){
				vis[i]=0;
				continue;
			}
			if(it!=S.begin()&&prev(it)->second>=L[i]){
				vis[i]=0;
				continue;
			}
			S.insert(make_pair(L[i],R[i]));
			vis[i]=1;
			ans+=R[i]-L[i]+1;
		}
	}
	void bud(){
		rep(i,1,m)pre[i]=i-1,nxt[i]=i+1;
		nxt[0]=1,pre[m+1]=m;
		rep(i,1,m)if(R[i]-L[i]+1<B)del(i);
		rebud();
	}
	void sol(int i){
		bool flg=0;
		for(int x:vec[i]){
			del(x);
			if(vis[x])flg=1;
		}
		if(flg)rebud();
	}
}
int main(){
	rd(n),rd(m);
	rep(i,1,m)rd(L[i]),rd(R[i]),xay2::vec[R[i]-L[i]+1].push_back(i);
	for(int i=1;i<=n&&i<B;++i){
		xay1::sol(i);
	}
	if(n>=B){
		xay2::bud();
	}
	rep(i,B,n){
		printf("%d\n",xay2::ans);
		xay2::sol(i);
	}
	return 0;
}