#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
#define PB push_back
#define EB emplace_back
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
#ifdef xay5421
const int N=15,B=3;
#else
const int N=100005,B=355;
#endif
int n,Q,ind,ch[N][26],fa[N];
LL ans[N];
vector<int>lu[N];
char s[N];
vector<pair<int,int> >que[N];
vector<int>G[N],H[N];
int nt,tin[N],tou[N],dfn[N],nt2,tin2[N],tou2[N],cnt[N][N/B+5];
void dfs1(int k1){
	tin[k1]=++nt,dfn[nt]=k1;
	for(auto j:G[k1])if(j!=fa[k1])dfs1(j);
	tou[k1]=nt;
}
void dfs2(int k1){
	tin2[k1]=++nt2;
	for(auto j:H[k1])dfs2(j);
	tou2[k1]=nt2;
}
int bel[N],bl[N/B+5],br[N/B+5],tg[N/B+5];
void dfs3(int k1,int k2){
	memcpy(cnt[k1],cnt[k2],sizeof(cnt[k1]));
	++cnt[k1][bel[tin[k1]]];
	for(auto j:H[k1]){
		dfs3(j,k1);
	}
}
void init(){
	memset(bl,-1,sizeof(bl));
	rep(i,0,max(n,nt2)+1){
		bel[i]=i/B;
		if(bl[bel[i]]==-1)bl[bel[i]]=i;
		br[bel[i]]=i;
	}
}
int weight[N],sum[N/B+5];
void add_small(int k1){
	D("add_small %d\n",k1);
	++weight[tin2[k1]];
	++sum[bel[tin2[k1]]];
	--weight[tou2[k1]+1];
	--sum[bel[tou2[k1]+1]];
}
void add_big(int k1){
	D("add_big %d\n",k1);
	++tg[k1];
}
void add(int l,int r){
	if(l>r)return;
	if(bel[l]+1>=bel[r]){
		rep(i,l,r)add_small(dfn[i]);
	}else{
		rep(i,l,br[bel[l]])add_small(dfn[i]);
		rep(i,bel[l]+1,bel[r]-1)add_big(i);
		rep(i,bl[bel[r]],r)add_small(dfn[i]);
	}
}
LL query(int k1){
	LL res=0;
	for(int i=0;i<=bel[nt2];++i){
		res+=1LL*cnt[k1][i]*tg[i];
	}
	for(int i=0;i<bel[tin2[k1]];++i){
		res+=sum[i];
	}
	for(int i=bl[bel[tin2[k1]]];i<=tin2[k1];++i){
		res+=weight[i];
	}
	return res;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&Q);
	rep(i,1,n){
		scanf("%s",s);
		int k1=0;
		for(int j=0;s[j];++j){
			if(!ch[k1][s[j]-'a'])ch[k1][s[j]-'a']=++ind,H[k1].PB(ind);
			k1=ch[k1][s[j]-'a'];
			lu[i].PB(k1);
		}
	}
	dfs2(0);
	queue<int>q;
	rep(i,0,25)if(ch[0][i])q.push(ch[0][i]),fa[ch[0][i]]=0;
	while(SZ(q)){
		int k1=q.front();
		G[fa[k1]].PB(k1);
		q.pop();
		rep(i,0,25){
			if(ch[k1][i]){
				fa[ch[k1][i]]=ch[fa[k1]][i];
				q.push(ch[k1][i]);
			}else ch[k1][i]=ch[fa[k1]][i];
		}
	}
	dfs1(0);
	init();
	dfs3(0,0);
	rep(i,1,Q){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		que[r].EB(k,i);
		que[l-1].EB(k,-i);
	}
	rep(i,1,n){
		add(tin[lu[i].back()],tou[lu[i].back()]);
		for(auto it=que[i].begin();it!=que[i].end();++it){
			if(it->se>0){
				ans[it->se]+=query(lu[it->fi].back());
			}else{
				ans[-it->se]-=query(lu[it->fi].back());
			}
		}
	}
	rep(i,1,Q){
		printf("%lld\n",ans[i]);
	}
	return 0;
}