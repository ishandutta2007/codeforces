#include<bits/stdc++.h>
using namespace std;
int a[210000];
long long b[2100000];
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		b[1]=a[1];
		for(int i=2;i<=n;i++) b[i]=b[i-1]+a[i];
		if((long long)(n-1)*a[n]+b[n-1]<0) {
			printf("INF\n");
			continue;
		}
		if((long long)(n-2)*a[1]+b[n]>0){
			printf("INF\n");
			continue;
		}
		long long maxx=-4000000000000000000ll;
		for(int i=1;i<n;i++) maxx=max(maxx,a[n]*b[i]+a[1]*(b[n]-b[i])-(long long)a[1]*a[n]-a[i]*((long long)i*a[n]+b[i]+(long long)(n-i-1)*a[1]+b[n-1]-b[i]));
		maxx=max(maxx,0-(long long)(n-1)*a[n]*a[n]);
		cout<<maxx<<endl;
	}
	return 0;
}