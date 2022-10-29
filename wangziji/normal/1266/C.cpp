#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int a,b;
	cin >> a >> b;
	if(a==b&&b==1)
	{
		puts("0");
		return 0;
	}
	if(b==1)
	{
		for(int i=2;i<=a+1;i++)
		{
			cout << i;
			puts("");
		}
		return 0;
	}
		for(int i=1;i<=a;i++)
		{
			for(int j=a+1;j<=b+a;j++)
			{
				cout << i*j << " ";
			}
			puts("");
		}
	return 0;
}