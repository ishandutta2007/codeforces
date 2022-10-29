#include <iostream>
using namespace std;
int a[1000];
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin >> x;
		a[x]=1;
	}
	int ans=0;
	for(int i=1;i<=100;i++)
	{
		if(a[i])
		{
			++ans;
			for(int j=i;j<=100;j+=i)
				a[j]=0;
		}
	}
	cout << ans;
	return 0;
}