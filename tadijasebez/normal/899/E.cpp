#include <stdio.h>
#include <set>
#include <map>
using namespace std;
struct Node
{
	int l,r,sz,id;
	Node(){}
	Node(int a, int b, int c, int d){ l=a,r=b,sz=c,id=d;}
	bool operator < (Node b) const
	{
		if(sz==b.sz) return l<b.l;
		return sz>b.sz;
	}
} tr;
struct Seg
{
	int l,r,sz,id;
	Seg(){}
	Seg(int a, int b, int c, int d){ l=a,r=b,sz=c,id=d;}
	bool operator < (Seg b) const
	{
		return l<b.l;
	}
};
set<Node> Set;
set<Seg> Set2;
set<Seg>::iterator it,it1,it2;
const int N=200050;
const int M=2*N;
/*int id[N],l[N],r[N],sz[N],cnt;
int x[M],ls[M],rs[M],clock,root;
void Set(int &c, int ss, int se, int qs, int qe, int val)
{
	if(!c) c=++clock;
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se){ x[c]=val;return;}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,val);
	Set(rs[c],mid+1,se,qs,qe,val);
}
int Get(int c, int ss, int se, int qi)
{
	if(ss==se) return x[c];
	int mid=ss+se>>1;
	if(qi<=mid) return max(x[c],Get(ls[c],ss,mid,qi));
	else return max(x[c],Get(rs[c],mid+1,se,qi));
}*/
int cnt;
map<int,int> index;
int main()
{
	int n,tmp=0,x,y,i;
	y=0;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		if(!index[x]) index[x]=++cnt;
		x=index[x];
		if(x==y) tmp++;
		else
		{
			if(i>1)
			{
				Set.insert(Node(i-tmp,i-1,tmp,y));
				Set2.insert(Seg(i-tmp,i-1,tmp,y));
			}
			tmp=1;
		}
		y=x;
	}
	Set.insert(Node(i-tmp,i-1,tmp,y));
	Set2.insert(Seg(i-tmp,i-1,tmp,y));
	int sol=0;
	while(!Set.empty())
	{
		tr=*(Set.begin());
		Set.erase(tr);
		int l=tr.l,r=tr.r,id=tr.id,sz=tr.sz;
		bool lf=0,rf=0;
		it=Set2.lower_bound(Seg(l,r,sz,id));
		it2=it;it2++;
		if(it2!=Set2.end()) rf=1;
		it1=it;
		if(it1!=Set2.begin()) lf=1,it1--;
		if(lf && rf)
		{
			if(it1->id==it2->id)
			{
				Set.erase(Node(it1->l,it1->r,it1->sz,it1->id));
				Set.erase(Node(it2->l,it2->r,it2->sz,it2->id));
				Set.insert(Node(it1->l,it2->r,it1->sz+it2->sz,it1->id));
				l=it1->l;r=it2->r;sz=it1->sz+it2->sz;id=it1->id;
				Set2.erase(*it1);
				Set2.erase(*it2);
				Set2.insert(Seg(l,r,sz,id));
			}
		}
		Set2.erase(*it);
		sol++;
	}
	printf("%i\n",sol);
	return 0;
}