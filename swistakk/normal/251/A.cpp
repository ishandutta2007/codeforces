#include <iostream>
#include <algorithm>
#define uint long long int
using namespace std;
uint odl[100005];
int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	uint d;
	cin>>n>>d;
	for(int i=1; i<=n; i++)
	{
		cin>>odl[i];
	}
	sort(odl+1, odl+1+n);
	uint wynik=0;
	uint p1=1, p2=3;
	while(p2<=n)
	{
		while(odl[p1]+d<odl[p2])
		{
			p1++;
		}
		wynik+=(p2-p1)*(p2-p1-1)/2;
		p2++;
	}
	cout<<wynik<<endl;
	return 0;
}