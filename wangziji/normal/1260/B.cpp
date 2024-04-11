#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int a,b;
		cin >> a >> b;
		if((a+b)%3==0&&a<=b*2&&b<=a*2)
		{
			puts("YES");
		}
		else puts("NO");
	}
	return 0;
}