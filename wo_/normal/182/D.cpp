#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	string str1,str2;
	cin>>str1>>str2;
	int n=str1.size(),m=str2.size();
	int d=__gcd(n,m);
	string base=str1.substr(0,d);
	bool flg=true;
	for(int i=0;(i+1)*d<=n;i++)
	{
		string cmp=str1.substr(i*d,d);
		if(cmp!=base) flg=false;
	}
	for(int i=0;(i+1)*d<=m;i++)
	{
		string cmp=str2.substr(i*d,d);
		if(cmp!=base) flg=false;
	}
	if(flg==false)
	{
		printf("0\n");
		return 0;
	}
	vector<int> divs;
	for(int i=1;i*i<=d;i++)
	{
		if(d%i==0)
		{
			divs.push_back(i);
			if(i*i!=d) divs.push_back(d/i);
		}
	}
	int ans=0;
	for(int i=0;i<divs.size();i++)
	{
		int sz=divs[i];
		bool flg=true;
		string cmp=base.substr(0,sz);
		for(int j=0;(j+1)*sz<=d;j++)
		{
			string cmp2=base.substr(j*sz,sz);
			if(cmp!=cmp2) flg=false;
		}
		if(flg) ans++;
	}
	printf("%d\n",ans);
	return 0;
}