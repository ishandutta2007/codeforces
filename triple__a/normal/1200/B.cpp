#include<bits/stdc++.h>
using namespace std;
 
const int maxn=1007;
long long a[maxn],n,m,k; 
 
bool solve(){
	for (int i=1;i<n;++i){
		m+=min(a[i]-a[i+1]+k,a[i]);
		if (m<0) return 0;
	}
	return 1;
}
 
int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		scanf("%lld%lld%lld",&n,&m,&k);
		for (int i=1;i<=n;++i){
			scanf("%lld",&a[i]);
		}
		if (solve()){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}