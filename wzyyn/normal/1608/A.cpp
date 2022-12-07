#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	scanf("%d",&n);
	for (int i=2;i<=n+1;i++)
		printf("%d%c",i,i==(n+1)?'\n':' ');
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}