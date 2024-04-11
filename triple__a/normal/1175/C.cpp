#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=200007;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k,a[maxn];
		scanf("%d%d",&n,&k);
		for (int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		int ans=1e9,u=0;
		for (int i=0;i+k<n;++i){
			if (a[i+k]-a[i]<ans){
				u=(a[i+k]+a[i])/2;
				ans=a[i+k]-a[i];
			}
		}
		printf("%d\n",u); 
	}
}