#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,s,a[N];
int main() 
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	bool q=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==a[i+1])
		{
			if(q||(i!=0&&a[i]-1==a[i-1])||a[i]==0)
			{
				cout<<"cslnb\n";
				return 0;
			}
			q=1;
		}
		s+=a[i];
	}
	s-=(n*(n-1))/2;
	if(s%2)
		cout<<"sjfnb\n";
	else 
		cout<<"cslnb\n";
	return 0;
}