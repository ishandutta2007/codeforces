#include <iostream>
#include <set>
#include <utility>

typedef std::pair<int, int> ii;

std::set<ii> hmm;

ii p[3];

int main()
{
	for(int i=0;i<3;i++)
		std::cin >> p[i].first >> p[i].second;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(i==j)
				continue;
			ii curp=ii(p[i].first-p[j].first,p[i].second-p[j].second);
			for(int k=0;k<3;k++)
			{
				if(i==k || j==k)
					continue;
				ii got=ii(p[k].first+curp.first,p[k].second+curp.second);
				hmm.insert(got);
				//std::cout << "got (" << got.first << ',' << got.second << ")\n";
			}
		}
	}
	std::cout << int(hmm.size()) << '\n';
	std::set<ii>::iterator it=hmm.begin();
	while(it!=hmm.end())
	{
		std::cout << it->first << ' ' << it->second << '\n';
		it++;
	}
}