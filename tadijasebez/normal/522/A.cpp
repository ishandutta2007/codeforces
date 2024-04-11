#include <stdio.h>
#include <map>
#include <iostream>
#include <cstring>
using namespace std;
map<string,int> dp;
int sol;
string f,s,r;
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,i,j;
	dp["polycarp"]=1;
	scanf("%i",&n);
	for(i=0;i<n;i++)
	{
		cin >> f >> r >> s;
		for(j=0;j<f.size();j++) f[j]=tolower(f[j]);
		for(j=0;j<s.size();j++) s[j]=tolower(s[j]);
		dp[f]=dp[s]+1;
		sol=max(sol,dp[f]);
	}
	printf("%i\n",sol);
	return 0;
}