#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

string str = "1";
char buf[100005];
int zeros;

int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", buf);
		if (buf[0] == '0')
		{
			printf("0");
			return 0;
		}

		int ones = 0;
		for (int i = 0; buf[i]; i++)
		{
			if (buf[i] == '1') ones++;
			else if (buf[i] != '0') ones += 2;
		}

		if (ones > 1) str = buf;
		else zeros += strlen(buf) - 1;
	}

	printf("%s", str.c_str());
	while (zeros--) printf("0");
}