// author: xay5421
// created: Wed Apr 21 15:55:02 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=300005;
int n,num[N],fa[N],ind1,ind2,ind3,tin[N],tou[N],dfn[N],ord[N],cur;
LL ans;
vector<int>e[N];
void dfs(int k1,int k2){
	tin[k1]=++ind1;
	if(num[k1]>=cur){
		dfn[k1]=++ind3+cur-1;
	}
	sort(e[k1].begin(),e[k1].end(),[&](int x,int y){return num[x]<num[y];});
	for(int x:e[k1])dfs(x,k2+1);
	if(num[k1]<cur)ans+=k2;
	ord[k1]=++ind2;
	tou[k1]=ind1;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&num[i]);
	rep(i,2,n){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		fa[k2]=k1;
		e[k1].push_back(k2);
	}
	cur=max(1,num[1]-1);
	int u=-1;
	rep(i,1,n)if(num[i]==cur){u=i;break;}
	for(int i=u;i>1;){
		swap(num[i],num[fa[i]]);
		i=fa[i];
		++ans;
	}
	dfs(1,0);
	rep(i,1,n){
		if(num[i]<cur&&num[i]!=ord[i])puts("NO"),exit(0);
		else if(num[i]>=cur&&num[i]!=dfn[i])puts("NO"),exit(0);
	}
	rep(i,1,n){
		if(ord[i]==cur&&!(tin[u]<=tin[i]&&tin[i]<=tou[u]))puts("NO"),exit(0);
	}
	printf("YES\n%lld\n",ans);
	rep(i,1,n)printf("%d ",tin[i]);
	puts("");
	return 0;
}