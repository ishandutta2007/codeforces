#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<set>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
typedef long long ll;
ll l=1LL<<32;
ll f[1000];
ll s;
int k;
set<ll>z;
int main()
{
	cin>>s>>k;
	k=min(34,k);
	f[k]=1;
	int cnt;
	for(int i=k+1;;i++)
	{
		for(int j=1;j<=k;j++)
			f[i]+=f[i-j];
		if(f[i]>l)
		{
			cnt=i;
			break;
		}
	}
	for(int i=cnt;i>0;i--)
		if(s>=f[i])
		{
			s-=f[i];
			z.insert(f[i]);
		}
	z.insert(0);
	cout<<z.size()<<endl;
	fe(i,z)
		cout<<*i<<' ';
	return 0;
}