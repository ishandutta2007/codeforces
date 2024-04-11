#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int INF=0X3F3F3F3F;
int main(){
	int n;
	scanf("%d",&n);
	vector<LL>a(n);
	rep(i,0,n-1){
		scanf("%lld",&a[i]);
		if(a[i]==0)--i,--n;
	}
	vector<int>f(1<<n,0);
	vector<LL>sum(1<<n,0);
	rep(i,0,(1<<n)-1)rep(j,0,n-1){
		if((i>>j)&1)continue;
		sum[i|(1<<j)]=sum[i]+a[j];
	}
	auto chk=[&](int s){
		int cnt=__builtin_popcount(s);
		if((cnt&1)==(sum[s]&1))return 0;
		for(int i=s&(s-1);i;--i&=s)if(abs(sum[s]-2*sum[i])<cnt)return 1;
		return 0;
	};
	rep(i,1,(1<<n)-1){
		if(chk(i)){
			f[i]=1;
		}
		for(int j=(i-1)&i;j;--j&=i){
			f[i]=max(f[i],f[j]+f[i-j]);
		}
	}
	printf("%d\n",n-f[(1<<n)-1]);
	return 0;
}