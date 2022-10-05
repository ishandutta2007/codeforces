#include<bits/stdc++.h>
using namespace std;
int a[210000];
int b[210000];
int main(){
	int _;
	cin>>_;
	while(_--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		long long s=0;
		for(int i=1;i<=n;i++)s+=a[i];
		for(int i=1;i<=n;i++)b[i]=a[i]-(n-i);
		sort(b+1,b+n+1);
		long long ans=s;
		for(int i=1;i<=k;i++){
			s-=b[n-i+1];
			s-=i-1;
			ans=min(ans,s);
		}
		cout<<ans<<"\n";
	}
	return 0;
}