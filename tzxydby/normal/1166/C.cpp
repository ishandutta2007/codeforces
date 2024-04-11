#include<bits/stdc++.h>
using namespace std;
#define all(s) (s.begin(),s.end())
vector<int>s1,s2;
map<int,int>a;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		a[abs(x)]++;
		if(x<0)
			s1.push_back(-x);
		else
			s2.push_back(x);
	}
	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());
	long long ans=0;
	for(int i=0;i<s1.size();i++)
	{
		int x=s1[i];
		ans+=lower_bound(s1.begin(),s1.end(),x)-upper_bound(s1.begin(),s1.end(),(x+1)/2-1);
		ans+=lower_bound(s2.begin(),s2.end(),x)-upper_bound(s2.begin(),s2.end(),(x+1)/2-1);
	}
	for(int i=0;i<s2.size();i++)
	{
		int x=s2[i];
		ans+=lower_bound(s1.begin(),s1.end(),x)-upper_bound(s1.begin(),s1.end(),(x+1)/2-1);
		ans+=lower_bound(s2.begin(),s2.end(),x)-upper_bound(s2.begin(),s2.end(),(x+1)/2-1);
	}
	for(auto i=a.begin();i!=a.end();i++)
		ans+=1LL*(i->second)*(i->second-1)/2;
	cout<<ans<<endl;
	return 0;
}