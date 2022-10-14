#include <bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
int main(){
	int tt;
	scanf("%i",&tt);
	while(tt--){
		int n,l,r,k;
		scanf("%i%i%i%i",&n,&l,&r,&k);
		for(int i=0;i<n;i++)scanf("%i",&a[i]);
		sort(a,a+n);
		int ans=0;
		for(int i=0;i<n;i++){
			if(a[i]>=l&&a[i]<=r&&a[i]<=k)ans++,k-=a[i];
		}
		printf("%i\n",ans);
	}
	return 0;
}