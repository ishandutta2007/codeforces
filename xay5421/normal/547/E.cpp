#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define fi first
#define se second
#define D(...) fprintf(stderr,__VA_ARGS__)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef pair<int,int>PII;
typedef vector<int>VI;
typedef vector<PII>VII;
const int N=200005;
int n,q,cnt,ind,ch[N][26],que[N],fa[N],tin[N],tou[N],t[N],ans[N*3];VI lu[N],G[N];VII g[N];char s[N];
void upd(int k1,int k2){
	for(int i=k1;i<=ind;i+=i&-i)t[i]+=k2;
}
int qry(int k1){
	int k2=0;
	for(int i=k1;i;i&=i-1)k2+=t[i];
	return k2;
}
void dfs(int k1){
	tin[k1]=++ind;
	for(auto j:G[k1])if(j!=fa[k1])
		dfs(j);
	tou[k1]=ind;
}
int main(){
	scanf("%d%d",&n,&q);
	rep(i,1,n){
		scanf("%s",s+1),lu[i].resize(strlen(s+1));
		for(int k1=0,j=1;s[j];++j){
			int c=s[j]-'a';
			if(!ch[k1][c])ch[k1][c]=++cnt;
			lu[i][j-1]=k1=ch[k1][c];
		}
	}
	int he=0,ta=0;
	rep(i,0,25)if(ch[0][i])que[++ta]=ch[0][i];
	while(he!=ta){
		int k1=que[++he];
		rep(i,0,25){
			if(!ch[k1][i])ch[k1][i]=ch[fa[k1]][i];
			else que[++ta]=ch[k1][i],fa[ch[k1][i]]=ch[fa[k1]][i];
		}
	}
	rep(i,1,cnt)G[fa[i]].PB(i);//D(">>> %d %d\n",fa[i],i);
	dfs(0);
	rep(i,1,q){
		int k1,k2,k3;scanf("%d%d%d",&k1,&k2,&k3);
		g[k1-1].PB(MP(lu[k3].back(),-i));g[k2].PB(MP(lu[k3].back(),i));
	}
	rep(i,1,n){
		for(auto x:lu[i]){
//			D("upd:%d\n",tin[x]);
			upd(tin[x],1);
		}
		for(auto x:g[i]){
			int t=x.se<0?-1:1;
//			D(">>> %d %d %d %d\n",i,x.fi,qry(tou[x.fi]),qry(tin[x.fi]-1));
			ans[x.se*t]+=t*(qry(tou[x.fi])-qry(tin[x.fi]-1));
		}
	}
	rep(i,1,q)printf("%d\n",ans[i]);
	return 0;
}