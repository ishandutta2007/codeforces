#include <iostream>
#include <string>

const int ms=1000*500*2+1000;
const int eps='z'-'a'+2;

std::string str;

int to[ms][eps];
bool p[ms];
int size=1;

int first=0, second=0, inter=0;

int get_ind()
{
	int on=1;
	for(int i=0;i<str.size();i++)
	{
		int nxt=to[on][str[i]-'a'];
		if(!nxt)
		{
			size++;
			nxt=size;
			to[on][str[i]-'a']=size;
		}
		on=nxt;
	}
	return on;
}

void first_player()
{
	int ind=get_ind();
	p[ind]=true;
	first++;
}

void second_player()
{
	int ind=get_ind();
	if(p[ind])
	{
		inter++;
		first--;
	}
	else
		second++;
}


int main()
{
	int n, m;
	std::cin >> n >> m;

	for(int i=0;i<n;i++)
	{
		std::cin >> str;
		first_player();
	}

	for(int i=0;i<m;i++)
	{
		std::cin >> str;
		second_player();
	}

	while(1)
	{
		//poland ball
		if(inter)
			inter--;
		else
		{
			if(first)
				first--;
			else
			{
				std::cout << "NO\n";
				return 0;
			}
		}

		//enemy ball
		if(inter)
			inter--;
		else
		{
			if(second)
				second--;
			else
			{
				std::cout << "YES\n";
				return 0;
			}
		}
	}

}