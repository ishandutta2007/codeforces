#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d\n",2-(n==1)-(m==1));
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}