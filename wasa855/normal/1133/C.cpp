#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	queue<int> q;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		while(!q.empty()&&a[i]-q.front()>5)
		{
			q.pop();
		}
		q.push(a[i]);
		if(q.size()>ans)
		{
			ans=q.size();
		}
	}
	cout<<ans<<endl;
	return 0;
}
// dsfugvca