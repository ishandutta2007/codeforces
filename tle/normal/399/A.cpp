#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int rp[100001];
int main()
{
	int n,p,k;
	cin>>n>>p>>k;
	int ll=max(p-k,1),rr=min(p+k,n);
	if(ll!=1) cout<<"<<";
	cout<<" ";
	for(int i=ll;i<=rr;i++)
	{
		if(i==p) cout<<"(";
		cout<<i;
		if(i==p) cout<<")";
		cout<<" ";
	}
	if(rr!=n) cout<<">>";
}