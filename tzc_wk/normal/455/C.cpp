#include <bits/stdc++.h>
using namespace std;
int n,m,q,f[300010],s[300010];
vector<int> g[300010];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void join(int a,int b){
    int x=find(a);
    int y=find(b);
    if(x==y)	return;
    if(s[x]<s[y])	swap(s[x], s[y]);
    f[y]=x;
    s[x]=max(s[x],(s[x]+1)/2+(s[y]+1)/2+1);
}
void dfs(int root,int cur,int prev,int dist,int &t,int &ans){
    f[cur]=root;
    if(dist>ans){
		ans=dist;
		t=cur;
    }
    for(int i=0;i<g[cur].size();i++)
        if(g[cur][i]!=prev)
            dfs(root,g[cur][i],cur,dist+1,t,ans);
}
int main(void){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)	f[i]=i;
    for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if (f[i]==i){
            int t=i,q;
            int ans=-INT_MAX;
            dfs(i,i,0,0,t,ans);
            ans=-INT_MAX;
            dfs(i,t,0,0,q,ans);
            s[i]=ans;
        }
    }
    while(q--){
		int type;
        scanf("%d", &type);
        if(type==1){
        	int a;
			scanf("%d", &a);
			int root=find(a);
            printf("%d\n",s[root]);
        }
		else{
			int a,b;
            scanf("%d%d",&a,&b);
            join(a,b);
        }
    }
    return 0;
}