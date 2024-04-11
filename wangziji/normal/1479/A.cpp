#include <iostream>
using namespace std;
int n;
inline int ask(int x)
{
	if(x==0||x==n+1) return 1e9;
	cout << "? " << x << endl;
	int t;
	cin >> t;
	return t;
}
int main(int argc, char** argv) {
	cin >> n;
	int l=1,r=n,ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(ask(mid-1)<ask(mid)) r=mid-1,ans=mid-1;
		else l=mid+1,ans=mid;
	}
	cout << "! " << ans << endl;
	return 0;
}