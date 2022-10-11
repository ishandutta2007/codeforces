#include <iostream>
#include <string>

std::string str[2];
char to[256];

int main()
{
	std::cin >> str[0] >> str[1];
	bool valid=true;
	int ans=0;
	for(int i=0;i<str[0].size();i++)
	{
		if(str[0][i]!=str[1][i])
		{
			char c[2];
			c[0]=str[0][i];
			c[1]=str[1][i];
			for(int i=0;i<2;i++)
			{
				if(!to[c[i]])
					ans++;
				if(to[c[i]] && to[c[i]]!=c[1-i])
					valid=false;
				to[c[i]]=c[1-i];
			}
		}
		else
		{
			char c=str[0][i];
			if(to[c] && to[c]!=c)
				valid=false;
			to[c]=c;
		}
	}
	ans/=2;
	if(!valid)
		std::cout << "-1\n";
	else
	{
		std::cout << ans << '\n';
		for(int i=0;i<256;i++)
		{
			if(to[i] && to[i]!=i)
			{
				std::cout << (char)i << ' ' << (char)to[i] << '\n';
				to[to[i]]=0;
			}
		}
	}

}