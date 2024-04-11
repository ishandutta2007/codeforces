#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

set<long long> wtf;
long long n, i, arr[200005], j, ans;
vector<long long> lol;

int main(){
	for(scanf("%lld",&n),i=1;i<=n;i++){
		scanf("%lld",&arr[i]);
		wtf.insert(arr[i]);
	}
	for(i=1;i<=n;i++){
		for(j=0;j<40;j++){
			if(wtf.count(1LL*arr[i]+(1LL<<j))&&wtf.count(1LL*arr[i]+(1LL<<(j+1)))){
				if(3>ans){
					ans = 3; lol.clear();
					lol.push_back(arr[i]);
					lol.push_back(arr[i]+(1LL<<j));
					lol.push_back(arr[i]+(1LL<<(j+1)));
				}
			}
			if(wtf.count(1LL*arr[i]+(1LL<<j))){
				if(2>ans){
					ans = 2; lol.clear();
					lol.push_back(arr[i]);
					lol.push_back(arr[i]+(1LL<<j));
				}
			}
		}
	}
	printf("%lld\n",max(1LL,ans));
	if(!ans) printf("%lld\n",arr[1]);
	else{
		for(auto elem : lol)
			printf("%lld ",elem);
	}
	return 0;
}