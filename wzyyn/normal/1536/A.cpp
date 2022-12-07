#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,x,f=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		f|=(x<0); 
	}
	if (f) puts("NO");
	else{
		puts("YES");
		puts("101");
		for (int i=0;i<=100;i++)
			printf("%d ",i);
		puts("");
	} 
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}