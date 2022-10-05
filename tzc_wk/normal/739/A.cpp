#include <bits/stdc++.h>
using namespace std;
int n,m,ans=INT_MAX;
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int l,r;cin>>l>>r;
		ans=min(ans,r-l+1);
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)	cout<<i%ans<<" ";
}