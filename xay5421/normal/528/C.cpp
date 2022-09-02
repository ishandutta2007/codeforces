#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define PB push_back
#define fi first
#define se second
using namespace std;
const int N=300005;
int n,m,d[N];
int pp=1,lnk[N],nxt[N*2],to[N*2];bool ban[N];
vector<pair<int,int> >ans;
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
void dfs(int k1){
	for(int&i=lnk[k1];i;i=nxt[i])if(!ban[i/2]){
		ban[i/2]=1;
		int k2=to[i];
		dfs(to[i]);
		ans.PB({k1,k2});
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int k1,k2;scanf("%d%d",&k1,&k2);
		ae(k1,k2),ae(k2,k1);
		++d[k1],++d[k2];
	}
	int lst=0;
	for(int i=1;i<=n;++i)if(d[i]&1){
		if(lst)ae(i,lst),ae(lst,i),lst=0,++m;
		else lst=i;
	}
	assert(lst==0);
	if(m&1){
		ae(1,1),ae(1,1),++m;
	}
	dfs(1);
	int f=0;
	printf("%d\n",(int)ans.size());
	while(!ans.empty()){
		if(f&1)swap(ans.back().fi,ans.back().se);
		f^=1;
		printf("%d %d\n",ans.back().fi,ans.back().se);
		ans.pop_back();
	}
	return 0;
}