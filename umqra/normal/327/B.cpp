#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = (int)1e7;  
bool used[N];

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
            
	int ind = 0;
	int n;
	cin >> n;
	for (int i = 2;;i++)
	{
		if (!used[i])
		{
			printf("%d ", i);
			ind++;
			if (ind == n)
				break;
			for (int s = i; s < N; s += i)
				used[s] = 1;
		}
	}

	return 0;
}