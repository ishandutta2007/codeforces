#include<bits/stdc++.h>
using namespace std;
int t,n,K,i,j,k,lt,rt,mid;
string s;
int work(int l1,int r1,int l2,int r2)
{
	cout<<"? "<<r1-l1+1<<' '<<r2-l2+1<<endl;
	for(int i=l1;i<=r1;++i)
		cout<<i<<' ';
	cout<<endl;
	for(int i=l2;i<=r2;++i)
		cout<<i<<' ';
	cout<<endl;
	cout.flush();
	cin>>s;
	if(s[0]=='E')
		return 0;
	if(s[0]=='F')
		return 1;
	return -1;
}
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>K;
		for(i=1;i<=10;i++)
		{
			j=rand()%(n-1)+2;
			if(work(1,1,j,j)<0)
				break;
		}
		if(i<=10)
		{
			cout<<"! "<<1<<endl;
			continue;
		}
		for(i=0;(1<<(i+1))<n;i++)
			if(work(1,1<<i,(1<<i)+1,1<<(i+1))>0)
				break;
		lt=(1<<i)+1,rt=min(n,1<<(i+1));
		while(lt<rt)
		{
			mid=(lt+rt)/2;
			if(work(1,mid-(1<<i),(1<<i)+1,mid)>0)
				rt=mid;
			else
				lt=mid+1;
		}
		cout<<"! "<<lt<<endl;
	}
	return 0;
}