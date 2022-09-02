#include<bits/stdc++.h>
#define PB push_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef vector<int>VI;
typedef long long LL;
const int N=200005,K=20;
struct SAM{
	int lst,cnt,len[N],fa[N],ch[N][26],pos[N];
	VI G[N];
	SAM(){lst=cnt=1;}
	void push(int c,int x){
		int p=lst,np=lst=pos[x]=++cnt;len[np]=len[p]+1;
		for(;p&&!ch[p][c];p=fa[p])ch[p][c]=np;
		if(!p){fa[np]=1;return;}
		int q=ch[p][c];
		if(len[p]+1==len[q]){fa[np]=q;return;}
		int nq=++cnt;len[nq]=len[p]+1;
		memcpy(ch[nq],ch[q],sizeof(ch[q]));
		fa[nq]=fa[q],fa[q]=fa[np]=nq;
		for(;p&&ch[p][c]==q;p=fa[p])ch[p][c]=nq;
	}
	void bud(){
		rep(i,2,cnt)G[fa[i]].PB(i);
	}
}A,B;
char s[N];
int n,dep[N],fa[N][K],ind,tin[N],dfn[N],id[N];LL ans[N],res;
struct cmp{
	bool operator()(const int&x,const int&y){return tin[x]<tin[y];}
};
set<int,cmp>S[N];
VI H[N];
void dfs(int k1){
	fa[k1][0]=B.fa[k1],dep[k1]=dep[fa[k1][0]]+1,tin[k1]=++ind;
	for(int i=1;i<K;++i)fa[k1][i]=fa[fa[k1][i-1]][i-1];
	for(auto j:B.G[k1]){
		dfs(j);
	}
}
int lca(int k1,int k2){
	if(dep[k1]<dep[k2])swap(k1,k2);int k3=dep[k1]-dep[k2];
	per(i,K-1,0)if(k3>>i&1)k1=fa[k1][i];if(k1==k2)return k1;
	per(i,K-1,0)if(fa[k1][i]!=fa[k2][i])k1=fa[k1][i],k2=fa[k2][i];return fa[k1][0];
}
void add(int k1,int k2){
	auto it=S[id[k1]].insert(k2).first,jt=it;
	int t=0;
	if(it!=S[id[k1]].begin()){
		t=lca(*--it,k2);
	}
	if((++jt)!=S[id[k1]].end()){
		int tt=lca(*jt,k2);
		if(!t||dep[tt]>dep[t])t=tt;
	}
	if(t!=-1)ans[id[k1]]+=B.len[k2]-B.len[t];
}
void mer(int k1,int k2){
	if(SZ(S[id[k1]])<SZ(S[id[k2]]))swap(id[k1],id[k2]);
	for(auto x:S[id[k2]]){
		add(k1,x);
	}
	S[id[k2]].clear(),ans[id[k2]]=0;
}
void dfs2(int k1){
	for(auto j:A.G[k1]){
		dfs2(j);
		mer(k1,j);
	}
	for(auto x:H[k1])add(k1,x);
	res+=1LL*(A.len[k1]-A.len[A.fa[k1]])*(ans[id[k1]]+1);
}
int main(){
	scanf("%s",s+1),n=strlen(s+1);
	B.len[1]=1,A.len[1]=1;
	rep(i,1,n)A.push(s[i]-'a',i);
	per(i,n,1)B.push(s[i]-'a',i);
	A.pos[0]=1,B.pos[n+1]=1;
	rep(i,0,n-1)H[A.pos[i]].PB(B.pos[i+2]);
	A.bud(),B.bud();
	dfs(1);
	rep(i,1,A.cnt)id[i]=i;
	dfs2(1);
	printf("%lld\n",res);
	return 0;
}