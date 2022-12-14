#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<cstdio>
#include<bitset>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 100005
int d[N],n,x,y;
int ans;
double m;
int main()
{
	scanf("%d%lf",&n,&m);
	for(int i=1;i<n;i++)scanf("%d%d",&x,&y),d[x]++,d[y]++;
	if(n==2)return printf("%.6f\n",m),0;
	for(int i=1;i<=n;i++)ans+=(d[i]==1);
	return printf("%.7f\n",m/ans*(double)2),0;
}