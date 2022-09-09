#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
int a[N],b[N];
int main(){
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]);
	for(int i=1;i<=n;i++)scanf("%i",&b[i]),a[i]-=b[i];
	sort(a+1,a+1+n);
	ll ans=0;
	for(int i=1,j=n+1;i<=n;i++){
		while(j>1 && a[i]+a[j-1]>0)j--;
		ans+=n-j+1-(j<=i);
	}
	printf("%lld\n",ans/2);
	return 0;
}