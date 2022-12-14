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
int n,Q,size,block,pos[N],L[N],R[N],num[N],c[N],b[N],a[N];
struct QaQ
{
	int l,r,idx;
	bool operator < (const QaQ &a) const {return pos[l]==pos[a.l]?r<a.r:l<a.l;}
}q[N];
int rl,rr;
void update(int x,int v){num[c[x]]--,c[x]+=v,num[c[x]]++;}
vector<int >v;
int calc()
{
	int ret=0,lst=0;
	priority_queue<int ,vector<int > ,greater<int >  >q;
	// printf("%d %d %d\n",c[1],c[2],c[3]);
	for(int i=0;i<v.size();i++)if(c[v[i]]>size)q.push(c[v[i]]);
	for(int i=1;i<=size;i++)b[i]=num[i];
	for(int i=1;i<=size;i++)if(b[i])
	{
		if(lst)
		{
			b[i]--;
			if(lst+i>size)q.push(lst+i);else b[i+lst]++;
			ret+=lst+i,lst=0;
		}
		if(b[i]&1)lst=i,b[i]--;ret+=b[i]*i;
		if(i*2>size)
			for(int j=1;j<=b[i]>>1;j++)q.push(i*2);
		else b[i<<1]+=b[i]>>1;
	}
	if(lst)q.push(lst);
	while(q.size()>1)
	{
		int x=q.top();q.pop();
		int y=q.top();q.pop();
		ret+=x+y;q.push(x+y);
	}
	return ret;
}
int ans[N];
int main()
{
	scanf("%d",&n);size=sqrt(n),block=n/size+1;
	for(int i=1;i<=block;i++)
	{
		L[i]=R[i-1]+1,R[i]=min(n,size*i);
		for(int j=L[i];j<=R[i];j++)pos[j]=i,scanf("%d",&a[j]),b[a[j]]++;
	}
	for(int i=1;i<=100000;i++)if(b[i]>size)v.push_back(i);scanf("%d",&Q);
	for(int i=1;i<=Q;i++)scanf("%d%d",&q[i].l,&q[i].r),q[i].idx=i;sort(q+1,q+Q+1);
	rr=0,rl=1;
	for(int i=1;i<=Q;i++)
	{
		while(rr<q[i].r)update(a[++rr],1);
		while(rl>q[i].l)update(a[--rl],1);
		while(rr>q[i].r)update(a[rr--],-1);
		while(rl<q[i].l)update(a[rl++],-1);
		// printf("\n%d %d\n",rl,rr);
		ans[q[i].idx]=calc();
	}
	for(int i=1;i<=Q;i++)printf("%d\n",ans[i]);
}