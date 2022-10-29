#include <iostream>
using namespace std;
int z,e,r,o,n;
int main(int argc, char** argv) {
	int m;
	cin >> m;
	for(int i=1;i<=m;i++)
	{
		char t;
		cin >> t;
		if(t=='z') ++z;
		if(t=='e') ++e;
		if(t=='r') ++r;
		if(t=='o') ++o;
		if(t=='n') ++n;
	}
	while(n&&o&&e)
	{
		--n;
		--o;
		--e;
		cout << 1 << ' ';
	}
	while(z&&e&&r&&o)
	{
		--z,--e,--r,--o;
		cout << 0 << ' ';
	}
	return 0;
}