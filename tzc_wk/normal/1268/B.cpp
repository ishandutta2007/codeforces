#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[300005],black,white;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i%2==1)	black+=a[i]/2,white+=a[i]-a[i]/2;
		else		black+=a[i]-a[i]/2,white+=a[i]/2;
	}
	cout<<min(black,white);
    return 0;
}