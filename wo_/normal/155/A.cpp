#include<cstdio>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int min,max,cnt=0;
	for(int i=0;i<n;i++)
	{
		int in;
		scanf("%d",&in);
		if(i==0)
		{
			min=in;max=in;
			continue;
		}
		if(in<min)
		{
			min=in;
			cnt++;
		}
		if(in>max)
		{
			max=in;
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}