#include <iostream>
#define int long long 
using namespace std;
signed main(int argc, char** argv) {
	int n,cnt=1;
	cin >> n;
	--n;
	int t=9;
	while(n)
	{
		if(n<t*cnt)
			break;
		n-=t*cnt;
		t*=10;
		++cnt;
	}
	int x=cnt-n%cnt-1,ans=t/9+n/cnt;
	for(int i=1;i<=x;i++) ans/=10;
	cout << ans%10;
	return 0;
}