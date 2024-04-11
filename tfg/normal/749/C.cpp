#include <iostream>
#include <string>

int n;
std::string str;
std::string next;

int main()
{
	std::cin >> n >> str;
	int d=0, r=0;
	while(str.size()!=1)
	{
		next="";
		int curd=0;
		int curr=0;
		for(int i=0;i<str.size();i++)
		{
			if(str[i]=='D')
			{
				curd++;
				if(r)
				{
					r--;
					continue;
				}
				d++;
				next+='D';
			}
			else
			{
				curr++;
				if(d)
				{
					d--;
					continue;
				}
				r++;
				next+='R';
			}
		}
		if(curd==str.size() || curr==str.size())
			break;
		std::swap(str, next);
		//std::cout << "previous is " << next << '\n';
		//std::cout << "next is " << str << '\n';
	}
	std::cout << str[0] << '\n';
}