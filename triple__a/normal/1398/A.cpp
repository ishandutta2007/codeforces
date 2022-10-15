#include<bits/stdc++.h>
using namespace std;

const int maxn=200007;
int t,n;
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=0;i<n;++i) cin>>a[i];
		if (a[0]+a[1]<=a[n-1]) cout<<"1 2 "<<n<<"\n";
		else cout<<"-1\n";
	}
}