#include <bits/stdc++.h> 
using namespace std;
typedef double D;
typedef pair<D,D> pdd;
const int MAXN=23;
const D INF=10001.0;
int main()
{
	D n,v,index;
	D a[MAXN],b[MAXN];
	cin>>n>>v;
	pdd p[21];
	for(int i=0;i<n;i++)	cin>>a[i];
	for(int i=0;i<n;i++)	cin>>b[i];
	D min=INF;
	for(int i=0;i<n;i++)	
	{
		p[i].first=a[i];
		p[i].second=b[i]/a[i];
		if(min>p[i].second)	min=p[i].second;
	}
	D ans=0.0000;
	for(int i=0;i<n;i++)	ans+=p[i].first;
	ans*=min;
	if(ans>v)	ans=v;
	cout<<ans;
	return 0;
}