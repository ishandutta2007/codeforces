#include <iostream>
using namespace std;
inline int f(int x)
{
	int rtn=0;
	for(int i=1;i<=10;i++) rtn+=x%10,x/=10;
	return rtn;
}
int main(int argc, char** argv) {
	int x;
	cin >> x;
	cout << f(f(f(x)));
	return 0;
}