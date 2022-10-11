#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int> vec;
int n;

int main()
{
	scanf("%i", &n);
	for(int i=0;i<n;i++)
	{
		int temp;scanf("%i", &temp);
		int j;
		for(j=0;j<vec.size();j++) if(vec[j]==temp) break;
		if(j==vec.size()) vec.push_back(temp);
		if(vec.size()>3)
		{
			printf("NO");
			return 0;
		}
	}
	std::sort(vec.begin(),vec.end());
	if(vec.size()==1) printf("YES");
	else if(vec.size()==2) printf("YES");
	else
	{
		if(vec[2]-vec[1]==vec[1]-vec[0])printf("YES");
		else printf("NO");
	}
}