#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		if(a==c&&a==b+d||a==d&&a==b+c||b==c&&b==a+d||b==d&&b==a+c)
		{
			puts("yEs");
		}else puts("nO");
	}
	return 0;
}