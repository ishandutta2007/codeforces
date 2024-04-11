#include <iostream>
#include <cstdio>
#include <map>
#define maxn 100005
using namespace std;
map<int, int> p;
int t;
long long x;
char s[2];
int main()
{
	map<int, int>::iterator it;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%s%lld", s, &x);
		if(s[0] == '+')
		{
			int Hash = 0; 
			for (int i = 0; i <= 18; i++)
			{
				if((x % 10ll) & 1ll) Hash += (1 << i);
				x /= 10;
			}
			it = p.find(Hash);
			if(it == p.end()) p.insert(make_pair(Hash, 1));
			else it->second++;
		}
		if(s[0] == '-')
		{
			int Hash = 0; 
			for (int i = 0; i <= 18; i++)
			{
				if((x % 10ll) & 1ll) Hash += (1 << i);
				x /= 10;
			}
			it = p.find(Hash);
			it->second--;
		}
		if(s[0] == '?')
		{
			int Hash = 0; 
			for (int i = 0; i <= 18; i++)
			{
				if((x % 10ll) & 1ll) Hash += (1 << i);
				x /= 10;
			}
			it = p.find(Hash);
			if(it == p.end()) printf("0\n");
			else printf("%d\n", it->second);
		}
	}
	return 0;
}