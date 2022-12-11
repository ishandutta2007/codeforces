#include<bits/stdc++.h>
using namespace std;
struct edge{
	int to,nex;
};
edge ed[2000005];
int cnt,h[600005],n,co[600005],re[10];
void add(int st,int et){
	cnt++;
	ed[cnt].to=et;
	ed[cnt].nex=h[st];
	h[st]=cnt;
}
void dfs(int x,int fa){
	if(x<=n)re[co[x]]++;
	for(int i=h[x];i;i=ed[i].nex){
		int v=ed[i].to;
		if(v==fa)continue;
		if(co[v]==co[x]){
			re[0]=-1;
		}
		if(!co[v]){
			co[v]=3-co[x];
			dfs(v,x);
		}
		if(re[0]==-1)return;
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(h,0,sizeof h);
		memset(co,0,sizeof co);
		cnt=0;
		int m,ct;
		scanf("%d%d",&n,&m);
		ct=n+1;
		for(int i=1;i<=m;i++){
			int x,y;
			string s;
			scanf("%d%d\n",&x,&y);
			cin>>s;
			if(s[0]=='i'){
				add(y,x);
				add(x,y);
			}
			else{
				add(y,++ct);
				add(ct,y);
				add(ct,x);
				add(x,ct);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(!co[i]){
				re[2]=re[1]=re[0]=0;
				co[i]=1;
				dfs(i,0);
				if(re[0]==-1){
					ans=-1;
					break;
				}
				if(ans==-1)break;
				ans+=max(re[1],re[2]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}