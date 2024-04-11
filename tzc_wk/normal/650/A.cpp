#include <bits/stdc++.h>
using namespace std;
#define int long long
map<int,int> x,y,e;
int n,ans,m=INT_MAX;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int a,b;
		cin>>a>>b;
		ans+=x[a]+y[b]-e[a*m+b];
		x[a]++;y[b]++;e[a*m+b]++;
	}
	cout<<ans<<endl;
	return 0;
}