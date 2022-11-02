#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int T,n,a[N];
signed main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		for (int i=1;i<=n;i+=2)a[i]=abs(a[i]);
		for (int i=2;i<=n;i+=2)a[i]=-abs(a[i]);
		for (int i=1;i<=n;i++)printf("%d ",a[i]);
		puts("");
	}
}