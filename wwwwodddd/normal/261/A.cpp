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
int n,m;
int a[100020];
int b[100020];
long long z;
int s;
int main()
{
	cin>>n;
	fr(i,n)
		cin>>a[i];
	cin>>m;
	fr(i,m)
		cin>>b[i];
	sort(a,a+n);
	sort(b,b+m);
	reverse(b,b+m);
	int w=*min_element(a,a+n);
	for(int i=0;i<m;i++)
	{
		if(i%(w+2)<w)
			z+=b[i];
	}
	cout << z << endl;
}