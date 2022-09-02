// author: xay5421
// created: Thu Mar 11 16:29:53 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
typedef long long LL;
const int N=200005,K=20;
int n,Q,a[N],b[N],p[N],fa[N][K],dep[N],pd[N],cnt[N];
LL res,dp[N],c[N];
vector<int>e[N];
int LCA(int k1,int k2){
	if(dep[k1]<dep[k2])swap(k1,k2);
	int t=dep[k1]-dep[k2];
	per(i,K-1,0)if(t>>i&1)k1=fa[k1][i];
	if(k1==k2)return k1;
	per(i,K-1,0)if(fa[k1][i]!=fa[k2][i])k1=fa[k1][i],k2=fa[k2][i];
	return fa[k1][0];
}
set<int>S;
LL dist(int k1,int k2){
	return dp[k1]+dp[k2]-dp[LCA(k1,k2)]*2;
}
void ins(int k1){
	auto it=S.insert(k1).first;
	if(it!=S.begin()&&it!=--S.end())res-=dist(*prev(it),*next(it));
	if(it!=S.begin())res+=dist(*prev(it),k1);
	if(it!=--S.end())res+=dist(k1,*next(it));
}
void del(int k1){
	auto it=S.find(k1);
	if(it!=S.begin())res-=dist(*prev(it),k1);
	if(it!=--S.end())res-=dist(k1,*next(it));
	if(it!=S.begin()&&it!=--S.end())res+=dist(*prev(it),*next(it));
	S.erase(it);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(Q);
	rep(i,1,n)rd(p[i]);
	rep(i,1,n)rd(a[i]);
	rep(i,1,n)rd(b[i]);
	{
		vector<int>st;
		per(i,n,1){
			while(!st.empty()&&p[i]>p[st.back()]){
				fa[st.back()][0]=i;
				st.pop_back();
			}
			st.push_back(i);
		}
	}
	rep(j,1,K-1)rep(i,1,n)fa[i][j]=fa[fa[i][j-1]][j-1];
	rep(i,1,n)dep[i]=dep[fa[i][0]]+1,e[fa[i][0]].push_back(i);
	rep(i,0,n){
		c[i]=a[i]-b[i];
		for(int x:e[i])c[i]+=b[x];
	}
	per(i,n,0){
		dp[i]=c[i];
		for(int x:e[i])if(dp[x]<0)dp[i]+=dp[x];
	}
	rep(i,1,n)dp[i]=max(dp[i],0LL);
	rep(i,0,n)for(int x:e[i])dp[x]+=dp[i];
	S.insert(0),cnt[0]=1;
	rep(_,1,Q){
		int x;
		rd(x);
		if(!pd[x]){
			if(++cnt[fa[x][0]]==1){
				ins(fa[x][0]);
			}
		}else{
			if(--cnt[fa[x][0]]==0){
				del(fa[x][0]);
			}
		}
		pd[x]^=1;
		pt(dp[0]+(res+dist(*S.begin(),*--S.end()))/2,'\n');
	}
	return 0;
}