#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int n;
	cin>>n;
	int maxn=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>maxn+1)
		{
			cout<<i<<endl;
			return 0;
		}
		if(a[i]>maxn)
		{
			maxn=a[i];
		}
	}
	cout<<"-1\n";
	return 0;
}
//asdfa