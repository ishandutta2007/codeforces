#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,a=0,b=0;
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			int t;
			cin >> t;
			if(t>a) b=a,a=t;
			else if(t>b) b=t;
		}
		if(b>=2) cout << min(n-2,b-1) << "\n";
		else puts("0");
	}
	return 0;
}