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
const int N=500005;
int n,dp[N];
char s[N];
int what[N];
struct SAM{
	int cnt,lst,fa[N*2],ch[N*2][26],len[N*2],pos[N*2],val[N*2];
	vector<int>e[N*2];
	SAM(){cnt=lst=1;}
	void ps(int c,int pos0){
		int p=lst,np=lst=++cnt; len[np]=len[p]+1,pos[np]=pos0;
		for(;p&&!ch[p][c];p=fa[p])ch[p][c]=np;
		if(!p){fa[np]=1;return;}
		int q=ch[p][c];
		if(len[p]+1==len[q]){fa[np]=q;return;}
		int nq=++cnt; len[nq]=len[p]+1;
		memcpy(ch[nq],ch[q],sizeof(ch[nq]));
		fa[nq]=fa[q],fa[q]=fa[np]=nq;
		for(;p&&ch[p][c]==q;p=fa[p])ch[p][c]=nq;
	}
	int	sz[N*2],son[N*2],bel[N*2];
	void dfs1(int k1){
		sz[k1]=1;
		for(auto x:e[k1]){
			dfs1(x);
			sz[k1]+=sz[x];
			if(sz[son[k1]]<sz[x])son[k1]=x;
		}
	}
	int ind,tin[N*2],tou[N*2],ord[N*2];
	void dfs2(int k1){
		tin[k1]=++ind,ord[ind]=k1;
		if(son[k1]){
			bel[son[k1]]=bel[k1];
			dfs2(son[k1]);
		}
		each(x,e[k1])if(x!=son[k1]){
			bel[x]=x;
			dfs2(x);
		}
		tou[k1]=ind;
	}
	void bud(){
		rep(i,2,cnt){
			e[fa[i]].pb(i);
		}
		dfs1(1);
		bel[1]=1;
		dfs2(1);
	}
	int get_good(int u){
		while(bel[u]!=1&&!val[bel[u]]){
			u=fa[bel[u]];
		}
		int l=tin[bel[u]],r=tin[u],ret=bel[u];
		while(l<=r){
			int mid=(l+r)>>1;
			if(mid==1||val[ord[mid]]){
				ret=ord[mid];
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		return ret;
	}
	int jump(int u,int x){
		while(u&&x<=len[fa[bel[u]]]){
			u=fa[bel[u]];
		}
		assert(x<=len[u]);
		int l=tin[bel[u]],r=tin[u],ret=u;
		while(l<=r){
			int mid=(l+r)>>1;
			if(x<=len[ord[mid]]){
				ret=ord[mid];
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		assert(x<=len[ret]);
		return ret;
	}
	void push(int u,int x){
		assert(x<=len[u]);
		val[u]=max(val[u],x);
		while(1){
			u=fa[u];
			if(val[u]==len[u])break;
			val[u]=len[u];
		}
	}
}A;
vector<pair<int,int> >todo[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	scanf("%s",s+1);
	reverse(s+1,s+n+1);
	rep(i,1,n){
		A.ps(s[i]-'a',i);
		what[i]=A.lst;
	}
	A.bud();
	rep(i,1,n){
		dp[i]=max(dp[i],1);
		{
			int u=A.get_good(what[i]);
			dp[i]=max(dp[i],A.val[u]+1);
		}
		for(auto&[x,w]:todo[i]){
			A.push(A.jump(what[x],w),w);
		}
		if(i<n){
			int u=A.get_good(what[i]);
			dp[i+1]=max(dp[i+1],A.val[u]+1);
		}
		if(i+dp[i]<=n){
			rep(k,0,10){
				if(i+dp[i]-k>=i)todo[i+dp[i]-k].eb(i,dp[i]-k);
			}
		}
	}
	printf("%d\n",*max_element(dp+1,dp+n+1));
	return 0;
}