#include<bits/stdc++.h>
using namespace std;
int n,a[55];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	bool flag=0;
	for (int i=1;i<=n;i++)
		if (a[i]!=i) flag=1;
	if (!flag){
		puts("0");
		return;
	}
	if (a[1]==1||a[n]==n){
		puts("1");
		return;
	}
	if (a[1]==n&&a[n]==1){
		puts("3");
		return;
	}
	puts("2");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}