#include <iostream>
#define int long long
using namespace std;
signed main(int argc, char** argv) {
	int n,ans,t,cnt=0,x=0;
	cin >> n;
	if(n==1)
	{
		cout << 1;
		return 0;
	}
	t=ans=n;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
			ans/=i,++cnt,x=i;
		while(n%i==0) n/=i;
	}
	if(n-1) ++cnt,x=n;
	if(cnt>=2) cout << 1;
	if(cnt==1) cout << x;
	return 0;
}