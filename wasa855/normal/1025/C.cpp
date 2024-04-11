#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	cin>>a;
	a+=a;
	int maxn=1;
	int t=1;
	for(int i=1;i<a.length();i++)
	{
		if(a[i]!=a[i-1])
		{
			t++;
			maxn=max(t,maxn);
		}
		else
		{
			maxn=max(t,maxn);
			t=1;
		}
	}
//	cout<<maxn<<endl;
	int ttt=a.length()/2;
	cout<<min(maxn,ttt)<<endl;;
	return 0;
}