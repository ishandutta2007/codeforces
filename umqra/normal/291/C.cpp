#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;

typedef long long ll;
const int N = (int)2e5;

struct IP
{
	int a[4];
	void scan()
	{                  
		scanf("%d.%d.%d.%d", &a[0], &a[1], &a[2], &a[3]);
	}
	int getINT ()
	{
		return (a[0] << 24) | (a[1] << 16) | (a[2] << 8) | a[3];
	}
} list[N];
int listINT[N];

int mask;

bool cmp(const int &a, const int &b)
{
	return (a & mask) < (b & mask);
}

int check(int n, int m)
{
	mask = -1;
	mask <<= (32 - m);                                    
	sort(listINT, listINT + n, cmp);

	int cnt = 1;

	for (int i = 1; i < n; i++)
	{        
		if ((listINT[i] & mask) != (listINT[i - 1] & mask))
			cnt++;
	}              
	return cnt;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		list[i].scan();
		listINT[i] = list[i].getINT();                
	}
	int l = 0, r = 32;
	while (r - l > 1)
	{
		int m = (l + r) / 2;
		int locVal = check(n, m);            
		if (locVal >= k)
			r = m;
		else
			l = m;
	}

	if (r == 32 || check(n, r) != k)
		puts("-1");
	else	
	{
		int ans = 0;       
		for (int i = 0; i < r; i++)
			ans |= (1 << (32 - i - 1));      

		for (int i = 3; i >= 0; i--)
		{
			printf("%d", (ans >> (8 * i) & 255));
			if (i != 0)
				putchar('.');
		}
	}

	return 0;
}