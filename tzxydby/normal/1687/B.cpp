#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,a[N],od[N],s,in[N];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cout<<"? ";
		for(int j=1;j<=m;j++)
		{
			if(i==j)
				cout<<"1";
			else
				cout<<"0";
		}
		cout<<endl;
		cin>>a[i];
		od[i]=i;
	}
	sort(od+1,od+m+1,[&](int x,int y){return a[x]<a[y];});
	for(int i=1;i<=m;i++)
	{
		int p=od[i];
		s+=a[p];
		in[p]=1;
		cout<<"? ";
		for(int j=1;j<=m;j++)
		{
			if(in[j])
				cout<<"1";
			else
				cout<<"0";
		}
		cout<<endl;
		int t;
		cin>>t;
		if(s!=t)
		{
			s-=a[p];
			in[p]=0;
		}
	}
	cout<<"! "<<s<<endl;
	return 0;
}