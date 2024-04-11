#include <bits/stdc++.h>
using namespace std;
int n;
pair<int,int> a[1005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i].first,a[i].second=i;
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i].first*(i-1)+1;
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)	cout<<a[i].second<<" ";
	return 0;
}