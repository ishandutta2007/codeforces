#include<bits/stdc++.h>

using namespace std;

void solve(){
	long long a,b,c,d;
	int k,v1,v2;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	scanf("%d%d%d",&k,&v1,&v2);
	for (int i=0;i<=k;i++){
		long long na=a+1ll*i*v2;
		long long nb=b+1ll*(k-i)*v1;
		long long ta=(c+nb-1)/nb;
		long long tb=(na+d-1)/d;
		if (ta<=tb) return puts("YES"),void(0);
	}
	puts("NO");
	
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}