#include<bits/stdc++.h>
using namespace std;

void solve(){
	int i=1,n;
	scanf("%d",&n);
	if (n&1){
		printf("3 1 2 ");
		i+=3;
	}
	for (;i<=n;i+=2)
		printf("%d %d ",i+1,i);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}