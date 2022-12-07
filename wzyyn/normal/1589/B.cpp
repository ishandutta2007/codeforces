#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d\n",(n*m/3+(n*m%3!=0)));
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}