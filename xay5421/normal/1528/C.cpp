// author: xay5421
// created: Mon May 24 22:50:46 2021
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=300005;
int n,a[N],ind,tin[N],tou[N];
vector<int>e1[N],e2[N];
void dfs1(int k1){
	tin[k1]=++ind;
	for(int x:e2[k1])dfs1(x);
	tou[k1]=ind;
}
int st[N*2][2],top;
set<pair<int,int> >S;
void ps(int l,int r){
	if(S.empty()){
		st[++top][0]=l,st[top][1]=r;
		S.insert(make_pair(l,r));
		return;
	}
	auto it=S.lower_bound(make_pair(l,0));
	if(it!=S.end()&&it->second<=r)return;
	if(it==S.end()||it->first>l)--it;
	if(it->first<=l&&it->second>=r){
		st[++top][0]=-it->first,st[top][1]=it->second;
		S.erase(it);
		st[++top][0]=l,st[top][1]=r;
		S.insert(make_pair(l,r));
	}else{
		st[++top][0]=l,st[top][1]=r;
		S.insert(make_pair(l,r));
	}
}
void roll_back(int _top){
	while(top>_top){
		if(st[top][0]<0){
			S.insert(make_pair(-st[top][0],st[top][1]));
		}else{
			S.erase(make_pair(st[top][0],st[top][1]));
		}
		--top;
	}
}
int ans;
void dfs2(int k1){
	int _top=top;
	ps(tin[k1],tou[k1]);
	ans=max(ans,SZ(S));
	for(int x:e1[k1]){
		dfs2(x);
	}
	roll_back(_top);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	int T;
	rd(T);
	while(T--){
		rd(n),ans=0,ind=0;
		roll_back(0);
		assert(S.empty());
		rep(i,1,n)e1[i].clear(),e2[i].clear();
		rep(i,2,n){
			int fa;
			rd(fa);
			e1[fa].push_back(i);
		}
		rep(i,2,n){
			int fa;
			rd(fa);
			e2[fa].push_back(i);
		}
		dfs1(1);
		dfs2(1);
		printf("%d\n",ans);
	}
	return 0;
}