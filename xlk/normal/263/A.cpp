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
int n=5,zi,zj;
int a[10][10];
int main()
{
	fr(i,n)
		fr(j,n)
		{
			cin>>a[i][j];
			if(a[i][j])
				zi=i,zj=j;
		} 
	cout << abs(zi-2)+abs(zj-2) << endl;
}