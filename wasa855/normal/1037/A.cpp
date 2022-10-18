#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
	int n;
	cin>>n;
	a[1]=1;
	int tot=1;
	for(int i=2;;i++)
	{
		if(tot>=n)
		{
			cout<<i-1<<endl;
			return 0;
		}
		a[i]=a[i-1]*2;
		tot+=a[i];
	}
	return 0;
}