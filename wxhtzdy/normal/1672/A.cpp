#include <bits/stdc++.h>
using namespace std;

int n,a[55];
void Solve(){
	scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]);
	int s=0;
	for(int i=1;i<=n;i++)s+=(a[i]-1);
	puts(s%2==1?"errorgorn":"maomao90");
}

int main(){
	int t;scanf("%i",&t);
	while(t--)Solve();
	return 0;
}