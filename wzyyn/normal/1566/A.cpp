#include<bits/stdc++.h>

using namespace std;


void solve(){
	int n,s;
	scanf("%d%d",&n,&s);
	int m=(n-(n+1)/2+1);
	printf("%d\n",s/m);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}