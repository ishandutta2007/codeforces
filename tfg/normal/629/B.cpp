#include <string>
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>

typedef std::pair<int, int> ii;

std::vector<ii> a,b;

int main()
{
	int n;
	std::cin >> n;
	for(int i=0;i<n;i++)
	{
		std::string str;
		ii temp;
		std::cin >> str >> temp.first >> temp.second;
		if(str[0]=='M')
			a.push_back(temp);
		else
			b.push_back(temp);
	}
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());
	int ans=0;
	int cur=0;
	int ca, cb;
	ca=cb=0;
	int la,lb;
	la=lb=0;
	std::priority_queue<int> ha,hb;
	while(ca!=a.size() || cb!=b.size())
	{
		//std::cout << "on " << cur << ", ans is " << ans << ", a is " << ca-la << ", b is " << cb-lb << '\n';
		if(ca==a.size())
		{
			cur=b[cb].first;
			hb.push(-b[cb++].second);
		}
		else if(cb==b.size())
		{
			cur=a[ca].first;
			ha.push(-a[ca++].second);
		}
		else
		{
			if(b[cb]<=a[ca])
			{
				if(a[ca]==b[cb])
					ha.push(-a[ca++].second);
				cur=b[cb].first;
				hb.push(-b[cb++].second);
			}
			else
			{
				cur=a[ca].first;
				ha.push(-a[ca++].second);
			}
		}
		while(!ha.empty() && -ha.top()<cur)
		{
			la++;
			ha.pop();
		}
		while(!hb.empty() && -hb.top()<cur)
		{
			lb++;
			hb.pop();
		}
		ans=std::max(ans, 2*std::min(cb-lb,ca-la));
	}
	std::cout << ans << '\n';
}