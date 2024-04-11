//CF 1017B
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
char s[111111],t[111111];
LL a[2][2];
int main()
{
	int n,i;
	LL x;
	scanf("%d%s%s",&n,s,t);
	for(i=0;i<n;i=i+1)
		a[s[i]-'0'][t[i]-'0']++;
	x=a[0][1]*a[1][0]+a[0][0]*a[1][0]+a[0][0]*a[1][1];
	cout<<x;
	return 0;
}