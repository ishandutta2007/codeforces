#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;;
	while(T--)
	{
		int n,s;
		cin >> n >> s;
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			int t;
			cin >> t;
			sum+=t;
		}
		cout << min(sum,s) << "\n";
	}
	return 0;
}