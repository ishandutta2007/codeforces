/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=100100;
const int P=1000000007;
int n,m,K;
int main()
{
	while(~scanf("%d%d%d",&n,&m,&K))
	{
		if(n+m-2<K)
		{
			puts("-1");
			continue;
		}
		LL ret=0;
		if(n>K)ret=max(ret,(LL)n/(K+1)*m);
		else ret=max(ret,(LL)m/(K-n+2));
		if(m>K)ret=max(ret,(LL)m/(K+1)*n);
		else ret=max(ret,(LL)n/(K-m+2));
		cout<<ret<<endl;
	}
}