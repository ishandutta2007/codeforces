#include<cstdio>
#include<algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);++i) 
const int N=100005;
int n,q[N];bool vis[N];
void dfs(int u){
	vis[u]=1;
	if(!vis[u*2%n])dfs(u*2%n);
	if(!vis[(u*2+1)%n])dfs((u*2+1)%n);
	q[++*q]=u;
}
int main(){
	scanf("%d",&n);
	if(n&1)puts("-1");else{
		q[++*q]=0;
		dfs(0);
		std::reverse(q+1,q+1+*q);
		rep(i,1,*q)printf("%d ",q[i]);
	}
	return 0;
}