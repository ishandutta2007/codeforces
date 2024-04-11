#include <bits/stdc++.h>
using namespace std;
long long s,k,n;
int house=1;
void go(int t,int m,int k)
{
	if(t+m<=k)
        t+=m;
    else
        t-=m;
}
int main()
{
	cin>>n>>k>>s;
	if(s<k)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	else if(s>(n-1)*k)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	for(int zz=k-1;zz>=0;zz--)
	{
		int ok=min(s-zz,n-1);
		s-=ok;
		if(house+ok<=n)	house=house+ok;
		else house=house-ok;
    	cout<<house<<" ";
	}
	return 0;
}