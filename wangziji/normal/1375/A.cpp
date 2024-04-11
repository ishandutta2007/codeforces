#include <iostream>
using namespace std;
int a[500005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=n;i++)
		{
			if(i&1) if(a[i]<0) a[i]=-a[i];
			if(i%2==0) if(a[i]>0) a[i]=-a[i];
			cout << a[i] << " ";
		}
		puts("");
	}
	return 0;
}