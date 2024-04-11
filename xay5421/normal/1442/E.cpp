#include<bits/stdc++.h>
#define PB push_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=200005;
int T,n,a[N],deg[N],d[N];
int pp,lnk[N],nxt[N*2],to[N*2];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
int sol(int x){
	rep(i,1,n)d[i]=deg[i];
	vector<int>leaf[3];
	rep(i,1,n)if(d[i]==1)leaf[a[i]].PB(i);
	int ans=0;
	while(1){
		++ans;
		while(SZ(leaf[0])||SZ(leaf[x])){
			int k1=0;
			if(SZ(leaf[0])){
				k1=leaf[0].back();
				leaf[0].pop_back();
			}else{
				k1=leaf[x].back();
				leaf[x].pop_back();
			}
			for(int i=lnk[k1];i;i=nxt[i])if(--d[to[i]]==1){
				leaf[a[to[i]]].PB(to[i]);
			}
		}
		x^=3;
		if(SZ(leaf[x])==0&&SZ(leaf[0])==0)return ans;
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,1,n)scanf("%d",&a[i]),deg[i]=0;
		rep(i,1,n-1){
			int k1,k2;
			scanf("%d%d",&k1,&k2);
			++deg[k1],++deg[k2];
			ae(k1,k2),ae(k2,k1);
		}
		printf("%d\n",min(sol(1),sol(2)));
		pp=0;
		rep(i,1,n)lnk[i]=0;
	}
	return 0;
}