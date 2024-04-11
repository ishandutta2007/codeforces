#include <iostream>
#include <string>
#include <utility>
#include <queue>
#include <map>

typedef std::pair<std::string, std::string> ss;

int main()
{
	int n, a, b, k, f;
	std::cin >> n >> a >> b >> k >> f;
	std::map<ss, int> cost;
	std::string last;
	while(n--)
	{
		std::string s1, s2;
		std::cin >> s1 >> s2;
		if(s1 == last)
			cost[ss(std::min(s1, s2), std::max(s1, s2))] += b;
		else
			cost[ss(std::min(s1, s2), std::max(s1, s2))] += a;
		last = s2;
	}
	std::priority_queue<int> hp;
	for(auto a : cost)
	{
		//std::cout << a.first.first << ", " << a.first.second << " = " << a.second << "\n";
		hp.push(a.second);
	}
	int ans = 0;
	while(!hp.empty() && k && f < hp.top())
		ans += f, hp.pop(), k--;
	while(!hp.empty())
		ans += hp.top(), hp.pop();
	std::cout << ans << '\n';
}