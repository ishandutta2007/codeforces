#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	int m;
	cin>>m;
	for(int i=1;i<=m/2;i++)
	{
		scanf("%d",&a[i]);
	}
	int x=0,y=0;
	sort(a+1,a+m/2+1);
	for(int i=1;i<=m/2;i++)
	{
		x+=abs(a[i]-(i*2-1));
		y+=abs(a[i]-i*2);
	}
	cout<<min(x,y)<<endl;
}