#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int l;
	int r;
};
Node a[100005];
int main()
{
	int n;
	cin>>n;
	string str;
	cin>>str;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='G')
		{
			sum++;
			a[sum].l=i;
			a[sum].r=i;
			while(i<n-1&&str[i+1]=='G')
			{
				i++;
				a[sum].r++;
			}
		}
	}
	if(sum==0)
	{
		cout<<"0\n";
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(sum==1&&a[i].r-a[i].l+1>ans)
		{
			ans=a[i].r-a[i].l+1;
		}
		if(sum>1&&a[i].r-a[i].l+2>ans)
		{
			ans=a[i].r-a[i].l+2;
		}
		if(i!=n)
		{
			if(a[i+1].l-a[i].r==2)
			{
				if(sum>2)
				{
					if(a[i].r-a[i].l+1+a[i+1].r-a[i+1].l+2>ans)
					{
						ans=a[i].r-a[i].l+1+a[i+1].r-a[i+1].l+2;
					}
				}
				else
				{
					if(a[i].r-a[i].l+1+a[i+1].r-a[i+1].l+1>ans)
					{
						ans=a[i].r-a[i].l+1+a[i+1].r-a[i+1].l+1;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}