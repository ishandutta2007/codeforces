#include <cstdio>
#include <algorithm>

const int ms=100100;

int n;
int cost[ms];
int a[ms];

int bsearch(int right, int diff)
{
	diff=a[right]-diff;
	int left=0;
	while(right!=left)
	{
		int mid=(left+right+1)/2;
		if(a[mid]>=diff)
			right=mid-1;
		else
			left=mid;
	}
	//printf("got %i\n",left);
	return left;
}

int main()
{
	scanf("%i",&n);
	for(int i=1;i<=n;i++)
	{
		//printf("on %i\n",i);
		scanf("%i",a+i);
		cost[i]=cost[i-1]+20;
		cost[i]=std::min(cost[i], cost[bsearch(i, 90-1)]+50);
		cost[i]=std::min(cost[i], cost[bsearch(i, 1440-1)]+120);
		printf("%i\n",cost[i]-cost[i-1]);
	}
}