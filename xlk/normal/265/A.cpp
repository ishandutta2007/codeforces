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
char a[10020];
char b[10020];
int n,m,z,s;
int main()
{
	scanf("%s%s",a,b);
	for(int i=0;b[i];i++)
		if(a[s]==b[i])
			s++;
	cout << s+1 << endl;
	return 0;
}