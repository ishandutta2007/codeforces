#include <iostream>
#include <string>

std::string s, t;
int freq[256];
int to[256];

int main()
{
	std::cin >> s >> t;
	for(auto a : s)
		freq[a]++;
	int on = 0, pt = 0;
	while(on != s.size())
	{
		char got = 0;
		if(freq[t[on % t.size()]])
			got = t[on % t.size()];
		else if(freq['?'])
			got = '?';
		else
		{
			while(!freq[pt])
				pt++;
			got = pt;
		}
		freq[got]--;
		if(got == '?')
		{
			got = t[on % t.size()];
			to[t[on % t.size()]]++;
		}
		on++;
	}
	pt = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] != '?')
			continue;
		while(!to[pt])
			pt++;
		to[pt]--;
		s[i] = pt;
	}
	std::cout << s << '\n';
}