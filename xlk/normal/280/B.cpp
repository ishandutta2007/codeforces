#include <bits/stdc++.h>
using namespace std;
int n, x, z;
stack<int> s;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		while (s.size())
		{
			z = max(z, x ^ s.top());
			if (s.top() < x)
			{
				s.pop();
			}
			else
			{
				break;
			}
		}
		s.push(x);
	}
	cout << z << endl;
	return 0;
}