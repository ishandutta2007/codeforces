#include<bits/stdc++.h>
using namespace std;
vector<pair<int,string>>ans;
int main()
{
	ios::sync_with_stdio(false);
	int n,m,k;
	cin>>n>>m>>k;
	if(m==1)
	{
		if(k>2*(n-1))
			cout<<"NO"<<endl;
		else
		{
			cout<<"YES"<<endl;
			if(k<=(n-1))
			{
				cout<<1<<endl;
				cout<<k<<' '<<"D"<<endl;
			}
			else
			{
				cout<<2<<endl;
				cout<<(n-1)<<' '<<"D"<<endl;
				k-=n-1;
				cout<<k<<' '<<"U"<<endl;
			}
		}
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		if(k<=3*(m-1))
		{
			ans.emplace_back(k/3,"RDU");
			if(k%3==1)
				ans.emplace_back(1,"R");
			if(k%3==2)
				ans.emplace_back(1,"RD");
			k=0;
			break;
		}
		else
		{
			ans.emplace_back(m-1,"RDU");
			k-=3*(m-1);
		}
		if(k<=m-1)
		{
			ans.emplace_back(k,"L");
			k=0;
			break;
		}
		else
		{
			ans.emplace_back(m-1,"L");
			k-=m-1;
		}
		ans.emplace_back(1,"D");
		k--;
		if(!k)
			break;
	}
	if(k)
	{
		if(k<=m-1)
		{
			ans.emplace_back(k,"R");
			k=0;
		}
		else
		{
			ans.emplace_back(m-1,"R");
			k-=m-1;
		}
	}
	if(k)
	{
		if(k<=m-1)
		{
			ans.emplace_back(k,"L");
			k=0;
		}
		else
		{
			ans.emplace_back(m-1,"L");
			k-=m-1;
		}
	}
	if(k>n-1)
		cout<<"NO"<<endl;
	else
	{
		if(k)
			ans.emplace_back(k,"U");
		cout<<"YES"<<endl;
		int sz=ans.size();
		for(auto i:ans)
			if(!i.first)
				sz--;
		cout<<sz<<endl;
		for(auto i:ans)
			if(i.first)
				cout<<i.first<<' '<<i.second<<endl;
	}
	return 0;
}