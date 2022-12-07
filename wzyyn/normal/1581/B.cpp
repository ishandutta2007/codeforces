#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	if (m>1ll*n*(n-1)/2||m<n-1) puts("NO");
	else if (k<=1) puts("NO");
	else if (k==2) puts(n==1?"YES":"NO");
	else if (k==3) puts(m==1ll*n*(n-1)/2?"YES":"NO");
	else puts("YES");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve(); 
}