#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
vector<int>pos[N];
char s[N];
int n,m,cnt[N],a[N],dfn[N],low[N],bel[N],exi[N],ct,stk[N],top,num,deg[N],id[N],cn,key[N],vis[N];
vector<int>gr1[N],gr2[N];
pair<int,int>seg[N];
void tarjan(int x){
	dfn[x]=low[x]=++ct;
	stk[++top]=x;exi[x]=1;
	for(int v:gr1[x]){
		if(!dfn[v])tarjan(v),low[x]=min(low[x],low[v]);
		else if(exi[v])low[x]=min(low[x],dfn[v]);
	}
	if(low[x]==dfn[x]){
		int tp;
		do{
			tp=stk[top--];
			exi[tp]=0;
			bel[tp]=num;
		}while(tp!=x);
		num++;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",s);
		for(int o=0;o<m;o++)if(s[o]=='#')pos[o].push_back(n-1-i);
	}
	for(int i=0;i<m;i++)scanf("%d",&a[i]);
	for(int i=0;i<m;i++)reverse(pos[i].begin(),pos[i].end());
	cnt[0]=0;
	for(int i=1;i<=m;i++)cnt[i]=cnt[i-1]+pos[i-1].size();
	for(int i=0;i<m;i++){
		for(auto it=begin(pos[i]);it!=end(pos[i]);++it){
			int id=cnt[i]+(it-begin(pos[i]));
			if(it!=begin(pos[i]))gr1[id].push_back(id-1);
			if(next(it)!=end(pos[i])&&it[1]==*it+1)gr1[id].push_back(id+1);
			if(i!=0){
				auto t=upper_bound(pos[i-1].begin(),pos[i-1].end(),*it);
				if(t!=begin(pos[i-1]))gr1[id].push_back(cnt[i-1]-1+(t-begin(pos[i-1])));
			}
			if(i+1!=m){
				auto t=upper_bound(pos[i+1].begin(),pos[i+1].end(),*it);
				if(t!=begin(pos[i+1]))gr1[id].push_back(cnt[i+1]-1+(t-begin(pos[i+1])));
			}
		}
	}
	int nc=cnt[m];
	for(int i=0;i<nc;i++){
		if(!dfn[i])tarjan(i);
	}
	for(int i=0;i<m;i++){
		if(a[i])key[bel[cnt[i]+a[i]-1]]=1;
	}
	for(int i=0;i<nc;i++){
		for(int v:gr1[i]){
			if(bel[i]!=bel[v])gr2[bel[i]].push_back(bel[v]),++deg[bel[v]];
		}
	}
	vector<int>ord;
	for(int i=0;i<num;i++)if(!deg[i])ord.push_back(i);
	for(int i=0;i<num;i++){
		int x=ord[i];
		if(vis[x])key[x]=0;
		if(key[x])vis[x]=1;
		for(int v:gr2[x]){
			--deg[v];
			if(vis[x]||key[x])vis[v]=1;
			if(!deg[v])ord.push_back(v);
		}
	}
	for(int i=0;i<num;i++)if(key[i])id[i]=cn++;
	for(auto i=rbegin(ord);i!=rend(ord);i++){
		int x=*i;
		seg[x].first=key[x]?id[x]:numeric_limits<int>::max();
		seg[x].second=key[x]?id[x]:numeric_limits<int>::min();
		for(int v:gr2[x]){
			seg[x].first=min(seg[x].first,seg[v].first);
			seg[x].second=max(seg[x].second,seg[v].second);
		}
	}
	sort(seg,seg+num);
	int R=-1,r=0,ans=0;
	for(int i=0;i<num&&R+1<cn;i++){
		r=max(r,seg[i].second);
		if(i+1==num||seg[i+1].first>R+1)ans++,R=r;
	}
	printf("%d\n",ans);
	return 0;
}