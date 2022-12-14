#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define ll long long
#define N 100005
int n,a[N],b[N],ans[N],cnt=1,num;
vector<int>v[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[a[i]]++,v[a[i]].push_back(i);
	for(int i=0;i<n;i++)
		if(b[i])
		{
			if(b[i]%(n-i)!=0)return puts("Impossible"),0;
			int lim=(n-i);
			for(int j=0;j<b[i];j++,cnt+=(j%lim==0))ans[v[i][j]]=cnt,num++;
		}
	if(num!=n)return puts("Impossible"),0;
	puts("Possible");
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}