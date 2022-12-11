#include<bits/stdc++.h>
using namespace std;
int a[10],b[10];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,m,i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=m;i++) cin>>b[i];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j])
			{
				cout<<a[i]<<" ";
				break;
			}
	return 0;
}