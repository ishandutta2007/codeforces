#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

int n;
string s;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> s >> n;
	if ((s == "front") ^ (n == 1))
		printf("R\n");
	else
		printf("L\n");

	return 0;
}