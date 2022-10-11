#include <iostream>
#include <cstdio>
#include <queue>

const int ms=200200;

int n, k;
int a[ms], b[ms];

typedef long long ll;

int main()
{
	std::cin >> n >> k;
	for(int i=0;i<n;i++)
		scanf("%i",a+i);
	for(int i=0;i<n;i++)
		scanf("%i",b+i);
	std::priority_queue<ll> hp;
	ll suma=0, sumb=0;
	for(int i=0;i<n;i++)
	{
		suma+=a[i];
		sumb+=b[i];
		hp.push(-(a[i]-b[i]));
	}
	int got=0;
	ll ans=sumb;
	while(!hp.empty())
	{
		if(hp.top()>=0)
		{
			ans-=hp.top();
		}
		else
		{
			if(got>=k)
				break;
			ans-=hp.top();
		}
		hp.pop();
		got++;
	}
	std::cout << ans << '\n';
}