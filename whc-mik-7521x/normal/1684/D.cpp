#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ans+=a[i];
			a[i]+=i;
		}
		stable_sort(a+1,a+n+1);
		reverse(a+1,a+n+1);
		for(int i=1;i<=k;i++)ans-=a[i];
		for(int i=1;i<=k;i++){
			ans+=n+1-i;
		}
		cout<<ans<<endl;
	}
	return 0;
}