#include <iostream>
#include <cstdio>

const int ms=200200;

int n, k, a, m;

int step[ms];
int cur_step=0;

int shot[ms];

bool f(int move)
{
	cur_step++;
	for(int i=0;i<move;i++)
		step[shot[i]-1]=cur_step;

	int on=0;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(step[i]==cur_step)
		{
			on=0;
			continue;
		}
		else
		{
			on++;
			if(on==a)
			{
				step[i+1]=cur_step;
				ans++;
				on=0;
			}
		}
	}
	return ans>=k;
}

int main()
{
	std::cin >> n >> k >> a >> m;
	for(int i=0;i<m;i++)
		scanf("%i",shot+i);
	if(f(m))
	{
		std::cout << "-1\n";
		return 0;
	}
	int l=1;
	int r=m;
	while(l!=r)
	{
		int mid=(l+r)/2;
		if(f(mid))
			l=mid+1;
		else
			r=mid;
	}
	std::cout << l << '\n';
}