#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int n,K,a[20];
bitset<2005>f[(1<<16)+0]; // naive ece
int main(){
	scanf("%d%d",&n,&K);
	rep(i,0,n-1)scanf("%d",&a[i]);
	f[0][0]=1;
	rep(i,1,(1<<n)-1){
		rep(j,0,n-1)if(i>>j&1)f[i]|=f[i^(1<<j)]<<a[j];
		per(j,2000/K,1)f[i][j]=f[i][j]|f[i][j*K];
	}
	if(!f[(1<<n)-1][1]){
		puts("NO"),exit(0);
	}
	puts("YES");
	int mask=(1<<n)-1,pos=1,dep=0;
	priority_queue<tuple<int,int> >que;
	while(mask){
		while(pos*K<=2000&&f[mask][pos*K])pos*=K,++dep;
		rep(i,0,n-1)if((mask>>i&1)&&pos>=a[i]&&f[mask^(1<<i)][pos-a[i]]){
			que.emplace(dep,a[i]);
			mask^=(1<<i),pos-=a[i];
		}
	}
	while(SZ(que)>1){
		auto u=que.top();
		que.pop();
		auto v=que.top();
		que.pop();
		assert(get<0>(u)==get<0>(u));
		printf("%d %d\n",get<1>(u),get<1>(v));
		int cur=get<1>(u)+get<1>(v),dep=get<0>(u);
		while(cur%K==0)cur/=K,--dep;
		que.emplace(dep,cur);
	}
	return 0;
}