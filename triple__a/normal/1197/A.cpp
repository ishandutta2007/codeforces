#include<bits/stdc++.h>
using namespace std;

const int maxn=1000007;

int s[maxn],a[maxn];

void solve(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	printf("%d\n",min(n-2,a[n-1]-1));
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}