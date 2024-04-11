#include <iostream>
#include <string>
#include <cstdio>

const int ms=200200;

std::string str, want;

int step[ms];
int cur_step=0;

int p[ms];

bool can(int num)
{
	cur_step++;
	for(int i=0;i<num;i++)
		step[p[i]]=cur_step;

	std::string cur;
	for(int i=0;i<str.size();i++)
	{
		if(step[i]!=cur_step)
			cur+=str[i];
	}
	//std::cout << num << ": " << cur << '\n';
	int on=0;
	for(int i=0;i<cur.size();i++)
	{
		if(want[on]==cur[i])
			on++;
		if(on==want.size())
			return true;
	}
	return false;
}

int main()
{
	std::cin >> str >> want;
	for(int i=0;i<str.size();i++)
	{
		scanf("%i",p+i);
		p[i]--;
	}
	int l=0;
	int r=str.size()-1;

	while(l!=r)
	{
		int mid=(l+r+1)/2;
		if(can(mid))
			l=mid;
		else
			r=mid-1;
	}
	std::cout << l << '\n';
}