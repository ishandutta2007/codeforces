#include <iostream>
#include <string>
#include <set>

int gcd(int a, int b)
{
	if(!b)
		return a;
	else
		return gcd(b, a % b);
}

const int ms = 2010000;

bool np[ms];
int pi[ms];
int pa[ms];

int base[9];

std::set<int> pal;

void generate(int num, int l, int r)
{
	if(r < l)
	{
		//std::cout << "got " << num << '\n';
		pal.insert(num);
		return;
	}
	for(int i = 0; i < 10; i++)
	{
		if(num == 0 && i == 0)
			continue;
		int nxt = num + base[l] * i;
		if(l != r)
			nxt += base[r] * i;
		generate(nxt, l + 1, r - 1);
	}
}

int main()
{
	base[0] = 1;
	for(int i = 1; i < 9; i++)
		base[i] = base[i - 1] * 10;
	for(int i = 0; i < 9; i++)
		generate(0, 0, i);
	np[1] = true;
	for(int i = 2; i < ms; i++)
	{
		if(np[i])
			continue;
		for(int j = i + i; j < ms; j += i)
			np[j] = true;
	}
	for(int i = 1; i < ms; i++)
	{
		pi[i] = pi[i - 1];
		pa[i] = pa[i - 1];
		if(!np[i])
			pi[i]++;
		if(pal.count(i))
			pa[i]++;
	}
	int p, q;
	std::cin >> p >> q;
	int g = gcd(p, q);
	p /= g;
	q /= g;
	int ans = 1;
	for(int i = 2; i < ms; i++)
	{
		if((long long)pi[i] * q <= (long long)pa[i] * p)
			ans = i;
	}
	std::cout << ans << '\n';
}