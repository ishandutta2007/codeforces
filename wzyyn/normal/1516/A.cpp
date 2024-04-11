#include<bits/stdc++.h>
using namespace std;

int a[105];
void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (;k;--k){
		int p=n;
		for (int i=1;i<n;i++)
			if (a[i]){
				p=i;
				break;
			}
		if (p!=n)
			a[p]--,a[n]++;
		else break;
	}
	for (int i=1;i<=n;i++)
		printf("%d ",a[i]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}