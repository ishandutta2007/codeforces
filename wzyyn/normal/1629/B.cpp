#include<bits/stdc++.h>

using namespace std;

void solve(){
	int l,r,k;
	scanf("%d%d%d",&l,&r,&k);
	int s2=r/2-(l-1)/2;
	if (l==r&&l!=1) puts("YES");
	else if (!s2||k+s2<r-l+1) puts("NO");
	else puts("YES");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}