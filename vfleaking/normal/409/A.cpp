#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	static char sA[30];
	static char sB[30];

	cin >> sA >> sB;
	int n = strlen(sA);

	int res = 0;
	for (int i = 0; i < n; i += 2)
	{
		if (sA[i] == '(')
		{
			if (sB[i] == '(')
				;
			else if (sB[i] == '[')
				res--;
			else if (sB[i] == '8')
				res++;
		}
		else if (sA[i] == '[')
		{
			if (sB[i] == '(')
				res++;
			else if (sB[i] == '[')
				;
			else if (sB[i] == '8')
				res--;
		}
		else if (sA[i] == '8')
		{
			if (sB[i] == '(')
				res--;
			else if (sB[i] == '[')
				res++;
			else if (sB[i] == '8')
				;
		}
	}

	if (res > 0)
		puts("TEAM 1 WINS");
	else if (res < 0)
		puts("TEAM 2 WINS");
	else
		puts("TIE");

	return 0;
}