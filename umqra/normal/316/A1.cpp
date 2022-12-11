#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int BASE = 10000;

struct BigInt
{
	vector <int> a;
	BigInt () {}
	BigInt (int x)
	{
		while (x)
		{
			a.push_back(x % BASE);
			x /= BASE;
		}
	}
	void operator *= (int k)
	{
		int z = 0;
		for (int i = 0; i < (int)a.size() || z; i++)
		{
			if (i == (int)a.size())
				a.push_back(0);
			a[i] = a[i] * k + z;
			z = a[i] / BASE;	
			a[i] %= BASE;
		}
	}
	void print()
	{
		printf("%d", a[(int)a.size() - 1]);
		for (int i = (int)a.size() - 2; i >= 0; i--)
			printf("%04d", a[i]);
	}
};

bool used[10000];

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	string str;
	cin >> str;

               
    BigInt ans = BigInt(1);
    int cntUsed = 0;                
    for (int i = 0; i < (int)str.length(); i++)
    {

		int t = 0;
		if (i == 0)
			t = 1;

    	if (str[i] == '?')
    		ans *= (10 - t);
    	else if (str[i] >= 'A' && str[i] <= 'J')
    	{
    		if (!used[str[i]])
    		{                   
    			ans *= (10 - cntUsed - t);
    			cntUsed++;
    			used[str[i]] = 1;
    		}
    	}
    }

    ans.print();

	return 0;
}