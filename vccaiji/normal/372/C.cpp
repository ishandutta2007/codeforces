#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long ans[160000];
long long cans[160000];
int r[160000];
int leftt,rightt;
int main()
{
	std::ios::sync_with_stdio(0);
    long long n,m,d;
	cin>>n>>m>>d;
	long long a,b,t,lt;
	for(int oo=1;oo<=m;oo++)
	{
		cin>>a>>b>>t;
		if(oo==1)
		{
			for(int i=1;i<=n;i++)
			 ans[i]=b-fabs(i-a);
			lt=t;
			continue; 
		}
		for(int i=1;i<=n;i++) cans[i]=ans[i];
		long long y=(t-lt)*d;
		for(long long i=1;i<=n;i++)
		{
			if(i==1)
			{
				leftt=1;
				rightt=0;
				long long o=min(y+1,n);
				for(int j=1;j<=o;j++)
				{
					for(;;)
					{
						if(rightt<leftt) break;
						if(cans[r[rightt]]>cans[j]) break;
						rightt--;
					}
					rightt++;
					r[rightt]=j;
				}
				ans[1]=cans[r[leftt]]+b-fabs(a-1);
				continue;
			}
			if((i>=y+2)&&(r[leftt]==i-y-1)) leftt++;
			if(i+y<=n)
			{
				for(;;)
				{
					if(rightt<leftt) break;
					if(cans[r[rightt]]>cans[i+y]) break;
					rightt--;
				}
				rightt++;
				r[rightt]=i+y;
			}
			ans[i]=cans[r[leftt]]+b-fabs(a-i);
		}
		lt=t;
	}
	long long u=-10000000000000000;
	for(int i=1;i<=n;i++) if(u<ans[i]) u=ans[i];
	cout<<u;
	return 0; 
}