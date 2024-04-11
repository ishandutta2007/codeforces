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
int n;
ll x;
int sg(ll x)
{
    if(x>=2562991876LL)return 2;
    if(x>=45212176)return 1;
    if(x>=50626)return 1;
    if(x>=6724)return 3;
    if(x>=82)return 0;
    if(x>=16)return 2;
    if(x>=4)return 1;
    return 0;
}
int z;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%I64d",&x);
		z^=sg(x);
		
	}
	puts(z?"Furlo":"Rublo");
}