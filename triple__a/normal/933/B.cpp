#include<bits/stdc++.h>

using namespace std;

const int maxn = 10007;

typedef long long LL;

LL p;
int k,n=0;
LL ans[maxn],c[maxn];

int main(){
	memset(c,0,sizeof(c));
	memset(ans,0,sizeof(ans));
	scanf("%lld%d",&p,&k);
	ans[0]=p;
	bool fg=0;
	while(p){
		p=p/k-(p%k!=0&&p<0);
		p*=-1;
		c[n++]=p;
	}
	for (int i=0;i<n;++i){
		ans[i+1]+=c[i];
		ans[i]+=k*c[i];
	}
	printf("%d\n",n);
	for (int i=0;i<n;++i){
		printf("%lld ",ans[i]);
	}
	return 0;
}