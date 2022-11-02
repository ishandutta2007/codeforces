#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;ll a[109];
int main(){
	cin>>n;ll sum=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		sum+=((ll)i-1)*(a[i]-1)+a[i];
	}
	cout<<sum;
	return 0;
}