#include <cstdio>
#include <iostream>
#include <utility>
#include <string>
#include <algorithm>

typedef std::pair<int, int> ii;
typedef std::pair<double, double> dd;

inline int readint()
{
	int temp;
	scanf("%i",&temp);
	return temp;
}

int freq[1000];
int types=0;

int main()
{
	int n=readint();
	std::string str;
	std::cin >> str;
	for(int i=0;i<n;i++)
	{
		if(freq[str[i]]==0)
		{
			freq[str[i]]++;
			types++;
		}
	}
	for(int i=0;i<1000;i++)
		freq[i]=0;
	int right=0;
	int left=0;
	int cur_type=0;
	int ans=999999;
	for(;right<n;right++)
	{
		int ind=str[right];
		if(freq[ind]==0)
			cur_type++;

		freq[ind]++;
		//printf("adding %c, freq %i. freq left is %i\n",str[right],freq[ind]);
		while(freq[str[left]]>1)
		{
			freq[str[left]]--;
			left++;
		}
		if(cur_type==types)
			ans=std::min(ans,right-left+1);
	}
	printf("%i\n",ans);
}