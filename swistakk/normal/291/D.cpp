#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	int n, k;
	cin>>n>>k;
	/* for(int i=1; i<=n; i++)
	{
		if((n-i)%2==0)
		{
			cout<<"1 ";
		}
		else
		{
			cout<<n<<" ";
		}
	} */
	//cout<<endl;
	int pot=1;
	for(int j=1; j<=k; j++)
	{
		for(int i=1; i<=n-1; i++)
		{
			if((n-i-1)&pot)
			{
				cout<<n-pot<<" ";
			}
			else
			{
				cout<<n<<" ";
			}
		}
		cout<<n<<" "<<endl;
		pot*=2;
	}
	return 0;
}