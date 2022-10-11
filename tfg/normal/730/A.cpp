#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>

typedef std::pair<int,int> ii;

std::set<ii>::iterator it1,it2;
std::set<ii> players;

std::string str;

std::string plays[10010];

int main()
{
	int n;
	scanf("%i",&n);
	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%i",&temp);
		str+='0';
		players.insert(ii(temp,i));
	}
	int cur_play=0;
	while(1)
	{
		it1=players.end();
		ii p1,p2;
		it1--;
		it2=it1;
		p1= *(it1);
		if(players.begin()->first==p1.first)
			break;
		int cur_max=p1.first;
		it1--;
		p2= *(it1);
		
		if(p2.first!=p1.first)
		{
			//std::cout << "first case\n";
			plays[cur_play]=str;
			plays[cur_play][p1.second]='1';
			plays[cur_play][p2.second]='1';
			players.erase(it1);
			players.erase(it2);
			p1.first=std::max(p1.first-1,0);
			p2.first=std::max(p2.first-1,0);
			players.insert(p1);
			players.insert(p2);
		}
		else
		{
			//std::cout << "second case\n";
			it1=it2;
			plays[cur_play]=str;
			std::stack<ii> old;
			int count=0;
			while(it1->first==cur_max && count<6)
			{
				//std::cout << "went through " << it1->second << std::endl;
				plays[cur_play][it1->second]='1';
				old.push(*it1);
				it1--;
				count++;
			}
			if(count==6)
			{
				while(count>4)
				{
					int num_p=old.top().second;
					plays[cur_play][num_p]='0';
					count--;
					old.pop();
					it1++;
				}
			}
			it1++;
			players.erase(it1,players.end());
			while(!old.empty())
			{
				ii nownow=old.top();
				nownow.first=std::max(nownow.first-1,0);
				players.insert(nownow);
				old.pop();
			}
		}
		cur_play++;
	}
	printf("%i\n%i\n",players.begin()->first,cur_play);
	for(int i=0;i<cur_play;i++)
		printf("%s\n",plays[i].c_str());
}