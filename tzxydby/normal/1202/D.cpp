#include<bits/stdc++.h>
using namespace std; 
long long t,n,zyb,x,y,z;
void work(long long x)
{
	if(x==0)
		return;
	long long l=0,r=sqrt(x)+20;
	while(r-l>1)
	{
		long long mid=(l+r)/2;
		if(1LL*mid*(mid-1)<=x)
			l=mid;
		else 
			r=mid;
	}
	work(x-l*(l-1));
	for(int i=zyb;i<l;i++)
		cout<<"3";
	cout<<"7";
	zyb=l;
}
int main()
{ 
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		cin>>n;
		n*=2;
		zyb=0;
		cout<<"1";
		work(n);
		cout<<endl;
	}
	return 0;
}