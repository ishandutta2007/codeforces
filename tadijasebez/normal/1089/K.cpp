#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=300050;
const int lim=1000050;
const int M=2*lim;
int t[N];
struct Node
{
	ll ans,ost;
	Node(int x=0){ ans=x,ost=0;}
};
Node operator + (Node a, Node b)
{
	Node ans;
	ans.ans=b.ans;
	b.ost-=a.ans-1;
	if(b.ost<0) ans.ans-=b.ost,b.ost=0;
	ans.ost=a.ost+b.ost;
	return ans;
}
int ls[M],rs[M],tsz,root;
Node node[M];
void Build(int &c, int ss, int se)
{
	c=++tsz;node[c]=Node(0);
	if(ss==se) return;
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	node[c]=node[ls[c]]+node[rs[c]];
}
void Set(int c, int ss, int se, int qi, int x)
{
	if(ss==se){ node[c]=Node(x);return;}
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,x);
	else Set(rs[c],mid+1,se,qi,x);
	node[c]=node[ls[c]]+node[rs[c]];
}
Node Get(int c, int ss, int se, int qs, int qe)
{
	if(qs<=ss && qe>=se) return node[c];
	int mid=ss+se>>1;
	if(qe<=mid) return Get(ls[c],ss,mid,qs,qe);
	if(qs>mid) return Get(rs[c],mid+1,se,qs,qe);
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
int main()
{
	int q,i,x;char ty;
	scanf("%i",&q);
	Build(root,1,lim);
	for(i=1;i<=q;i++)
	{
		scanf("\n%c %i",&ty,&t[i]);
		if(ty=='+') scanf("%i",&x),Set(root,1,lim,t[i],x);
		if(ty=='-') Set(root,1,lim,t[t[i]],0);
		if(ty=='?') printf("%lld\n",max(Get(root,1,lim,1,t[i]).ans,(ll)0));
	}
	//for(int i=1;i<=tsz;i++)
	//{
	//	printf("c:%i ans:%lld ost:%lld\n",i,node[i].ans,node[i].ost);
	//}
	return 0;
}