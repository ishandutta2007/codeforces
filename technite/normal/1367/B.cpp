#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> v(n);
		int odd=0,even=0;
		for(int i=0;i<n;i++) cin>>v[i];
		for(int i=0;i<n;i++)
		{
			if(i%2!=v[i]%2)
			{
				if(i%2)odd++;
				else even++;
			}
		}
		if(odd!=even) cout<<-1<<'\n';
		else
		{
			cout<<odd<<'\n';
		}
	}
}