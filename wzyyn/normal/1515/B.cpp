#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	scanf("%d",&n);
	int v1=(floor)(sqrt(n/4)+1e-8);
	int v2=(floor)(sqrt(n/2)+1e-8);
	if (4ll*v1*v1==n||2ll*v2*v2==n)
		puts("YES");
	else puts("NO"); 
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}