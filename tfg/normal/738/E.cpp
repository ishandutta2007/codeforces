#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

const int ms=int(1e5)*2+10;

int n,s;

int a[ms];
bool nv[ms];
int coringa=0;

int b[ms];

int main()
{
	scanf("%i %i",&n,&s);
	int ans=0;
	int total=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%i",a+i);
		if(i==s)
		{
			if(a[i]!=0)
				ans++;
		}
		else
		{
			if(a[i]==0)
			{
				ans++;
				nv[i]=true;
				coringa++;
			}
			else
			{
				b[a[i]]++;
				total++;
			}
		}
	}
	int missing=0;
	int got=0;
	int global_ans=ans;
	for(int i=1;i<n;i++)
	{
		got+=b[i];
		if(!b[i])
			missing++;
		int cur_m=std::max(0,missing-coringa-(total-got));
		int cur_ans=ans+cur_m+(total-got);
		if(i==1)
			global_ans=int(1e9);
		global_ans=std::min(global_ans,cur_ans);
		//std::cout << "on " << i << " ans is " << cur_ans << '\n';
	}
	std::cout << global_ans << '\n';
}