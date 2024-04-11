#include<bits/stdc++.h>
using namespace std;


void solve(){
	int n,x,f=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		int y=ceil(sqrt(x-0.1));
		if (y*y!=x) f=1;
	}
	puts(f?"YES":"NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}