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
int n,z;
int a[100020];
int f[100020];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	for(int i=0;i<n;i++)
	{
		int w=0;
		for(int j=1;j*j<=a[i];j++)
			if(a[i]%j==0)
				w=max(w,max(f[j],f[a[i]/j]));
		w++;
		for(int j=1;j*j<=a[i];j++)
			if(a[i]%j==0)
			{
				if(j>1)
					f[j]=max(f[j],w);
				if(a[i]/j>1)
					f[a[i]/j]=max(f[a[i]/j],w);
			}
		z=max(z,w);
	}
	cout << z << endl;
}