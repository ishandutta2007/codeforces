#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 1e5+9;
int T,n;
ll a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		ll sum=a[1];
		for(int i=1;i<=n;i++) sum&=a[i];
		printf("%lld\n",sum);
	}
	return 0;
}