#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int mod=998244353;
template<int mod=::mod>ll quickpow(ll x,int k,ll ret=1){
	for(; k; k>>=1,x=x*x%mod)
		(k&1)&&(ret=ret*x%mod);
	return ret;
}
constexpr int max_n=100000;
int a[max_n+1],b[max_n+1];
void test(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	int mex=0,now=k;
	for(int i=1; i<=n; ++i)
		if(a[i]>=mex){
			while(mex<a[i]&&now)
				++mex,--now;
			if(mex==a[i])
				++mex;
			else{
				const int d=i-1;
				n-=d;
				for(int j=1; j<=n; ++j)
					a[j]=a[j+d];
				break;
			}
		}
	if(mex>a[n]){
		puts("0");
		return;
	}
	int m=0,cnt=0;
	for(int i=1,now=0; i<=n; ++i){
		if(a[i]==now)
			++cnt;
		else{
			b[++m]=cnt;
			cnt=1,now=a[i];
		}
	}
	b[++m]=cnt;
	sort(b+1,b+m+1);
	int ans=0;
	for(int i=1; i<=m; ++i)
		if(b[i]<=k){
			k-=b[i];
			b[i]=0;
		}
		else
			++ans;
	printf("%d\n",ans);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}