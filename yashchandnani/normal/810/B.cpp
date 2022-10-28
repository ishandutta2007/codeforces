#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	long long int sum=0;
	int x,l;
	std::vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		cin>>x>>l;
		sum+=min(x,l);
		if (l-x>0)
		{
			v.push_back(min(l-x,x));
		}
	}
	if (!v.empty())
	{
		sort(v.begin(),v.end());
		int y=v.size();
		y-=k;
		y=max(y,0);
		for (int i = y; (i < v.size())&&(i>=0); ++i)
		{
			sum+=v[i];
		}
	}
	cout<<sum<<endl;
	
	return 0;
}