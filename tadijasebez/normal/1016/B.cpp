#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
#define ll long int
#define mp make_pair
#define pb push_back
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
string s,t;
const int N=1050;
int sum[N];
int main()
{
	int n,m,q,i,l,r;
	scanf("%i %i %i",&n,&m,&q);
	cin >> s >> t;
	for(i=0;i<n-m+1;i++)
	{
		if(s.substr(i,m)==t) sum[i+1]=1;
		sum[i+1]+=sum[i];
	}
	while(q--)
	{
		scanf("%i %i",&l,&r);
		if(r-l+1<m) printf("0\n");
		else printf("%i\n",sum[r-m+1]-sum[l-1]);
	}
	return 0;
}