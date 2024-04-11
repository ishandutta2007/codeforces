#include<bits/stdc++.h>
using namespace std;
#define N 10005
int m,n;
struct Set
{
	int siz;
	bool a[N];
	Set operator & (Set x)
	{
		Set ans;
		ans.siz=0;
		memset(ans.a,0,sizeof(ans.a));
		for(int i=1;i<=n;i++)
		{
			if(a[i]==true&&x.a[i]==true)
			{
				ans.a[i]=true;
				ans.siz++;
			}
		}
		return ans;
	}
};
Set s[55];
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&s[i].siz);
		int tmp=0;
		for(int j=1;j<=s[i].siz;j++)
		{
			scanf("%d",&tmp);
			s[i].a[tmp]=true;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=i+1;j<=m;j++)
		{
			Set res=s[i]&s[j];
			if(res.siz==0)
			{
				cout<<"impossible\n";
				return 0;
			}
		}
	}
	cout<<"possible\n";
	return 0;
}