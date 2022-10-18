#include<bits/stdc++.h>
using namespace std;
struct node
{
	bool a[30];
	long long data;
};
node a[1005];
bool cmp(node x,node y)
{
	return x.data<y.data;
}
long long powa(long long x,long long y)
{
	long long ans=1;
	for(long long i=1;i<=y;i++)
	{
		ans*=x;
	}
	return ans;
}
int main()
{
	int m;
	cin>>m;
	char t[1005];
	int len;
	for(int i=1;i<=m;i++)
	{
		scanf("%s",t);
		len=strlen(t);
		for(int j=0;j<len;j++)
		{
			a[i].a[t[j]-'a']=true;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<='z'-'a';j++)
		{
			if(a[i].a[j]==true)
			{
				a[i].data+=powa(2,j);
			}
		}
	}
	sort(a+1,a+m+1,cmp);
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		if(a[i].data!=a[i+1].data)
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}