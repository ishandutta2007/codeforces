#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		long long x;
		cin >> x;
		if(x<14) x=0;
		x%=14;
		if(x==0||x>=7)
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}