#include <iostream>
using namespace std;
int a[1000005];
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		long long s=0;
		for(int j=i+2;j<=n;j++)
		{
			s+=a[j-1];
			if(s>a[i]*2) break;
			if(a[i]>a[j]&&(a[i]^a[j])==s) ++ans;
		}
		s=0;
		for(int j=i-2;j>=1;j--)
		{
			s+=a[j+1];
			if(s>a[i]*2) break;
			if(a[i]>a[j]&&(a[i]^a[j])==s) ++ans;
		}
	}
	cout << ans;
	return 0;
}