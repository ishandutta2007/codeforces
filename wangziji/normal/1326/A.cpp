#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		if(n==1)
		{
			puts("-1");
			continue;
		}
		cout << 2;
		for(int i=1;i<n;i++) cout << 3;
		puts("");
	}
	return 0;
}