// author: xay5421
// created: Tue Nov  9 21:27:56 2021
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=100005;
int T,n,m,ans[N],pre[N];
bool vis[N];
vector<int>e[N];
void out(){
	puts("YES");
	rep(i,1,n)printf("%d%c",ans[i],i==n?'\n':' ');
}
bool dfs1(int k1,int k2,int k3,int k4){
	if(k1==k4){
		ans[k1]=2;
		for(auto x:e[k1])if(x!=k2){
			ans[x]=1;
		}
		return 1;
	}
	for(auto x:e[k1])if(x!=k2){
		int flg=dfs1(x,k1,k3,k4);
		if(k1==k3){
			if(flg){
				ans[k1]=2;
			}else{
				ans[x]=1;
			}
		}else{
			if(flg){
				ans[k1]=2;
				return 1;
			}
		}
	}
	return 0;
}
void dfs2(int k1,int k2,vector<int>&k3){
	k3.pb(k1);
	for(auto x:e[k1])if(x!=k2)dfs2(x,k1,k3);
}
void sol(int tc){
	rd(n),rd(m);
	rep(i,1,n)e[i].clear(),ans[i]=0,pre[i]=0,vis[i]=0;
	rep(i,1,m){
		int k1,k2;
		rd(k1),rd(k2);
		e[k1].pb(k2),e[k2].pb(k1);
	}
	rep(root,1,n)if(!vis[root]){
		vector<int>que={root};
		vis[root]=1;
		vector<int>v3;
		rep(i,0,SZ(que)-1){
			int k1=que[i];
			if(SZ(e[k1])>=4){
				ans[k1]=2;
				for(auto x:e[k1])ans[x]=1;
				out();
				return;
			}
			if(SZ(e[k1])==3){
				v3.pb(k1);
			}
			for(auto x:e[k1]){
				if(!vis[x]){
					vis[x]=1,pre[x]=k1;
					que.pb(x);
				}else if(x!=pre[k1]){
					for(int y=x;y;y=pre[y]){
						ans[y]=1;
					}
					for(int y=k1;y;y=pre[y]){
						ans[y]=1;
					}
					out();
					return;
				}
			}
		}
		if(SZ(v3)>1){
			dfs1(v3[0],0,v3[0],v3[1]);
			out();
			return;
		}
		if(SZ(v3)==1){
			int k1=v3[0];
			vector<vector<int > >vs;
			for(auto x:e[k1]){
				vs.pb(vector<int>{});
				dfs2(x,k1,vs.back());
			}
			sort(vs.begin(),vs.end(),[&](const auto&x,const auto&y){return SZ(x)>SZ(y);});
			if(SZ(vs[2])>=2){
				ans[k1]=3;
				rep(i,0,2){
					ans[vs[i][0]]=2;
					ans[vs[i][1]]=1;
				}
				out();
				return;
			}else if(SZ(vs[2])==1){
				if(SZ(vs[1])>=3){
					ans[k1]=4;
					ans[vs[2][0]]=2;
					rep(i,0,1){
						ans[vs[i][0]]=3;
						ans[vs[i][1]]=2;
						ans[vs[i][2]]=1;
					}
					out();
					return;
				}else if(SZ(vs[1])==2){
					if(SZ(vs[0])>=5){
						ans[k1]=6;
						ans[vs[2][0]]=3;
						ans[vs[1][0]]=4;
						ans[vs[1][1]]=2;
						ans[vs[0][0]]=5;
						ans[vs[0][1]]=4;
						ans[vs[0][2]]=3;
						ans[vs[0][3]]=2;
						ans[vs[0][4]]=1;
						out();
						return;
					}
				}
			}
		}
	}
	puts("NO");
}
int main(){
	rd(T);
	rep(_,1,T){
		sol(_);
	}
	return 0;
}