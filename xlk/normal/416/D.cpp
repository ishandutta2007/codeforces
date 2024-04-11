#include <bits/stdc++.h>
using namespace std;
int n, flag;
long long z, x, f, p, v, k;
// f  
// p -1
// v -1
// k 
// flag
// 0 
// 1 -1
// 21-1
// 32-1
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (flag == 0)
		{
			if (x == -1)
			{
				z++;
				flag = 1;
				f = i;
			}
			else
			{
				z++;
				flag = 2;
				f = i;
				p = i;
				v = x;
			}
		}
		else if (flag == 1)
		{
			if (x == -1)
			{
				
			}
			else
			{
				flag = 2;
				p = i;
				v = x;
			}
		}
		else if (flag == 2)
		{
			if (x == -1)
			{
				
			}
			else
			{
				if ((x - v) % (i - p) == 0 && v - (x - v) / (i - p) * (p - f) > 0)
				{
					flag = 3;
					k = (x - v) / (i - p);
				}
				else
				{
					z++;
					flag = 2;
					f = i;
					p = i;
					v = x;
				}
			}
		}
		else if (flag == 3)
		{
			if (x == -1)
			{
				if (v + (i - p) * k > 0)
				{
					
				}
				else
				{
					z++;
					flag = 1;
					f = i;
				}
			}
			else
			{
				if (v + (i - p) * k == x)
				{
					
				}
				else
				{
					z++;
					flag = 2;
					f = i;
					p = i;
					v = x;
				}
			}
		}
	}
	cout << z << endl;
	return 0;
}