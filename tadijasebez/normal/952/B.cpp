#include <bits/stdc++.h>
using namespace std;
string ask(int x)
{
	printf("%i\n",x);
	fflush(stdout);
	string s;getline(cin,s);
	return s;
}
int main()
{
	int i;
	for(i=0;i<4;i++)
	{
		string tmp=ask(i);
		if(tmp=="great!" || tmp=="don't think so" || tmp=="not bad" || tmp=="cool" || tmp=="don't touch me")
		{
			printf("normal\n");
			fflush(stdout);
			return 0;
		}
		if(tmp=="no way" || tmp=="are you serious" || tmp=="don't even" || tmp=="go die in a hole" || tmp=="worse" || tmp=="terrible")
		{
			printf("grumpy\n");
			fflush(stdout);
			return 0;
		}
	}
	printf("normal\n");
	fflush(stdout);
	return 0;
}