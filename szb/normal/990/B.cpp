#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+233;
int n,k,ans;
int a[maxn];
signed main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	ans = n;
	for(int i=n-1;i>=1;i--){
		if(a[i+1]>a[i] && a[i+1] <= a[i] + k){
			ans--;
			while(a[i-1]==a[i]){
				i--;
				ans--;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}