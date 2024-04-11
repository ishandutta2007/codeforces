#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int a,b;
		cin >> a >> b;
		a=abs(a-b);
		int t=0;
		for(int i=0;i<=10000000;i++)
		{
			t+=i;
			if(t>=a&&t!=a+1&&t%2==a%2)
			{
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}