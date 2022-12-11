#include<bits/stdc++.h>
using namespace std;
const int max_n=100+5;
int a[max_n];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	int ans=0;
	for(int i=1;i<=n;++i)
		ans+=a[i];
	cout<<ans<<endl;
	return 0;
}