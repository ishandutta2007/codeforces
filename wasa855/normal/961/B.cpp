#include<bits/stdc++.h>
using namespace std;
#define ok fsjejsklf
#define data fsjesklf
#define add fsjejslf
bool ok[100005];
int data[100005];
int add[100005];
int main()
{
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&data[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&ok[i]);
	}
	int all=0;
	for(int i=1;i<=m;i++)
	{
		add[i]=add[i-1];
		if(ok[i]==true)
		{
			all+=data[i];
		}
		else
		{
			add[i]+=data[i];
		}
	}
	int maxn=0;
	for(int i=1;i<=m-n+1;i++)
	{
//		cout<<add[i+n-1]-add[i-1]<<" ";
		if(maxn<add[i+n-1]-add[i-1])
		{
			maxn=add[i+n-1]-add[i-1];
		}
	}
//	cout<<endl;
	cout<<all+maxn<<endl;
	return 0;
}