#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		long long n;
		scanf("%lld",&n);
		if(n%2050==0){
			long long mul=2050;
			for(int i=1;i<=15;i++)
				mul*=10;
			long long ans=0;
			for(int i=15;i>=0;i--){
				ans+=n/mul,n%=mul;
				mul/=10;
			}
			printf("%lld\n",ans);
		}
		else puts("-1");
	}
	return 0;
}