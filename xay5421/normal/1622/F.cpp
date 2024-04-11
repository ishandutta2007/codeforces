#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using ULL=unsigned long long;
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const int N=1000005;
int n,p[N];
ULL f[N],g[N];
bool ban[N];
void sieve(){
	ban[0]=ban[1]=1;
	rep(i,2,N-1){
		if(!ban[i]){
			p[++*p]=i;
			f[i]=rng();
		}
		for(int j=1;j<=*p&&i*p[j]<N;++j){
			ban[i*p[j]]=1;
			f[i*p[j]]=f[i]^f[p[j]];
			if(i%p[j]==0)break;
		}
	}
	rep(i,1,N-1){
		g[i]=g[i-1]^f[i];
	}
}
int main(){
	sieve();
	scanf("%d",&n);
	ULL all=0;
	rep(i,1,n){
		all^=g[i];
	}
	if(all==0){
		printf("%d\n",n);
		rep(i,1,n)printf("%d ",i);
		puts("");
		exit(0);
	}
	rep(i,1,n){
		if(g[i]==all){
			printf("%d\n",n-1);
			rep(j,1,n)if(j!=i)printf("%d ",j);
			puts("");
			exit(0);
		}
	}
	map<ULL,int>mp;
	rep(i,1,n){
		if(mp.count(all^g[i])){
			printf("%d\n",n-2);
			int i_=mp[all^g[i]];
			rep(j,1,n)if(j!=i_&&j!=i)printf("%d ",j);
			puts("");
			exit(0);
		}
		mp[g[i]]=i;
	}
	mp.clear();
	all^=g[n];
	rep(i,1,n-1){
		if(mp.count(all^g[i])){
			printf("%d\n",n-3);
			int i_=mp[all^g[i]];
			rep(j,1,n-1)if(j!=i_&&j!=i)printf("%d ",j);
			puts("");
			exit(0);
		}
		mp[g[i]]=i;
	}
	assert(0);
	return 0;
}