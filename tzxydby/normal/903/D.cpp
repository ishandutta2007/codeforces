#include<bits/stdc++.h>
using namespace std;
map<int,int>m;
long double n,a,sum,ans;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		int b=a;
		ans+=i*a-sum+m[b+1]-m[b-1];
		sum+=a;
		m[b]++;
	}
	printf("%.0Lf\n",ans);
	return 0;
}