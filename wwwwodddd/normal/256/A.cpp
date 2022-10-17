#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int n,f[4040][4040],a[4040];
int main()
{
	cin>>n;
	fo(i,n)
		scanf("%d",&a[i]);
	int z=1;
	for(int i=n-1;i>0;i--)
	{
		int p=0; 
		for(int j=n;j>i;j--)
		{
			f[i][j] = 2;
			if(p)
				f[i][j]=max(f[i][j],f[j][p]+1);
			if(a[i]==a[j])
				p=j;
			z=max(z,f[i][j]);
		}
	}
	cout<<z<<endl;
	return 0;
}