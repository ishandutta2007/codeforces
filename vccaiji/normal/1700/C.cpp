#include<bits/stdc++.h>
using namespace std;
int a[1100000],b[1100000];
char s[1100000];
int main(){
	int _;
	cin>>_;
	while(_--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		long long o=a[n];
		long long ans=0;
		for(int i=1;i<n;i++){
			if(a[i]>=a[i+1])ans+=a[i]-a[i+1];
			else ans+=a[i+1]-a[i],o-=a[i+1]-a[i];
		}
		printf("%lld\n",ans+abs(o));
	}
	return 0;
}