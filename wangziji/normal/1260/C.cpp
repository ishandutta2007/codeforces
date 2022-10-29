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
		int a,b,c;
		cin >> a >> b >> c;
		if(a<b) swap(a,b);
		if((a-1-gcd(a,b))/b+1>=c) puts("REBEL");
		else puts("OBEY");
	}
	return 0;
}