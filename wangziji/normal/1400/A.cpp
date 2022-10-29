#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		string a;
		cin >> a;
		for(int i=1;i<=n;i++)
			cout << a[n-1];
		puts("");
	}
	return 0;
}