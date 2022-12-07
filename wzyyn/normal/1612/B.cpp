#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	if (a>n/2+1||b<n/2) return puts("-1"),void(0);
	if ((a==n/2+1)^(b==n/2)) return puts("-1"),void(0);
	int p=n;
	printf("%d ",a);
	for (int i=1;i<n/2;i++){
		for (;p==a||p==b;--p);
		printf("%d ",p--);
	}
	printf("%d ",b);
	for (int i=1;i<n/2;i++){
		for (;p==a||p==b;--p);
		printf("%d ",p--);
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}