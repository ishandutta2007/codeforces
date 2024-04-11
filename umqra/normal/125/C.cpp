#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector <int> mas[200];
int main()
{
	int n;
	cin >> n;
	int pl=2;
	for ( int i=3; i<1000000; i+=pl )
	{
		pl++;
		if ( i+pl>n )
			break;
	}
	cout << pl << '\n';
	int last=1;
	for ( int i=0; i<pl; i++ )
	{
		int c=0;
		for ( int s=0; s<i; s++ )
		{
			cout << mas[s].back() << ' ';
			mas[s].pop_back();
			c++;
		}
		for ( int s=0; s<pl-c-1; s++ )
		{
			mas[i].push_back(last);
			cout << last << ' ';
			last++;
		}
		cout << '\n';
	}
	return 0;
}