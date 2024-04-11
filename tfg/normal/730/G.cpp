#include <iostream>
#include <set>
#include <utility>

typedef std::pair<int, int> ii;


int pref[220], days[220];
ii sch[220];

std::set<ii> inter;
std::set<ii>::iterator it,it2;

bool intersection(ii x, ii y)
{
	if(x.first>y.first)
		std::swap(x,y);
	//std::cout << "inter on (" << x.first<<','<<x.second<<"), ("<<y.first<<','<<y.second<<')'<<std::endl;
	

	if(x.first < y.first && x.second < y.first) return false;
	return true;
}

int main()
{
	int n;
	std::cin >> n;
	for(int i=0;i<n;i++)
		std::cin >> pref[i] >> days[i];
	sch[0]=ii(pref[0],pref[0]+days[0]-1);
	inter.insert(sch[0]);
	inter.insert(ii(0,0));
	for(int i=1;i<n;i++)
	{
		//std::cout << "entered on " << i << std::endl;
		//std::cout << "prev sch is " << sch[i-1].first << ' ' << sch[i-1].second << std::endl;
		it=inter.lower_bound(ii(pref[i],0));
		ii cur_i=ii(pref[i],pref[i]+days[i]-1);

		bool got_int=false;
		if(it!=inter.end())
		{
			
			if(intersection(*it,cur_i))
			{
				//std::cout << "got intersection\n";
				got_int=true;
			}
		}
		it--;
		if(!got_int && intersection(*it,cur_i))
		{
			//std::cout << "got intersection\n";
			got_int=true;
		}
		if(!got_int)
		{
			sch[i]=cur_i;
			inter.insert(cur_i);
			continue;
		}
		it=inter.begin();
		it2=it;
		it++;
		while(it!=inter.end())
		{
			if(it->first - it2->second - 1 >= days[i])
			{
				sch[i]=ii(it2->second+1,it2->second+days[i]);
				inter.insert(sch[i]);
				break;
			}
			it++;
			it2++;
		}
		if(it==inter.end())
		{
			sch[i]=ii(it2->second+1,it2->second+days[i]);
			inter.insert(sch[i]);
		}

	}
	for(int i=0;i<n;i++)
	{
		std::cout << sch[i].first << ' ' << sch[i].second << std::endl;
	}
}