#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a,b;
ll m;
int main()
{
	cin>>m;
	cin>>a>>b;
	ll sum01=0,sum00=0;
	ll sum10=0,sum11=0;
	for(ll i=0;i<m;i++)
	{
		if(b[i]=='0')
		{
			if(a[i]=='0')
			{
				sum00++;
			}
			else
			{
				sum10++;
			}
		}
		else
		{
			if(a[i]=='0')
			{
				sum01++;
			}
			else
			{
				sum11++;
			}
		}
	}
//	printf("%d %d %d %d\n",sum00,sum01,sum10,sum11);
	ll ans=sum10*(sum00+sum01)+sum00*(sum10+sum11)-sum00*sum10;
	cout<<ans<<endl;
	return 0;
}