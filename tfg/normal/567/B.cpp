#include <iostream>
#include <string>

const int ms=1001000;

std::string s[ms];
int num[ms];
bool exist[ms];
int cur_freq[ms];

int main()
{
	int n;
	std::cin >> n;
	for(int i=1;i<=n;i++)
		std::cin >> s[i] >> num[i];
	for(int i=1;i<=n;i++)
	{
		if(s[i][0]=='-')
		{
			if(!exist[num[i]])
			{
				for(int j=0;j<i;j++)
					cur_freq[j]++;
				exist[num[i]]=true;
			}
			exist[num[i]]=false;
			cur_freq[i]=cur_freq[i-1]-1;
		}
		else
		{
			exist[num[i]]=true;
			cur_freq[i]=cur_freq[i-1]+1;
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)
		ans=std::max(ans, cur_freq[i]);
	std::cout << ans << '\n';
}