#include <stdio.h>
#include <set>
#include <vector>
using namespace std;
struct Seg
{
	int l,r,k;
	Seg(){}
	Seg(int a, int b, int c){ l=a,r=b,k=c;}
	bool operator < (Seg b) const
	{
		if(l==b.l) return r<b.r;
		return l<b.l;
	}
};
set<Seg> Set;
set<Seg>::iterator it;
vector<Seg> v;
const int inf=1e9+7;
void Cut(int i)
{
	if(i==0) return;
	it=Set.upper_bound(Seg(i,inf,0));
	it--;
	if(it->r>i)
	{
		Seg tmp=*it;
		Set.erase(tmp);
		Set.insert(Seg(tmp.l,i,tmp.k));
		Set.insert(Seg(i+1,tmp.r,tmp.k));
	}
}
void Take(int l, int r)
{
	Cut(l-1);
	Cut(r);
	v.clear();
	for(it=Set.lower_bound(Seg(l,0,0));it!=Set.upper_bound(Seg(r,inf,0));it++)
	{
		v.push_back(*it);
	}
	Set.erase(Set.lower_bound(Seg(l,0,0)),Set.upper_bound(Seg(r,inf,0)));
}
int main()
{
	int n,q,l,r,k,i;
	scanf("%i %i",&n,&q);
	int sol=n;
	Set.insert(Seg(1,n,1));
	while(q--)
	{
		scanf("%i %i %i",&l,&r,&k);
		Take(l,r);
		for(i=0;i<v.size();i++)
		{
			if(v[i].k==1) sol-=v[i].r-v[i].l+1;
		}
		if(k==2) sol+=r-l+1,Set.insert(Seg(l,r,1));
		else Set.insert(Seg(l,r,0));
		printf("%i\n",sol);
	}
	return 0;
}
/*#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=300050;
const int M=31*N;
vector<int> id;
int x[M],y[M],ls[M],rs[M],clock,root;
void Propagate(int c, int ss, int se)
{
	if(!y[c]) return;
	if(y[c]==1)
	{
		x[c]=0;
		y[c]=0;
		if(ss==se) return;
		int mid=ss+se>>1;
		if(!ls[c]) ls[c]=++clock,x[ls[c]]=id[mid]-id[ss]+1;
		if(!rs[c]) rs[c]=++clock,x[rs[c]]=id[se]-id[mid];
		y[ls[c]]=1;
		y[rs[c]]=1;
	}
	else if(y[c]==2)
	{
		x[c]=id[se]-id[ss]+1;
		y[c]=0;
		if(ss==se) return;
		int mid=ss+se>>1;
		if(!ls[c]) ls[c]=++clock,x[ls[c]]=id[mid]-id[ss]+1;
		if(!rs[c]) rs[c]=++clock,x[rs[c]]=id[se]-id[mid+1]+1;
		y[ls[c]]=2;
		y[rs[c]]=2;
	}
}
void Set(int &c, int ss, int se, int qs, int qe, int X)
{
	if(!c) c=++clock,x[c]=id[se]-id[ss]+1;
	Propagate(c,ss,se);
	//printf("%i %i %i\n",ss,se,x[c]);
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se)
	{
		y[c]=X;
		Propagate(c,ss,se);
		return;
	}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,X);
	Set(rs[c],mid+1,se,qs,qe,X);
	x[c]=x[ls[c]]+x[rs[c]];
}
int l[N],r[N],k[N];
int main()
{
	int n,i,q;
	scanf("%i %i",&n,&q);
	id.push_back(-69);
	id.push_back(1);
	id.push_back(n);
	for(i=1;i<=q;i++)
	{
		scanf("%i %i %i",&l[i],&r[i],&k[i]);
		id.push_back(l[i]);
		id.push_back(r[i]);
		//Set(root,1,n,l,r,k);
		//printf("%i\n",x[root]);
	}
	sort(id.begin(),id.end());
	id.erase(unique(id.begin(),id.end()),id.end());
	for(i=1;i<=q;i++)
	{
		l[i]=lower_bound(id.begin(),id.end(),l[i])-id.begin();
		r[i]=lower_bound(id.begin(),id.end(),r[i])-id.begin();
		Set(root,1,id.size()-1,l[i],r[i],k[i]);
		printf("%i\n",x[root]);
	}
	return 0;
}*/