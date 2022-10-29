#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

int n,a[10010];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>n;
	rep(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<n;i+=2){
		ans += a[i+1]-a[i]; 
	}
	cout<<ans<<endl;
	return 0;
}