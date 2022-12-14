#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 100005
#define ll long long
#define lson l,m,tr[rt].ls
#define rson m+1,r,tr[rt].rs
struct Segment{int ls,rs,siz;}tr[N*31];
int n,k,A,B,rot,cnt;
void insert(int x,int l,int r,int &rt)
{
	if(!rt)rt=++cnt;tr[rt].siz++;if(l==r)return ;int m=(l+r)>>1;
	if(x<=m)insert(x,lson);else insert(x,rson);
}
ll solve(int l,int r,int rt)
{
	if(!rt)return A;if(l==r)return (ll)B*tr[rt].siz;int m=(l+r)>>1;
	return min((ll)B*(r-l+1)*tr[rt].siz,solve(lson)+solve(rson));
}
int main()
{
	scanf("%d%d%d%d",&n,&k,&A,&B);
	for(int i=1,x;i<=k;i++)scanf("%d",&x),insert(x,1,1<<n,rot);
	printf("%lld\n",solve(1,1<<n,rot));
}