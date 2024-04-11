#include <iostream>
using namespace std;
int a[1000005];
int main(int argc, char** argv) {
	int now=2;
	while(now<=1000000)
	{
		a[now]=a[now-1]=1;
		now=now*2+(1^now&1);
	}
	int n;
	cin >> n;
	cout << a[n]; 
	return 0;
}