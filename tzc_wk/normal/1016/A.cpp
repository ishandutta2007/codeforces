#include <bits/stdc++.h>
using namespace std;
const int maxn=200000+100;
int a[maxn],ans[maxn];
int main()
{
	int n,m,cur=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		ans[i]=(a[i]+cur)/m;
		cur=(a[i]+cur)%m;
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}