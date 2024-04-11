#include <iostream>
#include <cstdlib>

typedef long long int ll;

ll s, from, to;
ll tram, me;
ll pos, dir;

int main()
{
	std::cin >> s >> from >> to;
	std::cin >> tram >> me;
	std::cin >> pos >> dir;
	ll ans=abs(to-from)*me;
	//std::cout << "original ans: " << ans << '\n';
	ll my_dir;
	if(to>from)
		my_dir=1;
	else
		my_dir=-1;
	if(my_dir==1)
	{
		ll cur_pos=pos;
		ll cur_dir=dir;
		ll cur_time=0;
		while(cur_dir!=my_dir || cur_pos>from)
		{
			//std::cout << "on " << cur_pos << ", time is " << cur_time << '\n';
			if(cur_dir==1)
			{
				cur_time+=(s-cur_pos)*tram;
				cur_pos=s;
				cur_dir=-1;
			}
			else
			{
				cur_time+=(cur_pos)*tram;
				cur_pos=0;
				cur_dir=1;
			}
		}
		cur_time+=(to-cur_pos)*tram;
		//std::cout << "on " << cur_pos << ", time is " << cur_time << '\n';
		ans=std::min(ans, cur_time);
	}
	else
	{
		ll cur_pos=pos;
		ll cur_dir=dir;
		ll cur_time=0;
		while(cur_dir!=my_dir || cur_pos<from)
		{
			//std::cout << "on " << cur_pos << ", time is " << cur_time << '\n';
			if(cur_dir==1)
			{
				cur_time+=(s-cur_pos)*tram;
				cur_pos=s;
				cur_dir=-1;
			}
			else
			{
				cur_time+=(cur_pos)*tram;
				cur_pos=0;
				cur_dir=1;
			}
		}
		cur_time+=abs(to-cur_pos)*tram;
		//std::cout << "on " << cur_pos << ", time is " << cur_time << '\n';
		ans=std::min(ans, cur_time);
	}
	std::cout << ans << '\n';
}