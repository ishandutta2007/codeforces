#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define PB push_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=100005;
int n,m,deg[N];
bool ins[N],vis[N];
vector<int>G[N],H[N];
void tarjan(int k1){
	vis[k1]=1,ins[k1]=1;
	for(auto j:G[k1]){
		if(!ins[j])H[k1].PB(j),++deg[j];
		if(!vis[j])tarjan(j);
	}
	ins[k1]=0;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		G[k1].PB(k2);
	}
	rep(i,1,n)if(!vis[i])tarjan(i);
	queue<int>q;
	rep(i,1,n)if(!deg[i])q.push(i);
	while(SZ(q)>1){
		int k1=q.front();
		q.pop();
		int k2=q.front();
		q.pop();
		printf("? %d %d\n",k1,k2);
		fflush(stdout);
		int k3;
		scanf("%d",&k3);
		if(k3)swap(k1,k2);
		q.push(k2);
		for(auto j:H[k1])if(!--deg[j])q.push(j);
	}
	printf("! %d\n",q.front());
	return 0;
}