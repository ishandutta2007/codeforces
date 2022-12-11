#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define pll pair<ll,ll>
using namespace std;
int n;
int a[105];
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	bool yes=1;
	int ans=0;
	for(int i=2;i<=n;++i)
	{
		if(a[i]==1)
		{
			if(a[i-1]==1)yes=0;
			if(a[i-1]==2)ans+=3;
			if(a[i-1]==3)ans+=4;
		}
		if(a[i]==2)
		{
			if(a[i-1]==1)
			{
				if(a[i-2]==3)ans+=2;
				else ans+=3; 
			}
			if(a[i-1]==2)yes=0;
			if(a[i-1]==3)yes=0;
		}
		if(a[i]==3)
		{
			if(a[i-1]==1)ans+=4;
			if(a[i-1]==2)yes=0;
			if(a[i-1]==3)yes=0;
		}
	}
	if(!yes)
	{
		puts("Infinite");
	}
	else
	{
		puts("Finite");
		printf("%d\n",ans);
	}
}