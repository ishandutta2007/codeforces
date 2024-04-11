#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		if((a%2==1)+(b%2==1)+(c%2==1)+(d%2==1)==2)
		{
			puts("No");
			continue;
		}
		if((a%2==1)+(b%2==1)+(c%2==1)+(d%2==1)>=3&&a>=1&&b>=1&&c>=1||(a%2==1)+(b%2==1)+(c%2==1)+(d%2==1)<=1)
			puts("Yes");
		else puts("No");
	}
	return 0;
}