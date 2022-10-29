#include <iostream>
#include <cstring>
using namespace std;
int a[100005],b[100005];
int main(int argc, char** argv) {
	int n,k,p;
	cin >> n >> k;
	cout << "? " << 1 << endl;
	cin >> k;
	int l=1,r=1,now=2;
	for(int i=1;i<=480;i++)
	{
		if(now>n) now-=n;
		cout << "? " << now << endl;
		int t;
		cin >> t;
		if(t>k) break;
		l=r+1,r=l+i-1;
		now=r+1;
		if(r>n) r-=n;
		
	}
	for(int i=l;;i++)
	{
		if(i>n) i-=n;
		cout << "? " << i << endl;
		int t;
		cin >> t;
		if(t==k)
		{
			cout << "! " << i << endl;
			return 0;
		}
	}
	return 0;
}