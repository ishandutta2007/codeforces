#include<bits/stdc++.h>
using namespace std;
const int max_m=1e5+5;
int a[max_m];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;++i)
			scanf("%d",a+i);
		sort(a+1,a+m+1);
		vector<int> v;
		for(int i=1;i<=m-1;++i)
			v.push_back(a[i+1]-a[i]-1);
		v.push_back(a[1]-1+n-a[m]);
		sort(v.begin(),v.end(),greater<int>());
		int ans=0,Time=0;
		for(int i=0;i<=m-1;++i)
		{
			int rem=v[i]-2*Time;
			if(rem<=0)
				continue;
			++ans,++Time;
			if(rem<=2)
				continue;
			ans+=rem-2,++Time;
		}
		printf("%d\n",n-ans);
	}
	return 0;
}