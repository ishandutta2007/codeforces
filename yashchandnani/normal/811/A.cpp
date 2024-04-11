#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b;
	cin>>a>>b;
	for (int i = 1; ; ++i)
	{
		if (i%2)
		{
			a-=i;
			if (a<0)
			{
				cout<<"Vladik";
				return 0;
			}

		}
		else{
			b-=i;
			if (b<0)
			{
				cout<<"Valera";
				return 0;
			}
		}
	}
	return 0;
}