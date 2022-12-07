#include<bits/stdc++.h>
using namespace std;
int n,S,a[105];
void solve(){
	scanf("%d%d",&n,&S);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		if (!(S-=a[i]))
			if (i==n){
				puts("NO");
				return;
			}
			else swap(a[i],a[i+1]);
	puts("YES");
	for (int i=1;i<=n;i++)
		printf("%d ",a[i]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}