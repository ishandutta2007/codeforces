#include <stdio.h>
#include <vector>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
int k;
struct Node
{
	ll sol;int sz;
	vector<pair<int,int> > l,r;
	Node(){}
	Node(int x){ sol=(x>=k);l.pb(mp(x,1));r.pb(mp(x,1));sz=1;}
	void Print()
	{
		printf("%lld %i\n",sol,sz);
		int i;
		for(i=0;i<l.size();i++) printf("(%i %i) ",l[i].first,l[i].second);printf("\n");
		for(i=0;i<r.size();i++) printf("(%i %i) ",r[i].first,r[i].second);printf("\n");
	}
};
Node operator + (Node a, Node b)
{
	Node ret;ret.sz=a.sz+b.sz;
	int i,j;
	ret.l=a.l;
	for(i=0;i<b.l.size();i++)
	{
		if((ret.l.back().first|b.l[i].first)==ret.l.back().first) ret.l[ret.l.size()-1].second+=b.l[i].second;
		else ret.l.pb(mp(ret.l.back().first|b.l[i].first,b.l[i].second));
	}
	ret.r=b.r;
	for(i=0;i<a.r.size();i++)
	{
		if((ret.r.back().first|a.r[i].first)==ret.r.back().first) ret.r[ret.r.size()-1].second+=a.r[i].second;
		else ret.r.pb(mp(ret.r.back().first|a.r[i].first,a.r[i].second));
	}
	ret.sol=a.sol+b.sol;
	j=0;int cnt=0;
	if((a.r.back().first|b.l.back().first)<k) return ret;
	for(i=0;i<a.r.size();i++)
	{
		if(a.r[i].first>=k)
		{
			ret.sol+=(ll)a.r[i].second*b.sz;
		}
		else
		{
			while(j<b.l.size() && (b.l[j].first|a.r[i].first)<k) cnt+=b.l[j].second,j++;
			while(j>0 && (b.l[j-1].first|a.r[i].first)>=k) j--,cnt-=b.l[j].second;
			ret.sol+=(ll)a.r[i].second*(b.sz-cnt);
		}
	}
	return ret;
}
const int N=100050;
const int M=2*N;
Node node[M];
int ls[M],rs[M],tsz,root,a[N];
void Build(int &c, int ss, int se)
{
	c=++tsz;
	if(ss==se){ node[c]=Node(a[ss]);return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	node[c]=node[ls[c]]+node[rs[c]];
}
void Set(int c, int ss, int se, int qi, int y)
{
	if(ss==se){ node[c]=Node(y);return;}
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,y);
	else Set(rs[c],mid+1,se,qi,y);
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
void Print(int c, int ss, int se)
{
	printf("ss:%i se:%i\n",ss,se);
	node[c].Print();
	if(ss==se) return;
	int mid=ss+se>>1;
	Print(ls[c],ss,mid);
	Print(rs[c],mid+1,se);
}
int main()
{
	int n,q,i,t,l,r,y;
	scanf("%i %i %i",&n,&q,&k);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	Build(root,1,n);
	while(q--)
	{
		scanf("%i",&t);
		if(t==1) scanf("%i %i",&i,&y),Set(root,1,n,i,y);
		else scanf("%i %i",&l,&r),printf("%lld\n",Get(root,1,n,l,r).sol);
		//Print(root,1,n);
	}
	return 0;
}