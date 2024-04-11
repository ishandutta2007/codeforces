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
typedef long long ll;
int n,x;
ll a[100020];
int main()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ll mn=*min_element(a+1,a+1+n);
	int p=0;
	for(int i=x+1;i<=n;i++)
		if(a[i]==mn)
			p=i;
	for(int i=1;i<=x;i++)
		if(a[i]==mn)
			p=i;
	int s=0;
	if(p<=x)
		s=x-p;
	else
		s=n+x-p;
	a[p]+=mn*n+s;
	for(int i=1;i<=n;i++)
		a[i]-=mn;
	for(int i=p,j=0;j<s;j++,i++)
		a[i%n+1]--;
	for(int i=1;i<=n;i++)
		cout << a[i] << ' ';
	return 0;
}