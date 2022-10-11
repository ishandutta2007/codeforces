#include <iostream>
#include <string>

int ans=1;

int main()
{
	int n;
	std::cin >> n;
	std::string str;
	std::cin >> str;
	int on=0;
	char U=0, R=0;
	while(on<str.size())
	{
		char cur=str[on];
		if(cur=='U' || cur=='D')
		{
			if(U && U!=cur)
			{
				R=0;
				ans++;
			}
			U=cur;
		}
		else
		{
			if(R && R!=cur)
			{
				U=0;
				ans++;
			}
			R=cur;
		}

		on++;
	}
	std::cout << ans << '\n';
}