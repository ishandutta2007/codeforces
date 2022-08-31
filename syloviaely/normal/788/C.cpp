#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int w[1100],n,K,m;
struct atom{
	int w,where;
};
int operator < (atom k1,atom k2){
	return k1.w>k2.w;
}
int d[2100],pd[2100];
priority_queue<atom>Q;
int main(){
	scanf("%d%d",&n,&K); m=1000;
	for (;K;K--){
		int k1; scanf("%d",&k1); w[k1]=1;
	}
	memset(d,0xff,sizeof d);
	for (int i=0;i<=m;i++)
		if (w[i]){
			d[1000+i-n]=1; Q.push((atom){d[1000+i-n],1000+i-n});
		}
	while (!Q.empty()){
		atom k=Q.top(); Q.pop();
		if (pd[k.where]) continue;
		if (k.where==1000){
			printf("%d\n",k.w); return 0;
		}
		pd[k.where]=1;
		if (k.where>=1000){
			for (int i=0;i<=n;i++){
				if (w[i]==0) continue;
				int j=k.where+i-n;
				if (d[j]<k.w+1){
					d[j]=k.w+1; Q.push((atom){k.w+1,j});
				}
			}
		} else {
			for (int i=n;i<=1000;i++){
				if (w[i]==0) continue;
				int j=k.where+i-n;
				if (d[j]<k.w+1){
					d[j]=k.w+1; Q.push((atom){k.w+1,j});
				}
			}
		}
	}
	printf("-1\n");
}