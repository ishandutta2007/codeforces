#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 200000
vector<int>sn[max_n+1];
int que[max_n+1];
void bfs(ci s,ci n,int*dis){
	memset(dis+1,0,n<<2);
	que[1]=s;
	for(int head=1,tail=1; head<=tail; ++head){
		int u=que[head];
		for(auto v:sn[u])
			if(s!=v&&!dis[v]){
				dis[v]=dis[u]+1;
				que[++tail]=v;
			}
	}
}
int dis1[max_n+1],dis2[max_n+1];
int a[max_n+1];
bool cmp(ci a,ci b){
	return dis2[a]-dis1[a]<dis2[b]-dis1[b];
}
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=k; ++i)
		scanf("%d",a+i);
	for(int i=1,u,v; i<=m; ++i,sn[u].push_back(v),sn[v].push_back(u))
		scanf("%d%d",&u,&v);
	bfs(1,n,dis1);
	bfs(n,n,dis2);
	sort(a+1,a+k+1,cmp);
	int mx=-2147483647,ans=0;
	for(int i=1; i<=k; ++i){
//		printf("(%d,%d)\n",dis1[a[i]],dis2[a[i]]);
		if(mx+dis1[a[i]]>ans)
			ans=mx+dis1[a[i]];
		if(dis2[a[i]]>mx)
			mx=dis2[a[i]];
	}
	printf("%d\n",min(ans+1,dis1[n]));
	return 0;
}