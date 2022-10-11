#include <iostream>
#include <string>

int n;
int freq[2][10];
std::string str[2];

int main()
{
	std::cin >> n >> str[0] >> str[1];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2;j++)
			freq[j][str[j][i]-'0']++;
	}
	int win, lose;
	win=lose=0;
	for(int i=9;i>=0;i--)
	{
		for(int j=9;j>=i;j--)
		{
			int use=std::min(freq[0][i],freq[1][j]);
			freq[0][i]-=use;
			freq[1][j]-=use;
			//if(use)
			//	std::cout << "using " << use << " times " << i << " against " << j << '\n';
		}
		for(int j=0;j<=i;j++)
		{
			int use=std::min(freq[0][i],freq[1][j]);
			freq[0][i]-=use;
			freq[1][j]-=use;
			if(j<i)
				lose+=use;
			//if(use)
			//	std::cout << "using " << use << " times " << i << " against " << j << '\n';
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2;j++)
			freq[j][str[j][i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=9;j>i;j--)
		{
			int use=std::min(freq[0][i],freq[1][j]);
			freq[0][i]-=use;
			freq[1][j]-=use;
			if(j>i)
				win+=use;
			//if(use)
			//	std::cout << "using " << use << " times " << i << " against " << j << '\n';
		}
		for(int j=0;j<=i;j++)
		{
			int use=std::min(freq[0][i],freq[1][j]);
			freq[0][i]-=use;
			freq[1][j]-=use;
			//if(use)
			//	std::cout << "using " << use << " times " << i << " against " << j << '\n';
		}
	}
	std::cout << lose << '\n' << win << '\n';
}