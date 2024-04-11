#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=1000050;
const int M=N*2;
vector<int> x[M];
int rs[M],ls[M],clock,root;
void Set(int &c, int ss, int se, int qi, int r)
{
	if(!c) c=++clock;
	x[c].push_back(r);
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,r);
	else Set(rs[c],mid+1,se,qi,r);
}
void Sort(int c, int ss, int se)
{
	if(!c) return;
	sort(x[c].begin(),x[c].end());
	if(ss==se) return;
	int mid=ss+se>>1;
	Sort(ls[c],ss,mid);
	Sort(rs[c],mid+1,se);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(x[c].empty()) return 0;
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return upper_bound(x[c].begin(),x[c].end(),qe)-x[c].begin();
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
vector<int> Q;
int main()
{
	int n,m,q,i,l,r,k,x;
	scanf("%i %i",&n,&q);m=n;
	while(m--) scanf("%i %i",&l,&r),Set(root,1,N,l,r);
	Sort(root,1,N);
	while(q--)
	{
		scanf("%i",&k);
		Q.clear();
		Q.push_back(0);
		Q.push_back(N);
		while(k--) scanf("%i",&x),Q.push_back(x);
		sort(Q.begin(),Q.end());
		int ans=n;
		for(i=1;i<Q.size();i++) ans-=Get(root,1,N,Q[i-1]+1,Q[i]-1);
		printf("%i\n",ans);
	}
	return 0;
}