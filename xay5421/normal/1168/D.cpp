#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>void umin(T&x,const T&y){if(y<x)x=y;}
template<class T>void umax(T&x,const T&y){if(x<y)x=y;}
using LL=long long;
const int N=150005;
int n,Q,fa[N],ch[N][2],ce[N],dep[N],dd=-1,id[N],ind,tt[N][26],son[N][2],go[N][2],baba[N];
char cc[N];
vector<int>e[N];
void dfs1(int k1){
	if(!ce[k1]){
		if(dd==-1){
			dd=dep[k1];
		}else if(dd!=dep[k1]){
			while(Q--)puts("Fou");
			exit(0);
		}
	}
	rep(i,0,ce[k1]-1){
		dep[ch[k1][i]]=dep[k1]+1;
		dfs1(ch[k1][i]);
	}
}
bool is_good(int u){
	return ce[u]==0||ce[u]==2;
}
vector<int>nds;
void dfs2(int k1){
	rep(i,0,ce[k1]-1){
		int v=ch[k1][i];
		nds.clear();
		while(ce[v]==1){
			nds.pb(v);
			v=ch[v][0];
		}
		nds.pb(v);
		++ind;
		for(auto&x:nds){
			id[x]=ind;
			baba[x]=k1;
			if(cc[x]!='?'){
				++tt[ind][cc[x]-'a'];
			}
		}
		baba[v]=k1;
		son[k1][i]=v;
		go[k1][i]=ind;
		dfs2(v);
	}
}
int dp[N][26],sum[N],errors;
void dfs3(int k1){
	rep(i,0,ce[k1]-1){
		dfs3(son[k1][i]);
		rep(j,0,25){
			umax(dp[k1][j],dp[son[k1][i]][j]+tt[go[k1][i]][j]);
		}
	}
	rep(j,0,25)sum[k1]+=dp[k1][j];
	if(sum[k1]>dd-dep[k1]){
		++errors;
	}
}
void deal(int k1){
	while(k1>0){
		if(sum[k1]>dd-dep[k1]){
			--errors;
		}
		rep(j,0,25)dp[k1][j]=0;
		rep(i,0,ce[k1]-1){
			rep(j,0,25){
				umax(dp[k1][j],dp[son[k1][i]][j]+tt[go[k1][i]][j]);
			}
		}
		sum[k1]=0;
		rep(j,0,25)sum[k1]+=dp[k1][j];
		if(sum[k1]>dd-dep[k1]){
			++errors;
		}
		k1=baba[k1];
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&Q);
	rep(i,2,n){
		scanf("%d",&fa[i]);
		while(cc[i]=getchar(),cc[i]!='?'&&!islower(cc[i]));
		ch[fa[i]][ce[fa[i]]++]=i;
	}
	dfs1(1);
	dfs2(1);
	dfs3(1);
	rep(_,1,Q){
		int k1;
		char k2;
		scanf("%d",&k1);
		while(k2=getchar(),k2!='?'&&!islower(k2));
		if(cc[k1]!='?')--tt[id[k1]][cc[k1]-'a'];
		cc[k1]=k2;
		if(cc[k1]!='?')++tt[id[k1]][cc[k1]-'a'];
		deal(baba[k1]);
		if(errors>0)puts("Fou");
		else{
			LL res=0;
			rep(i,0,25)res+=1LL*(dd-sum[1]+dp[1][i])*(i+1);
			printf("Shi %lld\n",res);
		}
	}
	return 0;
}