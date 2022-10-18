#include<bits/stdc++.h>
using namespace std;
#define eps (1e-6)
int n;
struct Node
{
	double x;
	double y;
	bool used;
};
Node a[1005];
bool cmp(double k,double b)
{
//	cout<<k<<" "<<b<<"\n";
	for(int i=1;i<=n;i++)
	{
		a[i].used=false;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(abs(a[i].y-(a[i].x*k+b))<=eps)
		{
			a[i].used=true;
//			cout<<i<<" ";
		}
		else
		{
			cnt++;
		}
	}
//	cout<<"\n";
	if(cnt==0)
	{
		return false;
	}
	if(cnt==1)
	{
		return true;
	}
	double x1,x2,y1,y2;
	bool res=false;
	for(int i=1;i<=n;i++)
	{
		if(a[i].used==false)
		{
			if(res==false)
			{
				x1=a[i].x;
				y1=a[i].y;
				res=true;
			}
			else if(res==true)
			{
				x2=a[i].x;
				y2=a[i].y;
				break;
			}
		}
	}
	double k2=(y2-y1)/(x2-x1);
	double b2=y2-k2*x2;
	if(k2!=k)
	{
		return false;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i].used==true)
		{
			continue;
		}
		if(abs(a[i].y-(a[i].x*k2+b2))<=eps)
		{
			a[i].used=true;
			cnt--;
		}
	}
	if(cnt==0)
	{
		return true;
	}
	return false;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i].x=i;
		scanf("%lf",&a[i].y);
	}
	double k=(a[2].y-a[1].y)/(a[2].x-a[1].x);
	double b=a[1].y-k*a[1].x;
	if(cmp(k,b)==true)
	{
		cout<<"Yes\n";
		return 0;
	}
	k=(a[3].y-a[1].y)/(a[3].x-a[1].x);
	b=a[1].y-k*a[1].x;
	if(cmp(k,b)==true)
	{
		cout<<"Yes\n";
		return 0;
	}
	k=(a[3].y-a[2].y)/(a[3].x-a[2].x);
	b=a[2].y-k*a[2].x;
	if(cmp(k,b)==true)
	{
		cout<<"Yes\n";
		return 0;
	}
	cout<<"No\n";
	return 0;
}