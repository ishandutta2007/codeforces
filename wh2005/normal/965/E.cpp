#include <bits/stdc++.h>
using namespace std;
int n;char s[100009];
int t[100009][26],tot;
int flag[100009],d[100009];
void add(){
	int len=strlen(s),k=0;
	for(int i=0;i<len;i++){
		if(!t[k][s[i]-'a']) t[k][s[i]-'a']=++tot;
		k=t[k][s[i]-'a'],d[k]=i+1;
	}
	flag[k]=1;
}
priority_queue<int >q[100009];
void dfs(int u){
	for(int i=0;i<26;i++){
		if(!t[u][i]) continue;
		int v=t[u][i];dfs(v);
		while(!q[v].empty()){
			q[u].push(q[v].top());q[v].pop();
		}
	}
	if(flag[u]) q[u].push(d[u]);
	if(!flag[u]&&!q[u].empty()){
		int v=q[u].top();q[u].pop();
		q[u].push(d[u]);
	}
}
int main() {
	memset(flag,0,sizeof(flag));
	memset(t,0,sizeof(t));
	scanf("%d",&n);tot=0;
	for(int i=1;i<=n;i++){scanf("%s",s);add();}
	flag[0]=1;dfs(0);
	long long ans=0;
	while(!q[0].empty()){
		ans+=q[0].top();q[0].pop();
	}
	printf("%lld\n",ans);
	return 0;
}