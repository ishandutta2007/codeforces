#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

int freq[2][256];
char p[2][2];

void fix()
{
	for(int i = 0; i < 2; i++)
	{
		while(freq[i][p[i][0]] == 0)
			p[i][0]++;
		while(freq[i][p[i][1]] == 0)
			p[i][1]--;
	}
}

int main()
{
	std::string s[2];
	while(std::cin >> s[0] >> s[1])
	{
		memset(freq, 0, sizeof freq);
		int n = s[0].size();
		for(int i = 0; i < 2; i++)
		{
			for(int j = 0; j < n; j++)
			{
				freq[i][s[i][j]]++;
			}
		}
		freq[0][0] = freq[1][0] = freq[0][255] = freq[1][255] = 1;
		
		/*for(int i = 0; i < 2; i++)
		{
			for(int j = 0; j < 256; j++)
			{
				if(freq[i][j])
					std::cout << "(" << i << ", " << (char)j << ")\n";
			}
		}*/
		
		p[0][1] = p[1][1] = 'z';
		p[0][0] = p[0][0] = 'a';
		
		std::string ans, aux;
		int bit = 0;
		for(int i = 0; i < n; i++)
		{
			fix();
			if(i % 2 == 0)
			{
				if(p[0][0] < p[1][1])
				{
					// ok
					ans += p[0][0];
					freq[0][p[0][0]]--;
				}
				else //min > max
				{
					bit |= 1;
					aux += '0';
				}
			}
			else
			{
				if(p[1][1] > p[0][0])
				{
					// ok
					ans += p[1][1];
					freq[1][p[1][1]]--;
				}
				else //max < min
				{
					bit |= 2;
					aux += '1';
				}
			}
		}
		std::reverse(aux.begin(), aux.end());
		for(int i = 0; i < aux.size(); i++)
		{
			//std::cout << "on " << i << ", letter " << aux[i] << '\n';
			fix();
			//std::cout << p[0][0] << ' ' << p[1][1] << '\n';
			if(aux[i] == '0')
			{
				aux[i] = p[0][0];
				freq[0][p[0][0]]--;
			}
			else
			{
				aux[i] = p[1][1];
				freq[1][p[1][1]]--;
			}
		}
		ans += aux;
		std::cout << ans << '\n';
	}
}