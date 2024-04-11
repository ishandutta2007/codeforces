#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
vector<int>ans;
int main()
{
	int n,s1=0,s2=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s1+=a[i];
		if(2*a[i]<=a[1]||i==1)
		{
			s2+=a[i];
			ans.push_back(i);
		}
	}
	if(s2>=(s1)/2+1)
	{
		cout<<ans.size()<<endl;
		for(auto i:ans)
			cout<<i<<' ';
	}
	else
		cout<<0;
	return 0;
}