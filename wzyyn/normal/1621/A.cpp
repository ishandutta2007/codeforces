#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	if (k*2-1>n) puts("-1");
	else{
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++)
				if (i==j&&i%2==1&&i<=2*k-1)
					putchar('R');
				else
					putchar('.');
			puts("");
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}