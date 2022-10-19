#include<bits/stdc++.h>
using namespace std;
int check(int x)
{
	int cnt[10]={};
	while(x)
	{
		cnt[x%10]++;
		x/=10;
	}
	for(int i=0;i<=9;i++)
		if(cnt[i]>1)
			return 0;
	return 1;
}
int main()
{
	int l,r;
	cin>>l>>r;
	for(int i=l;i<=r;i++)
	{
		if(check(i))
		{
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}