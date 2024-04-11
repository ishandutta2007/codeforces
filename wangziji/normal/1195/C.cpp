#include <iostream>
#define int long long
using namespace std;
int a[100005],b[100005];
signed main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) cin >> b[i];
	int x=0,y=0;
	for(int i=1;i<=n;i++)
	{
		int tx=max(x,y+a[i]),ty=max(y,x+b[i]);
		x=tx,y=ty;
	}
	cout << max(x,y);
	return 0;
}