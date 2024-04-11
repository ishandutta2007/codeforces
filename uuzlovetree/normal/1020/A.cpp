#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,h,a,b,q;
int main()
{
	scanf("%d%d%d%d%d",&n,&h,&a,&b,&q);
	while(q--)
	{
		int t1,f1,t2,f2;
		int ans=0;
		scanf("%d%d%d%d",&t1,&f1,&t2,&f2);
		if(t1==t2)
		{
			printf("%d\n",abs(f2-f1));
			continue;
		}
		ans+=abs(t2-t1);
		int now=f1;
		if(f1<a)ans+=abs(f1-a),now=a;
		else if(f1>b)ans+=abs(f1-b),now=b;
		ans+=abs(now-f2);
		printf("%d\n",ans);
	}
	return 0;
}