#include <cstdio>
#include <algorithm>
#include <vector>

int x,y;
const int max=2,mid=1,min=0;
std::vector<int> l;
int steps=0;


char acb;
int main()
{
	scanf("%i %i",&x, &y);
	for(int i=0;i<3;i++) l.push_back(y);
	while(l[0]!=x || l[1]!=x || l[2]!=x)
	{
		//printf("%i %i %i, min %i mid %i max %i\n",l[0],l[1],l[2],l[min],l[mid],l[max]);
		if(l[mid]+l[max]-1<x) l[min]=l[mid]+l[max]-1;
		else l[min]=x;
		std::sort(l.begin(),l.end());
		steps++;
		scanf("%i", &acb);
	}
	printf("%i", steps);
}