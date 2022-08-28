//CF1404C
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
const int N = 333333;
const int M = 1<<20;
const int inf = 1e9;
int n,q,a[N],ans;
vector<int> v[M];
void build(int k=1,int l=1,int r=n){
	if(l==r){
		if(a[l]<=l)
			v[k].push_back(l-a[l]);
		v[k].push_back(inf);
		return;
	}
	int h=l+r>>1,i,j,x;
	build(k<<1,l,h);
	build(k<<1|1,h+1,r);
	x=0;
	for(i=0,j=0;x<N;){
		if(v[k<<1][i]<v[k<<1|1][j]-i)
			x=v[k<<1][i],i++;
		else
			x=v[k<<1|1][j]-i,j++;
		v[k].push_back(x);
	}
}

void query(int L,int R,int k=1,int l=1,int r=n){
	if(L<=l&&r<=R){
		ans+=upper_bound(v[k].begin(),v[k].end(),ans)-v[k].begin();
		return;
	}
	int h=l+r>>1;
	if(L<=h)
		query(L,R,k<<1,l,h);
	if(h<R)
		query(L,R,k<<1|1,h+1,r);
}
int main()
{
	int i,x,y;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	build();
	for(i=1;i<=q;i=i+1){
		scanf("%d%d",&x,&y);
		ans=0;
		query(x+1,n-y);
		printf("%d\n",ans);
	}
	return 0;
}