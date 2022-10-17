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
int n,a[100020],b[100020];
int z;
int main()
{
	cin>>n;
	fr(i,n)
		cin>>a[i],b[i]=a[i];
	sort(b,b+n);
	fr(i,n)
		if(a[i]!=b[i])
			z++;
	if(z<=2)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}