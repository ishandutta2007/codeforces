#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;
#define N 100005
int n,a[N],b[N];long long ans;
priority_queue<pair<int ,int > >q;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),q.push(make_pair(a[i],1));
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),q.push(make_pair(b[i],-1));
	int p=1;
	while(!q.empty())
	{
		pair<int ,int >x=q.top();q.pop();
		if(x.second==p)ans+=p*x.first;p=-p;
	}printf("%lld\n",ans);
}