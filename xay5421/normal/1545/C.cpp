// author: xay5421
// created: Sun Jul 11 23:47:49 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int P=998244353;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<typename... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<typename... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<typename... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
template<typename... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=1005;
int T,n,tt,a[N][N],vis[N][N],pd[N],cnt[N],col[N];
vector<int>e[N];
void dfs(int k1,int k2){
	col[k1]=k2;
	for(int x:e[k1])if(col[x]==-1)dfs(x,k2^1);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,1,n*2)pd[i]=0,e[i].clear(),col[i]=-1;
		rep(i,1,n*2)rep(j,1,n)scanf("%d",&a[i][j]);
		rep(j,1,n)rep(i,1,n)vis[j][i]=0;
		while(1){
			rep(j,1,n){
				rep(i,1,n*2)if(!pd[i]&&vis[j][a[i][j]]){
					pd[i]=2;
				}
			}
			rep(j,1,n){
				fill(cnt+1,cnt+1+n,0);
				rep(i,1,n*2)if(!pd[i]){
					++cnt[a[i][j]];
				}
				rep(i,1,n)if(!vis[j][i]&&cnt[i]==1){
					int pos=-1;
					rep(k,1,n*2)if(!pd[k]&&a[k][j]==i){
						pos=k;
						break;
					}
					pd[pos]=1;
					rep(k,1,n)vis[k][a[pos][k]]=1;
					goto re;
				}
			}
			rep(j,1,n){
				fill(cnt+1,cnt+1+n,0);
				rep(i,1,n*2)if(!pd[i]){
					++cnt[a[i][j]];
				}
				rep(i,1,n)if(!vis[j][i]&&cnt[i]!=2){
					assert(0);
				}
			}
			rep(j,1,n){
				static int lst[N];
				fill(lst+1,lst+1+n,0);
				rep(i,1,n*2)if(!pd[i]){
					if(!lst[a[i][j]]){
						lst[a[i][j]]=i;
					}else{
						e[i].push_back(lst[a[i][j]]);
						e[lst[a[i][j]]].push_back(i);
					}
				}
			}
			tt=1;
			rep(i,1,n*2)if(!pd[i]&&col[i]==-1)dfs(i,0),tt=ad(tt,tt);
			printf("%d\n",tt);
			rep(i,1,n*2)if(pd[i]==1)printf("%d ",i);else if(!pd[i]&&col[i]==0)printf("%d ",i);
			puts("");
			break;
			re:;
		}
	}
	return 0;
}