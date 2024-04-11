#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k, cnt, i, f[20]={1,1}, j;
vector<ll> vec, rem; set<ll> luck;
void gen(ll n,ll tot){
	if(n==-1) vec.push_back(tot),luck.insert(tot);
	else{
		gen(n-1,tot*10+4LL);
		gen(n-1,tot*10+7LL);
	}
}

int main(){
	scanf("%lld%lld",&n,&k);
	for(i=2;i<=15;i++) f[i]=f[i-1]*i;
	for(i=0;i<=10;i++) gen(i,0);
	for(auto v : vec){
		if(v<n-15) cnt++;
	}
	ll tot = 1;
	for(i=max(1LL,n-15);i<=n;i++)
		rem.push_back(i);
	for(i=max(1LL,n-15);i<=n;i++){
		for(j=0;j<20;j++){
			if(tot+j*f[n-i]>k){
				tot+=(--j)*f[n-i];
				break;
			}
		}
		if(j>=rem.size()){
			printf("-1\n");
			return 0;
		}
		if(luck.find(i)!=luck.end()&&luck.find(rem[j])!=luck.end()) cnt++;
		rem.erase(rem.begin()+j);
	}
	printf("%lld\n",cnt);
	return 0;
}