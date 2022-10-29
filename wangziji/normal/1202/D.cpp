#include <iostream>
#define int long long
using namespace std;
int a[100005];
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int cnt=0;
		for(int i=1;i<=10000000;i++)
		{
			a[i]=i*(i-1)/2;
			if(a[i]>n) break;
			cnt=i;
		}
		for(int i=cnt;i>=1;i--)
		{
			while(a[i]<=n&&a[i]!=0)
			{
				cout << 1;
				n-=a[i];
			}
			cout << 3;
		}
		cout << 7 << endl;
	}
	return 0;
}