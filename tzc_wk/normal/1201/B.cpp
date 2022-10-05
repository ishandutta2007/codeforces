#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100005],sum,sum0,zero=0;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++)	sum+=a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++)	sum0+=a[i];
	if(sum0<a[n])	puts("NO");
	else if(sum%2==0)	puts("YES");
	else			puts("NO");
	return 0;
}