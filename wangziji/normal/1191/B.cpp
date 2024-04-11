#include <iostream>
#include <algorithm>
using namespace std;
int a[1000];
int main(int argc, char** argv) {
	for(int i=1;i<=3;i++)
	{
		string b;
		cin >> b;
		a[i]=b[0]+b[1]*10000; 
	}
	sort(a+1,a+4);
	if(a[1]==a[2]&&a[2]==a[3])
	{
		cout << 0;
		return 0;
	}
	if(a[1]==a[2]||a[2]==a[3]||a[3]==a[1])
	{
		cout << 1;
		return 0;
	}
	if(a[1]+1==a[2]&&a[2]+1==a[3])
	{
		cout << 0;
		return 0;
	}
	if(a[1]+1==a[2]||a[1]+2==a[2]||a[2]+1==a[3]||a[1]+1==a[3]||a[1]+2==a[3]||a[2]+2==a[3])
	{
		cout << 1;
		return 0;
	}
	cout << 2;
	return 0;
}