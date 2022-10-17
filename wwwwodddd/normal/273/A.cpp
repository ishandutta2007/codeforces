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
long long a[100020];
long long n;
long long h;
int q;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>q;
	for(int i=0;i<q;i++)
	{
		long long x,y;
		cin>>x>>y;
		long long z=max(h,a[x]);
		cout << z << endl;
		h=z+y;
	}
	return 0;
}