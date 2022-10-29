#include <iostream>
using namespace std;
inline int gcd(int x,int y)
{
	if(x>y)
		swap(x,y);
	while(x)
	{
		y%=x;
		swap(x,y);
	}
	return y;
}
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int a,b;
		cin >> a >> b;
		if(gcd(a,b)!=1)
			puts("Infinite");
		else
			puts("Finite");
	}
	return 0;
}