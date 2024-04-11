#include <iostream>

using namespace std;

int main()
{
	char c;
	int w=7;
	while(w--)c=getchar();
	int d=c-'0';
	cout<<(d&1);
    return 0;
}