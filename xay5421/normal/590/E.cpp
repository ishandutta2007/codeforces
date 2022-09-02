// author: xay5421
// created: Tue Sep 14 20:43:09 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=755,N_=10000005;
int n,where[N],who[N_],up[N_],fa[N_],q[N_],f[N][N],match[N];
int ind,ch[N_][2],pre[N_]; // trie
bool pd[N_];
char s[N_];
bool vis[N];
int dfs(int k1){
	if(vis[k1])return 0;
	vis[k1]=1;
	rep(i,1,n)if(f[k1][i]&&(!match[i]||dfs(match[i]))){
		match[i]=k1;
		return 1;
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	int n_=0;
	rep(i,1,n){
		scanf("%s",s);
		int k1=0;
		for(int j=0;s[j];++j){
			if(!ch[k1][s[j]&1])ch[k1][s[j]&1]=++ind,pre[ind]=k1;
			k1=ch[k1][s[j]&1];
		}
		where[i]=k1,who[k1]=i;
	}
	int he=0,ta=0;
	rep(i,0,1)if(ch[0][i])q[++ta]=ch[0][i];
	while(he!=ta){
		int k1=q[++he];
		if(who[k1]!=0)up[k1]=k1;else up[k1]=up[fa[k1]];
		rep(i,0,1){
			if(!ch[k1][i]){
				ch[k1][i]=ch[fa[k1]][i];
			}else{
				fa[ch[k1][i]]=ch[fa[k1]][i];
				q[++ta]=ch[k1][i];
			}
		}
	}
	rep(i,1,n){
		for(int k1=where[i];k1!=0;k1=pre[k1]){
			int k2=up[k1],lst=i;
			while(k2!=0){
				f[lst][who[k2]]=1;
				lst=who[k2];
				if(pd[k2])break;
				pd[k2]=1;
				k2=up[fa[k2]];
			}
		}
	}
	rep(k,1,n)rep(i,1,n)rep(j,1,n)if(f[i][k]&&f[k][j])f[i][j]=1;
	rep(i,1,n)f[i][i]=0;
	int ans=n;
	rep(i,1,n){
		fill(vis+1,vis+1+n,0);
		ans-=dfs(i);
	}
	printf("%d\n",ans);
	fill(vis+1,vis+1+n,0);
	rep(i,1,n)if(match[i])vis[match[i]]=1;
	vector<int>nd;
	rep(i,1,n)if(!vis[i])nd.push_back(i);
	fill(vis+1,vis+1+n,0);
	bool flg=1;
	while(flg){
		flg=0;
		for(auto x:nd){
			rep(y,1,n)if(f[x][y])vis[y]=1;
		}
		for(auto&x:nd){
			if(vis[x]){
				flg=1;
				while(vis[x])x=match[x];
			}
		}
	}
	for(auto x:nd)printf("%d ",x);
	return 0;
}