#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005;
int a[N],b[N],n;
signed main(){
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)scanf("%lld",&b[i]);
	int Max=0;
	for (int i=1;i<=n;i++){
		a[i]=Max+b[i];
		Max=max(Max,a[i]);
	}
	for (int i=1;i<=n;i++)printf("%lld ",a[i]);
}