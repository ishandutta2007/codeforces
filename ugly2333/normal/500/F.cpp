//CF500F
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
const int N = 4444;
const int M = 23333;
const int inf = 1e9;
int n,w=4000,q,m,t,a[N],b[N],l[N],r[N],qt[M],qw[M],ans[M];
pair<int,int> p[M];
vector<int> v[1<<17];
int f[22][N];
void modify(int L,int R,int i,int k=1,int l=1,int r=m){
	if(L<=l&&r<=R){
		v[k].push_back(i);
		return;
	}
	int h=l+r>>1;
	if(L<=h)
		modify(L,R,i,k<<1,l,h);
	if(h<R)
		modify(L,R,i,k<<1|1,h+1,r);
}
void go(int d,int x){
	int i;
	for(i=w;i>=b[x];i=i-1)
		f[d][i]=max(f[d][i],f[d][i-b[x]]+a[x]);
}
void solve(int k,int l,int r,int d){
	int i;
	for(i=0;i<=w;i=i+1)
		f[d][i]=f[d-1][i];
	for(i=0;i<v[k].size();i=i+1)
		go(d,v[k][i]);
	if(l==r){
		i=p[l].second;
		ans[i]=f[d][qw[i]];
		return;
	}
	int h=l+r>>1;
	solve(k<<1,l,h,d+1);
	solve(k<<1|1,h+1,r,d+1);
}
int main()
{
	int i,x;
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d%d",b+i,a+i,l+i);
		r[i]=l[i]+t-1;
	}
	scanf("%d",&q);
	for(i=1;i<=q;i=i+1){
		scanf("%d%d",qt+i,qw+i);
		p[i]=make_pair(qt[i],i);
	}
	sort(p+1,p+q+1);
	m=q;
	for(i=1;i<=n;i=i+1){
		l[i]=lower_bound(p+1,p+q+1,make_pair(l[i],-inf))-p;
		r[i]=lower_bound(p+1,p+q+1,make_pair(r[i],inf))-p-1;
		if(l[i]<=r[i])
			modify(l[i],r[i],i);
	}
	solve(1,1,m,1);
	for(i=1;i<=q;i=i+1)
		printf("%d\n",ans[i]);
	return 0;
}