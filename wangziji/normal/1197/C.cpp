#include <iostream>
#include <algorithm>
using namespace std;
int a[300005],b[300005];
int main(int argc, char** argv) {
	int n,k,ans;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	ans=a[n]-a[1];
	for(int i=1;i<n;i++)
		b[i]=a[i+1]-a[i];
	sort(b+1,b+n);
	for(int i=n-1;i>n-k;i--)
		ans-=b[i];
	cout << ans;
	return 0;
}