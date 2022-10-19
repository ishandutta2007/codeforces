#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=2e5+10;
struct O{
	int id,v;
	inline O(int id=0,int v=0):id(id),v(v){}
};
bool operator<(O u,O v){return u.v>v.v;}
priority_queue<O> q;
int n,f[N],s[N],g;
bool vis[N];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d%d",&s[i],&g);
		f[i]=s[i]+g;
		q.push(O(i,f[i]));
	}
	while (!q.empty()){
		int u=q.top().id;q.pop();
		if (vis[u]) continue;
		if (u&&f[u-1]>f[u]+1){
			f[u-1]=f[u]+1;
			q.push(O(u-1,f[u-1]));
		}
		if (u<n&&f[u+1]>f[u]+1){
			f[u+1]=f[u]+1;
			q.push(O(u+1,f[u+1]));
		}
	}
	long long sum=0;
	for (int i=1;i<=n;++i) 
		if (f[i]<s[i]) return puts("-1"),0;
		else sum+=f[i]-s[i];
	printf("%lld\n",sum);
	for (int i=1;i<=n;++i) printf("%d ",f[i]);
}