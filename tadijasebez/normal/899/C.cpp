#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
vector<int> sol;
ll abs(ll x){ return x>0?x:-x;}
int main()
{
	int i,j,n;
	scanf("%i",&n);
	ll g=(ll)n*(n+1)/2;
	ll goal=(g+1)/2;
	for(i=n;i;i--)
	{
		if(goal>=i)
		{
			sol.push_back(i);
			goal-=i;
		}
	}
	ll sec=g-(g+1)/2+goal;
	ll tr=(g+1)/2-goal;
	printf("%lld\n%i ",abs(sec-tr),sol.size());
	for(i=0;i<sol.size();i++) printf("%i ",sol[i]);
	return 0;
}