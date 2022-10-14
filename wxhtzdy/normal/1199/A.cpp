#include <bits/stdc++.h>
#define MAXN 100007
using namespace std;
int a[MAXN];
int main()
{
	int n,x,y; cin>>n>>x>>y;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++)
	{
		bool ok=true;
		for(int j=1;j<=x;j++) if(i-j>=0 && a[i]>=a[i-j]) ok=false;
		for(int j=1;j<=y;j++) if(i+j<n && a[i]>=a[i+j]) ok=false;
		if(ok)
		{
			cout<<i+1;
			return 0;
		}
	}
}