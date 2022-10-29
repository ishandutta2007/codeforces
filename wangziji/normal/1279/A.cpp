#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int a,b,c;
		cin >> a >> b >> c;
		if(a>b+c+1||b>a+c+1||c>a+b+1)
			puts("No");
		else
			puts("Yes");
	}
	return 0;
}