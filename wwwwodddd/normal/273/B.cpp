#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
map<int,vector<int> >g;
int n,x,m;
long long z=1;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		scanf("%d",&x),g[x].push_back(i);
	for(int i=0;i<n;i++)
		scanf("%d",&x),g[x].push_back(i);
	cin>>m;
	fe(i,g)
	{
		vector<int>&a=i->second;
		sort(a.begin(),a.end());
		int c=0;
		for(int i=1;i<a.size();i++)
			if(a[i]==a[i-1])
				c++;
		for(int i=1;i<=a.size();i++)
		{
			int j=i;
			while(c&&j%2==0)
			{
				j/=2;
				c--;
			}
			z=z*j%m;
		}
	}
	cout << z <<endl;
	return 0;
}