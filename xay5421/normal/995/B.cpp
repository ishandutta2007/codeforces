#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=205;
int n,a[N],pos[N][2],deg[N],ans;
vector<int>e[N];
void work(int u,int pos){
	rep(i,1,n*2)if(a[i]==u){
		int x=i;
		while(x>pos)swap(a[x],a[x-1]),--x,++ans;
		rep(j,pos+1,n*2)if(a[j]==u){
			x=j;
			while(x>pos+1)swap(a[x],a[x-1]),--x,++ans;
			return;
		}
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n*2)scanf("%d",&a[i]);
	rep(i,1,n*2){
		if(!pos[a[i]][0])pos[a[i]][0]=i;
		else pos[a[i]][1]=i;
	}
	rep(i,1,n)rep(j,1,n)if(i!=j){
		if(pos[i][0]<pos[j][0]&&pos[i][1]<pos[j][1]){
			e[i].pb(j),++deg[j];
		}
	}
	queue<int>q;
	rep(i,1,n)if(!deg[i])q.push(i);
	int cur=1;
	while(!q.empty()){
		int u=q.front();
		work(u,cur);
		cur+=2;
		q.pop();
		for(auto&x:e[u])if(!--deg[x]){
			q.push(x);
		}
	}
	assert(cur==n*2+1);
	printf("%d\n",ans);
	return 0;
}