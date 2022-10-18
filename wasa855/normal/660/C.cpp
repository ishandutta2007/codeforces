#include<bits/stdc++.h>
using namespace std;
int a[300005];
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(k==0)
	{
		int ans=0;
		int al=0,ar=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				int t=0;
				while(a[i]==1)
				{
					i++;
					t++;
				}
				if(t>ans)
				{
					ans=t;
					ar=i;
					al=ans-ar+1;
				}
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)
		{
			printf("%d ",a[i]);
		}
		return 0;
	}
	int l=1,r=1,x=(a[1]==0?1:0);
	if(x!=k)
	{
		while(x<=k&&r<=n)
		{
			r++;
			if(a[r]==0)
			{
				x++;
				if(x==k)
				{
					break;
				}
			}
		}
	}
	while(a[r+1]==1&&r<=n)
	{
		r++;
	}
	if(r>n)
	{
		cout<<n<<endl;
		for(int i=1;i<=n;i++)
		{
			printf("1 ");
		}
		cout<<"\n";
		return 0;
	}
//	printf("%d %d\n",l,r);
	int ans=r;
	int al=1,ar=r;
	while(r<=n)
	{
		while(a[l]==1)
		{
			l++;
		}
		l++;
		while(a[r+1]==1&&r<=n)
		{
			r++;
		}
		r++;
		while(a[r+1]==1&&r<=n)
		{
			r++;
		}
//		printf("%d %d\n",l,r);
		if(r>n)
		{
			r=n;
			if(ans<r-l+1)
			{
				ans=r-l+1;
				al=l;
				ar=r;
			}
			break;
		}
		if(ans<r-l+1)
		{
			ans=r-l+1;
			al=l;
			ar=r;
		}
	}
	cout<<ans<<endl;
//	cout<<al<<" "<<ar<<endl; 
	for(int i=al;i<=ar;i++)
	{
		a[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}