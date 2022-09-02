// author: xay5421
// created: Wed Jun 16 23:15:51 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=100005;
int lt,rt,n,m,L[N],R[N],n1,n2,opt[N];
vector<int>e[N];
void dfs(int k1,int k2){
	if(opt[k1]==-1)opt[k1]=k2;
	else{
		if(opt[k1]!=k2)puts("IMPOSSIBLE"),exit(0);
		return;
	}
	for(int x:e[k1]){
		dfs(x,3-k2);
	}
}
int main(){
	scanf("%d%d%d%d",&lt,&rt,&n,&m);
	rep(i,1,n)scanf("%d%d",&L[i],&R[i]);
	n1=*max_element(L+1,L+1+n);
	n2=*min_element(R+1,R+1+n);
	if(n1+n2<lt){
		n1+=lt-n1-n2;
	}
	if(n1+n2>rt){
		n2-=n1+n2-rt;
	}
	if(n1<0||n2<0)puts("IMPOSSIBLE"),exit(0);
	memset(opt,-1,sizeof(opt));
	rep(i,1,m){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		e[k1].push_back(k2);
		e[k2].push_back(k1);
	}
	auto chk1=[&](int i){return L[i]<=n1&&n1<=R[i];};
	auto chk2=[&](int i){return L[i]<=n2&&n2<=R[i];};
	vector<int>nd;
	rep(i,1,n){
		if(chk1(i)&&chk2(i)){
			nd.push_back(i);
		}else if(chk1(i)){
			dfs(i,1);
		}else if(chk2(i)){
			dfs(i,2);
		}else{
			puts("IMPOSSIBLE"),exit(0);
		}
	}
	for(int x:nd)if(opt[x]==-1)dfs(x,1);
	puts("POSSIBLE");
	printf("%d %d\n",n1,n2);
	rep(i,1,n){
		assert(opt[i]!=-1);
		printf("%d",opt[i]);
	}
	return 0;
}