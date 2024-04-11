#include<bits/stdc++.h>

using namespace std;
int n,a[35];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

void solve(){
	scanf("%d",&n);
	for (int i=0;i<=29;i++) a[i]=0;
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		for (int j=0;j<=29;j++)
			if (x&(1<<j))
				++a[j];
	}
	int re=0;
	for  (int i=0;i<=29;i++)
		re=gcd(re,a[i]);
	for (int i=1;i<=n;i++)
		if (re%i==0)
			printf("%d ",i);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}