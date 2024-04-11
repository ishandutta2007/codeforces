#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	int ans=1;
	if (n-1>=m){
		puts("0");
		return 0;
	}
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			(ans*=abs(a[i]-a[j])%m)%=m;
	printf("%d\n",ans);
}