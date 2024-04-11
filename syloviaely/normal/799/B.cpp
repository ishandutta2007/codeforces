#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
struct atom{
	int where,w;
};
int operator < (atom k1,atom k2){
	return k1.w>k2.w;
}
priority_queue<atom>Q[5];
int pd[210000],n,w[210000],a[210000],b[210000];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&w[i]);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++){
		Q[a[i]].push((atom){i,w[i]});
		Q[b[i]].push((atom){i,w[i]});
	}
	int m; scanf("%d",&m);
	for (;m;m--){
		int k1; scanf("%d",&k1); int ans=-1;
		while (!Q[k1].empty()){
			atom k=Q[k1].top(); Q[k1].pop();
			if (pd[k.where]) continue;
			pd[k.where]=1; ans=k.w; break;
		}
		printf("%d ",ans);
	}
	return 0;
}