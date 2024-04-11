#include<bits/stdc++.h>
using namespace std;

int n,a[200005];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if (n==2) printf("%d %d\n",a[1],a[2]);
	else{
		int p=2;
		for (int i=2;i<=n;i++)
			if (a[i]-a[i-1]<a[p]-a[p-1])
				p=i;
		for (int i=p;i<=n;i++)
			printf("%d ",a[i]);
		for (int i=1;i<p;i++)
			printf("%d ",a[i]);
		puts("");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}