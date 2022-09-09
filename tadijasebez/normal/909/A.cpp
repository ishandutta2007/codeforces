#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<char> sol;
int main()
{
	string a,b;
	cin >> a >> b;
	int i=1,j=0;
	sol.push_back(a[0]);
	for(i=1;i<a.size();i++)
	{
		if(b[0]<=a[i]) break;
		sol.push_back(a[i]);
	}
	sol.push_back(b[0]);
	for(i=0;i<sol.size();i++) printf("%c",sol[i]);
	return 0;
}