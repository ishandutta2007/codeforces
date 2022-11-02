#include<bits/stdc++.h>

using namespace std;

int a[100010];

int main(){
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	long long tmp = 0;
	for(int i = 1; i < n; i++)
		tmp += a[i];
	printf("%lld\n", max(0LL, a[n] + 1 - tmp));
	return 0;
}