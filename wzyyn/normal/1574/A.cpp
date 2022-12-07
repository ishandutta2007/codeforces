#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		printf("()");
	puts("");
	for (int i=1;i<n;i++){
		for (int j=1;j<n;j++)
			if (i==j)
				printf("(())");
			else printf("()");
		puts(""); 
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}