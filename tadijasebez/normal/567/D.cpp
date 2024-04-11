#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> shots;
const int N=200050;
int x[N];
int main()
{
	int n,k,a,q,i;
	scanf("%i %i %i",&n,&k,&a);
	a++;
	scanf("%i",&q);
	for(i=1;i<=q;i++) scanf("%i",&x[i]);
	int top=q,bot=1,mid,sol=-1;
	while(top>=bot)
	{
		int mid=top+bot>>1;
		shots.clear();
		shots.push_back(0);
		shots.push_back(n+1);
		for(i=1;i<=mid;i++) shots.push_back(x[i]);
		sort(shots.begin(),shots.end());
		int z=0;
		for(i=1;i<shots.size();i++) z+=(shots[i]-shots[i-1])/a;
		if(z<k) sol=mid,top=mid-1;
		else bot=mid+1;
	}
	printf("%i\n",sol);
	return 0;
}