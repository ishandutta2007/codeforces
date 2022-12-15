#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> d; ll n, k, i;

int main(){
	scanf("%lld%lld",&n,&k);
	i = sqrt(n+0.0);
	for(;i>=1;i--){
		if(n%i==0){
			if(n/i==i) d.push_back(i);
			else d.push_back(n/i),d.insert(d.begin(),i);
		}
	}
	if(k>d.size()) printf("-1\n");
	else printf("%lld\n",d[k-1]);
	getchar(); getchar();
}