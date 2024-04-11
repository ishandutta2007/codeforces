#include <iostream>
using namespace std;
int a[200005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		long long ans=0;
		for(int i=1;i<=n;i++)
			cin>> a[i];
		int lst=a[1];
		for(int i=2;i<=n;i++)
			if(a[i]-a[i-1]<0) ans-=a[i]-a[i-1];
		cout << ans << "\n";
	}
	return 0;
}