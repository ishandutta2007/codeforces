#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int sum1[N],sum2[N];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		int sum=0,mc=0,flag=1;
		for(int j=0;j<s.size();j++)
		{
			if(s[j]=='(')
				sum++;
			else
				sum--;
			mc=min(mc,sum);
		}
		if(sum>=0)
		{
			if(mc>=0)
				sum1[sum]++;
		}
		else if(-mc<=-sum)
			sum2[-sum]++;
	}
	int ans=0;
	for(int i=1;i<=600000;i++)
		ans+=min(sum1[i],sum2[i]);
	ans+=sum1[0]/2;
	cout<<ans<<endl;
	return 0;
}