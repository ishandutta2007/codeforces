#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<double,int> di;
int i,n,cnt;
double l,L,v1,v2;
vector<di>a;
double z[100020];
int main()
{
	cin>>n>>l>>v1>>v2;
	L=l*v2/(v1+v2);
	for(i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		double t=x;
		double p=t-L;
		if(p<0)
		{
			a.push_back(di(p+2*l,1));
			a.push_back(di(2*l,-1));
			a.push_back(di(0,1));
			a.push_back(di(t,-1));
		}
		else
		{
			a.push_back(di(p,1));
			a.push_back(di(t,-1));
		}
	}
	a.push_back(di(0,0));
	a.push_back(di(2*l,0));
	sort(a.begin(),a.end());
	for(i=0;i<a.size();i++)
	{
		if(i>0)
			z[cnt]+=a[i].first-a[i-1].first;
		cnt+=a[i].second;
	}
	for(i=0;i<=n;i++)
		printf("%0.10lf\n",z[i]/=2*l);
	return 0;
}