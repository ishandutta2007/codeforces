//CF 888G
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int N = 222222;
const int K = 29;
const int inf = 2e9;
int n,a[N];
LL ans;
int merge(int l1,int r1,int l2,int r2,int k){ //[l,r)
	if(l1==r1||l2==r2||k<0)
		return 0;
	int i,j,res;
	for(i=l1;i<r1;i=i+1)
		if(a[i]&(1<<k))
			break;
	for(j=l2;j<r2;j=j+1)
		if(a[j]&(1<<k))
			break;
	res=inf;
	if(i!=l1&&j!=l2)
		res=min(res,merge(l1,i,l2,j,k-1));
	if(i!=r1&&j!=r2)
		res=min(res,merge(i,r1,j,r2,k-1));
	if(res<inf)
		return res;
	return merge(l1,r1,l2,r2,k-1)+(1<<k);
}
void solve(int l,int r,int k){ //[l,r)
	if(l==r||k<0)
		return;
	int i;
	for(i=l;i<r;i=i+1)
		if(a[i]&(1<<k))
			break;
	solve(l,i,k-1);
	solve(i,r,k-1);
	ans+=(LL)merge(l,i,i,r,K);
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i=i+1)
		scanf("%d",a+i);
	sort(a,a+n);
	ans=0;
	solve(0,n,K);
	cout<<ans<<endl;
	return 0;
}