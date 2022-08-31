#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
struct atom{
	long long t;
	int pd;
};
int operator < (atom k1,atom k2){
	return k1.t>k2.t||(k1.t==k2.t&&k1.pd>k2.pd);
}
priority_queue<atom>Q;
queue<int>rem;
int n,K,now,t[210000],d[210000];
long long ans[210000];
int main(){
	scanf("%d%d",&n,&K);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&t[i],&d[i]); Q.push((atom){t[i],i});
	}
	while (!Q.empty()){
		atom k=Q.top(); Q.pop(); //cout<<k.t<<" "<<k.pd<<endl;
		if (k.pd==0){
			ans[now]=k.t;
			if (rem.size()){
				int k1=rem.front(); rem.pop(); now=k1;
				Q.push((atom){k.t+d[k1],0});
			} else now=0;
		} else {
			if (now==0){
				now=k.pd; Q.push((atom){k.t+d[now],0});
			} else if (rem.size()<K)
				rem.push(k.pd);
			else ans[k.pd]=-1;
		}
	}
	for (int i=1;i<=n;i++) printf("%I64d ",ans[i]); printf("\n");
	return 0;
}