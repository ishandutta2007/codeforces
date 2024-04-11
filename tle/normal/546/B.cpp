#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int n,a[100001];
int main()
{
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		int add=max(a[i-1]-a[i]+1,0);
		a[i]+=add; ans+=add;
	}
	cout<<ans;
}