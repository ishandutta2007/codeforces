#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=50005,B=7,B1=1<<B,B2=(N>>B)+5;
int n,Q,a[N],up[N],f[N][B2],dep[N],fa[N]; // up[u]:uB1
vector<int>e[N];
int st[N],top;
struct trieTree{
	int ind,ch[B1*20][2];
	void clear(){
		rep(i,1,ind){
			ch[i][0]=ch[i][1]=0;
		}
		ind=1;
	}
	void insert(int x){
		int k1=1;
		per(i,18,0){
			if(!ch[k1][x>>i&1]){
				ch[k1][x>>i&1]=++ind;
			}
			k1=ch[k1][x>>i&1];
		}
	}
	int query(int x){
		int k1=1;
		int res=0;
		per(i,18,0){
			if(ch[k1][~x>>i&1]){
				k1=ch[k1][~x>>i&1];
				res+=1<<i;
			}else{
				k1=ch[k1][x>>i&1];
			}
		}
		return res;
	}
}trie;
void dfs1(int k1,int k2){
	dep[k1]=dep[k2]+1;
	st[++top]=k1,fa[k1]=k2;
	if(top>B1){
		up[k1]=st[top-B1];
	}
	for(auto&x:e[k1])if(x!=k2){
		dfs1(x,k1);
	}
	trie.clear();
	rep(i,max(1,top-B1+1),top){
		trie.insert(a[st[i]]^(top-i));
	}
	rep(k,0,B2-1){
		f[k1][k]=trie.query(B1*k);
	}
	top-=1;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(Q);
	rep(i,1,n)rd(a[i]);
	rep(i,2,n){
		int u,v;
		rd(u),rd(v);
		e[u].pb(v),e[v].pb(u);
	}
	dfs1(1,0);
	while(Q--){
		int u,v;
		rd(u),rd(v);
		int cur=0,ans=0,tt=0;
		while(dep[v]>=dep[u]+B1){
			ans=max(ans,f[v][cur]);
			cur+=1,tt+=B1;
			v=up[v];
		}
		while(dep[v]>=dep[u]){
			ans=max(ans,a[v]^tt);
			tt+=1;
			v=fa[v];
		}
		printf("%d\n",ans);
	}
	return 0;
}