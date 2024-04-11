#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
const int maxn=300005;
int n,m,top;
int stk[maxn],rec[maxn],fa[maxn],c[maxn];
long long f[maxn],sum[maxn];
long long ans;
vector<int>v[maxn];
string s;
void dfs(int x){
	int tot=0;
//	printf("x=%d\n",x);
	for(int i=0;i<v[x].size();i++){
		dfs(v[x][i]),f[x]+=f[v[x][i]],tot++,c[v[x][i]]=tot,sum[v[x][i]]=f[x];
//		printf("v[x][i]=%d c=%d s=%lld\n",v[x][i],c[v[x][i]],sum[v[x][i]]);
	}
	f[x]+=1ll*tot*(tot-1)/2ll+1;
}
int main(){
	scanf("%d%d",&n,&m),cin>>s,s=" "+s;
	for(int i=1;i<=n;i++)
		fa[i]=-1;
	for(int i=1;i<=n;i++){
		if(s[i]=='(')
			stk[++top]=i;
		else{
			if(top==0)
				continue;
			rec[i]=stk[top],rec[stk[top]]=i,top--,fa[i]=stk[top];
		}
	}
	for(int i=1;i<=n;i++)
		if(fa[i]!=-1){
			fa[i]=rec[fa[i]],v[fa[i]].push_back(i);
//			printf("i=(%d,%d) fa[i]=%d\n",rec[i],i,fa[i]);
		}
	dfs(0);
	for(int T=1,t,x,y;T<=m;T++){
		scanf("%d%d%d",&t,&x,&y);
//		printf("sum=%lld %lld\n",sum[y],sum[x-1]);
		ans=sum[y]-sum[x-1];
		int k=c[y]-c[x-1];
		printf("%lld\n",ans+1ll*k*(k-1)/2ll);
	}
	return 0;
}