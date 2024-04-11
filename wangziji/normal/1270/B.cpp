#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int flag=0,lst;
		cin >> lst;
		for(int i=2;i<=n;i++)
		{
			int t;
			cin >> t;
			if(abs(t-lst)>=2&&!flag)
			{
				flag=1;
				cout << "YES\n" << i-1 << " " << i << "\n";
			}
			lst=t;
		}
		if(!flag) puts("no");
	}
	return 0;
}