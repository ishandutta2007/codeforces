#include <iostream>
using namespace std;
int a[100005],b[100005];
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]&1)
		{
			++cnt;
			b[i]=a[i]/2;
			while(b[i]*2>a[i])
				--b[i];
			b[i]+=cnt&1;
		}
		else
			b[i]=a[i]/2;
	}
	for(int i=1;i<=n;i++)
		cout << b[i] << endl;
	return 0;
}