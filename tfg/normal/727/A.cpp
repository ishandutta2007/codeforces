#include <iostream>
#include <stack>

typedef long long int ll;

std::stack<ll> s;

ll a, b;

bool bt(ll x)
{
	if(x>b)
		return false;
	s.push(x);
	if(b==x)
		return true;
	bool ans=bt(2*x);
	if(ans)
		return true;
	ans=bt(10*x+1);
	if(ans)
		return true;
	s.pop();
	return false;
}

int main()
{
	
	std::cin >> a >> b;
	bool ans=bt(a);
	if(ans)
	{
		std::stack<ll> s2;
		while(!s.empty())
		{
			s2.push(s.top());
			s.pop();
		}
		std::cout << "YES\n" << s2.size() << '\n' << s2.top();
		s2.pop();
		while(!s2.empty())
		{
			std::cout << ' ' << s2.top();
			s2.pop();
		}
		std::cout << '\n';
	}
	else
		std::cout << "NO\n";
}