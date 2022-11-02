#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
typedef __int64 LL;
LL ans;
int n,a[100100],te,i;
int main()
{
	while(~scanf("%d",&n))
	{
		ans=(LL)n;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		te=1;
		for(i=1;i<n;i++)
		{
			if(a[i]==a[i-1])
			te++;
			else
			{
				ans+=(LL)te*(te-1)/2;
				te=1;
			}
		}
		ans+=(LL)te*(te-1)/2;
		cout<<ans<<endl;
	}
}