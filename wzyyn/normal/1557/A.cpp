#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
void solve(){
	int n;
	long long S=0,mx=-(1<<30),x;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%lld",&x);
		mx=max(mx,x);
		S+=x;
	}
	printf("%.10lf\n",mx+(S-mx)*1.0/(n-1));
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}