#include <iostream>
using namespace std;
int a[1000005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int flag=1;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=2;i<=n;i++)
			if(a[i]!=a[i-1]) flag=0;
		if(flag) cout << n;
		else cout << 1;
		puts("");
	}
	return 0;
}