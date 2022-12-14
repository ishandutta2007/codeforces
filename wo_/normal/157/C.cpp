#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string from_,from,to;
	cin>>from_;
	cin>>to;
	int n=to.size();
	for(int i=0;i<n;i++)
	{
		from+='#';
	}
	from+=from_;
	for(int i=0;i<n;i++)
	{
		from+='#';
	}
	int ans=n;
	for(int i=0;i<from.size()-n;i++)
	{
		int dis=0;
		for(int j=i;j<i+n;j++)
		{
			if(from[j]!=to[j-i]) dis++;
		}
		ans=min(ans,dis);
	}
	printf("%d\n",ans);
	return 0;
}