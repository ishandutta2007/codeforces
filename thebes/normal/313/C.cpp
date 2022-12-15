#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MN = 2000006;
ll p[MN], N, n, ans, i, a[MN];

int main(){
	for(scanf("%lld",&N),i=1;i<=N;i++)
		scanf("%lld",&a[i]);
	sort(a+1, a+N+1);
	for(i=1;i<=N;i++)
		p[i] = p[i-1]+a[N-i+1];
	for(n=sqrt(N),i=60;i>=0;i--){
		if((1LL<<i)&n){n=i; break;}
	}
	for(i=n;i>=0;i--)
		ans += p[(1LL<<(2*i))];
	printf("%lld\n",ans);
	return 0;
}