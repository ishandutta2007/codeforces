#include <iostream>
#include <vector>
using namespace std;
vector <long long> v[210005];
vector <long long> v2[210005];
int main(int argc, char** argv) {
	int n,m;
	cin >> n >> m;
	if(n==1&&m)
	{
		cout << 0;
		return 0;
	}
	for(int i=1;i<=n;i++)
		v[i+105000].push_back(i),v2[i].push_back(i);
	long long ans=n*n;
	for(int i=1;i<=m;i++)
	{
		long long x;
		cin >> x;
		x+=105000;
		if(v[x-i].size()<v[x-i-1].size())
		{
			//cout << x-i << " " << v[x-i].size() << endl;
			for(int j=0;j<v[x-i].size();j++)
				v[x-i-1].push_back(v[x-i][j]);
			v[x-i].clear();
		}
		else
		{
			//cout << x-i << " " << v[x-i].size() << endl;
			swap(v[x-i],v[x-i-1]);
			for(int j=0;j<v[x-i].size();j++)
				v[x-i-1].push_back(v[x-i][j]);
			v[x-i].clear();
		}
		x-=105000;
		if(v2[x+i].size()<v2[x+i+1].size())
		{
			for(int j=0;j<v2[x+i].size();j++)
				v2[x+i+1].push_back(v2[x+i][j]),--ans;
			v2[x+i].clear();
		}
		else
		{
			swap(v2[x+i],v2[x+i+1]);
			for(int j=0;j<v2[x+i].size();j++)
				v2[x+i+1].push_back(v2[x+i][j]),--ans;
			v2[x+i].clear();
		}
	}
	ans=0;
	for(int i=0;i<=210000;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			//cout << v[i][j] << " " << i << endl;
			long long t=i-105000+m+1;
			if(t>n)
				t=n;
			ans+=t-v[i][j]+1;
		}
		for(int j=0;j<v2[i].size();j++)
		{
			//cout << v2[i][j] << " " << i << endl;
			long long t=i-m-1;
			if(t<1)
				t=1;
			ans+=v2[i][j]-t;
		}
	}
	cout << ans;
	return 0;
}