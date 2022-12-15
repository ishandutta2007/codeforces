#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, i, s, x, f; long double ans;
unordered_map<ll,ll> c;

int main(){
	for(scanf("%lld",&N),i=0;i<N;i++){
		scanf("%lld",&x);
		f = i-c[x-1]-c[x+1]-c[x];
		ans += f*x-s+(x-1)*c[x-1]+(x)*c[x]+(x+1)*c[x+1];
		c[x]++; s += x;
	}
	printf("%.0Lf\n",ans); 
	return 0;
}