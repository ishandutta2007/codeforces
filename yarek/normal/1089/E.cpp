#include <bits/stdc++.h>
using namespace std;

void write(int r, int c)
{
	printf("%c%d ", 'a' + r - 1, c);
}

int main()
{
	int n;
	scanf("%d", &n);
	int n0 = n;
	set<int> s0 = { 1, 2, 3, 4, 5, 6, 7, 8 };
	auto s1 = s0;
	s1.erase(1);
	write(1, 1);
	int i = 1;
	while(true)
	{
		if(n == 1)
		{
			write(8, 8);
			puts("");
			return 0;
		}
		else if(n == 2 && i != 8)
			write(i, 8);
		else if(s1.size() == 1)
		{
			int k = *s1.begin();
			write(i, k);
			i++;
			write(i, k);
			s1 = s0;
			s1.erase(k);
			n--;
		}
		else if(i == 8 || ((int)s1.size() >= n - 2 && n0 <= 56))
		{
			auto it = s1.begin();
			write(i, *it);
			s1.erase(it);
		}
		else
		{
			auto it = prev(s1.end());
			write(i, *it);
			s1.erase(it);
		}
		n--;
	}
}