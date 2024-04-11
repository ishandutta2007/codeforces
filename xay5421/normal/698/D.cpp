#include<bits/stdc++.h>
#define fi first
#define se second
#define PB push_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=1005;
int m,n,q[10];
pair<int,int>a[N],b[N];
vector<int>g[10][N];
bool vis[N];
int st[N],top;
LL cross(pair<int,int>x,pair<int,int>y){
	return 1LL*x.fi*y.se-1LL*x.se*y.fi;
}
pair<int,int>operator-(const pair<int,int>&x,const pair<int,int>&y){
	return make_pair(x.fi-y.fi,x.se-y.se);
}
bool chk(pair<int,int>x,pair<int,int>y,pair<int,int>z){
	if(z.fi<min(x.fi,y.fi)||z.fi>max(x.fi,y.fi))return 0;
	if(z.se<min(x.se,y.se)||z.se>max(x.se,y.se))return 0;
	return cross(y-x,z-x)==0;
}
int cur;
bool dfs(int k1){
	if(cur>m)return 0;
	int now=cur;
	for(auto j:g[q[now]][k1]){
		if(!vis[j]){
			++cur;
			if(!dfs(j))return 0;
		}
	}
	return vis[k1]=1,st[++top]=k1,1;
}
int main(){
	scanf("%d%d",&m,&n);
	rep(i,1,m)scanf("%d%d",&a[i].fi,&a[i].se);
	rep(i,1,n)scanf("%d%d",&b[i].fi,&b[i].se);
	rep(i,1,m)rep(j,1,n)rep(k,1,n)if(j!=k&&chk(a[i],b[j],b[k])){
		g[i][j].PB(k);
		if(SZ(g[i][j])==m)break;
	}
	int ans=0;
	rep(i,1,n){
		rep(j,1,m)q[j]=j;
		do{
			while(top)vis[st[top--]]=0;
			cur=1;
			if(dfs(i)){
				++ans;
				break;
			}
		}while(next_permutation(q+1,q+1+m));
	}
	printf("%d\n",ans);
	return 0;
}