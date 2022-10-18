#include<bits/stdc++.h>
using namespace std;
int prime[1000005];
struct Node
{
	int x;
	int y;
};
Node a[150005];
bool primee(int x)
{
	int to=sqrt(x)+1;
	if(x==2)
	{
		return true;
	}
	if(x==1)
	{
		return false;
	}
	for(int i=2;i<=to;i++)
	{
		if(x%i==0)
		{
			return false;
		}
	}
	return true;
}
bool cmp(Node x,Node y)
{
	return (x.x+x.y<y.x+y.y);
}
int m;
int size;
void fenjie(int x)
{
	for(int i=2;i<=x/i;i++)
	{
		if(x%i==0)
		{
			size++;
			prime[size]=i;
			while(x%i==0)
			{
				x/=i;
			}
		}
	}
	if(x!=1)
	{
		size++;
		prime[size]=x;
	}
}
int main()
{
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&a[i].x,&a[i].y);
	}
//	sort(a+1,a+m+1,cmp);
	fenjie(a[1].x);
	fenjie(a[1].y);
//	sort(prime+1,prime+size+1);
	for(int i=1;i<=size;i++)
	{
		if(prime[i]==prime[i-1])
		{
			continue;
		}
		bool ok=true;
		for(int j=2;j<=m;j++)
		{
			if((a[j].x%prime[i]!=0&&a[j].y%prime[i]!=0))
			{
				ok=false;
				break;
			}
		}
		if(ok==true)
		{
			cout<<prime[i]<<endl;
			return 0;
		}
	}
	cout<<"-1\n";
	return 0;
}
////////////aisdgfahbczjcbdsiyrf