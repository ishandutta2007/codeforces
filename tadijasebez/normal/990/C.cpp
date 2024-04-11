#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
const int N=300050;
string s[N];
int l[N],r[N];
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		cin >> s[i];
		int len=s[i].size();
		int cnt=0;
		bool ok=1;
		for(j=0;j<len;j++)
		{
			if(s[i][j]=='(') cnt++;
			else cnt--;
			if(cnt<0) ok=0;
		}
		if(ok) l[cnt]++;
		cnt=0;ok=1;
		for(j=len-1;j>=0;j--)
		{
			if(s[i][j]==')') cnt++;
			else cnt--;
			if(cnt<0) ok=0;
		}
		if(ok) r[cnt]++;
	}
	ll sol=0;
	for(i=0;i<N;i++) sol+=(ll)l[i]*r[i];
	printf("%lld\n",sol);
	return 0;
}