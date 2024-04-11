// author: xay5421
// created: Fri Jun  4 23:41:16 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=2005;
int T,n,a[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,1,n)scanf("%d",&a[i]);
		sort(a+1,a+1+n,[&](int k1,int k2){return (k1&1)<(k2&1);});
		int ans=0;
		rep(i,1,n)rep(j,i+1,n){
			if(__gcd(a[i],2*a[j])>1){
				++ans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}