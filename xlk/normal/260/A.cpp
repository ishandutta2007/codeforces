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
ll a,b,n;
int ok(ll a,ll b,ll n)
{
	a%=b;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<10;j++)
			if((a*10+j)%b==0)
			{
				a=(a*10+j)%b;
				goto end;
			}
		return 0;
		end:;
	}
	return 1;
}
void mk(ll a,ll b,ll n)
{
	cout << a;
	a%=b;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<10;j++)
			if((a*10+j)%b==0)
			{
				printf("%d",j);
				a=(a*10+j)%b;
				break;
			}
	}
}
int main()
{
	cin>>a>>b>>n;
	if(!ok(a,b,n))
		puts("-1");
	else
		mk(a,b,n);
}