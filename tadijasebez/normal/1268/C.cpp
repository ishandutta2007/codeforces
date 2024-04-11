#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=200050;
int p[N],id[N];
const int M=2*N;
struct SegmentTree
{
	int ls[M],rs[M],tsz,root;
	ll sum[M],lzy[M];
	SegmentTree(){}
	void Build(int &c, int ss, int se)
	{
		c=++tsz;sum[c]=lzy[c]=ls[c]=rs[c]=0;
		if(ss==se) return;
		int mid=ss+se>>1;
		Build(ls[c],ss,mid);
		Build(rs[c],mid+1,se);
	}
	void Build(){ Build(root,1,N);}
	void Upd(int c, int ss, int se, int f){ sum[c]+=(ll)(se-ss+1)*f;lzy[c]+=f;}
	void Push(int c, int ss, int se)
	{
		int mid=ss+se>>1;
		Upd(ls[c],ss,mid,lzy[c]);
		Upd(rs[c],mid+1,se,lzy[c]);
		lzy[c]=0;
	}
	void Set(int c, int ss, int se, int qs, int qe, int f)
	{
		if(qs>qe || qs>se || ss>qe) return;
		if(qs<=ss && qe>=se){ Upd(c,ss,se,f);return;}
		int mid=ss+se>>1;
		Push(c,ss,se);
		Set(ls[c],ss,mid,qs,qe,f);
		Set(rs[c],mid+1,se,qs,qe,f);
		sum[c]=sum[ls[c]]+sum[rs[c]];
	}
	void Set(int qs, int qe, int f){ Set(root,1,N,qs,qe,f);}
	ll Get(int c, int ss, int se, int qs, int qe)
	{
		if(qs>qe || qs>se || ss>qe) return 0;
		if(qs<=ss && qe>=se) return sum[c];
		Push(c,ss,se);
		int mid=ss+se>>1;
		return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
	}
	ll Get(int qs, int qe){ return Get(root,1,N,qs,qe);}
} L,R;
struct BIT
{
	int sum[N];
	BIT(){}
	void Set(int i, int f){ for(;i<N;i+=i&-i) sum[i]+=f;}
	int Get(int i){ int ans=0;for(;i;i-=i&-i) ans+=sum[i];return ans;}
	int Get(int l, int r){ return Get(r)-Get(l-1);}
} BT;
int main()
{
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++) scanf("%i",&p[i]),id[i]=i;
	sort(id+1,id+1+n,[&](int i, int j){ return p[i]<p[j];});
	ll ans=0;
	L.Build();
	R.Build();
	for(int k=1;k<=n;k++)
	{
		int i=id[k];
		ans+=BT.Get(i,n);
		BT.Set(i,1);
		L.Set(i,n,1);
		R.Set(1,i,1);
		int top=n,bot=1,mid,taj=0;
		int hal=k/2;
		while(top>=bot)
		{
			mid=top+bot>>1;
			if(BT.Get(mid)<=hal) bot=mid+1,taj=mid;
			else top=mid-1;
		}
		//printf("k:%i taj:%i ans:%lld\n",k,taj,ans);
		ll tmp=ans+L.Get(1,taj)+R.Get(taj+1,n);
		tmp-=(ll)hal*(hal+1)/2;
		hal=k-hal;
		tmp-=(ll)hal*(hal+1)/2;
		printf("%lld ",tmp);
	}
	return 0;
}