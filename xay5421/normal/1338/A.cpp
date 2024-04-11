#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
const int N=100005;
int T,n;
LL a[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,1,n){
			scanf("%lld",&a[i]);
		}
		LL mx=a[1];
		auto calc=[&](LL x)->int{
			return __lg(x)+1;
		};
		int ans=0;
		rep(i,2,n){
			if(a[i]<mx){
				ans=max(ans,calc(mx-a[i]));
			}else{
				mx=a[i];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}