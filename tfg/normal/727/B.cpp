#include <string>
#include <iostream>

bool is_digit(char x)
{
	if(x>'9' || x<'0')
		return false;
	return true;
}

typedef long long int ll;

ll ans=0;

void print_num(ll x)
{
	ll next=x/1000;
	if(x==0)
		return;
	
	print_num(next);
	if(next!=0)
		std::cout << (x/100)%10 << (x/10)%10 << x%10;
	else
		std::cout << x;
	if(x!=ans/100)
		std::cout << '.';
}

int main()
{
	std::string str;
	std::cin >> str;
	int on=0;
	while(on!=str.size())
	{
		while(!is_digit(str[on]))
			on++;
		int blocks=0;
		int nums=0;
		ll cur_ans=0;
		while(on<str.size() && (is_digit(str[on]) || str[on]=='.'))
		{
			if(str[on]=='.')
			{
				blocks++;
				nums=0;
			}
			else
			{
				cur_ans=(cur_ans)*10+str[on]-'0';
				nums++;
			}
			on++;
		}
		if(blocks==0 || nums==3)
		{
			cur_ans*=100;
		}
		ans+=cur_ans;
	}
	print_num(ans/100);
	if(ans/100==0)
	{
		std::cout << 0;
	}
	if(ans%100!=0)
		std::cout << '.' << (ans/10)%10 << ans%10;
	std::cout << '\n';
	
}