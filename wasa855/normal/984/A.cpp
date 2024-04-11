#include<bits/stdc++.h>
using namespace std;
int a[1005]; 
int main()
{
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+m+1);
	cout<<a[(m-1)/2+1]<<endl;
	return 0;
}