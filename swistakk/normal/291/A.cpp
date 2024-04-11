#include <iostream>
#include <algorithm>
#define N 1000005
using namespace std;
int dosort[N];
int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>dosort[i];
	}
	sort(dosort+1, dosort+1+n);
	int par=0;
	int st=2;
	while(dosort[st]==0)
	{
		st++;
	}
	for(int i=st; i<=n; i++)
	{
		if(dosort[i]==dosort[i-1])
		{
			par++;
			if(dosort[i]==dosort[i-2])
			{
				cout<<"-1"<<endl;
				return 0;
			}
		}
	}
	cout<<par<<endl;
	return 0;
}