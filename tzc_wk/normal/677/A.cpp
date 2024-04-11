#include <bits/stdc++.h>
using namespace std;
int n,h,a[1005],ans;
int main(){
	cin>>n>>h;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]>h)	ans+=2;
		else		ans++;
	}
	cout<<ans<<endl;
}