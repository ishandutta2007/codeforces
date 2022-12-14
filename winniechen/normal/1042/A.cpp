#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 105
int a[N],n,m,ans2,ans1;
priority_queue<int>q;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),q.push(-a[i]),ans2=max(ans2,a[i]);ans2+=m;
	while(m--)
	{
		int x=q.top();q.pop();
		q.push(x-1);
	}while(!q.empty())ans1=q.top(),q.pop();
	printf("%d %d\n",-ans1,ans2);
}