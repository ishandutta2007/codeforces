#include<bits/stdc++.h>
using namespace std;

const int N=200005;
int n,a[N];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int mn=1;
	for (int i=2;i<=n;i++)
		if (a[i]<a[mn]) mn=i;
	printf("%d\n",n-1);
	for (int i=1;i<=n;i++)
		if (i!=mn)
			if ((i+mn)%2==0)
				printf("%d %d %d %d\n",mn,i,a[mn],a[mn]);
			else
				printf("%d %d %d %d\n",mn,i,a[mn],a[mn]+1);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}