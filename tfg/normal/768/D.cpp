#include <iostream>

const double eps=1e-7;
const int ms=1010;
const int md=10010;

int n;

bool visit[ms][md];
double memo[ms][md];

double dp(int orbs, int day)
{
	if(orbs>n)
		return 0.0;
	if(day==0)
	{
		if(orbs==n)
			return 1.0;
		else
			return 0.0;
	}
	double &ans=memo[orbs][day];
	if(visit[orbs][day])
		return ans;
	visit[orbs][day]=true;
	ans=dp(orbs, day-1)*((double)(n-orbs)/(double)n)+dp(orbs+1, day-1)*((double)(orbs+1)/n);
	return ans;
}

int main()
{
	int q;
	std::cin >> n >> q;
	while(q--)
	{
		int wut;
		std::cin >> wut;
		double wanted=(wut-eps)/2000.0;
		int l=n, r=md-1;
		while(l!=r)
		{
			int mid=(l+r)/2;
			if(dp(0, mid)<wanted)
				l=mid+1;
			else
				r=mid;
		}
		std::cout << l << '\n';
	}
}