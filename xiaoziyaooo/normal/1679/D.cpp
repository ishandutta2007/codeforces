#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<map>
using namespace std;
const int maxn=500005;
int n,m,ans;
long long k;
int a[maxn],id[maxn],f[maxn],deg[maxn],xx[maxn],yy[maxn];
vector<int>v[maxn];
queue<int>q;
inline int cmp(int x,int y){
	return a[x]<a[y];
}
int main(){
	scanf("%d%d%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),id[i]=i;
	sort(id+1,id+1+n,cmp);
	for(int i=1,x,y;i<=m;i++)
		scanf("%d%d",&xx[i],&yy[i]);
	int L=0,R=n+1;
	while(L+1<R){
		int mid=(L+R)>>1;
		for(int i=1;i<=m;i++)
			if(a[xx[i]]<=a[id[mid]]&&a[yy[i]]<=a[id[mid]])
				deg[yy[i]]++,v[xx[i]].push_back(yy[i]);
		int tot=0;
		for(int i=1;i<=n;i++)
			if(deg[i]==0)
				q.push(i);
		while(!q.empty()){
			int x=q.front();
			q.pop(),tot++;
			for(int i=0;i<v[x].size();i++){
				int y=v[x][i];
				deg[y]--,f[y]=max(f[y],f[x]+1);
				if(deg[y]==0)
					q.push(y);
			}
		}
		for(int i=1;i<=n;i++)
			if(f[i]+1>=k){
				tot=0;
				break;
			}
		if(tot<n)
			R=mid;
		else L=mid;
		for(int i=1;i<=n;i++)
			v[i].clear(),deg[i]=f[i]=0;
	}
	if(R>n)
		puts("-1");
	else printf("%d\n",a[id[R]]);
	return 0;
}