#include <stdio.h>
#include <set>
using namespace std;
const int M=15000000;
const int N=200050;
int ls[M],rs[M],clock,root[N][2],n;
long long x[M];
void Set(int &c, int ss, int se, int qi, int val)
{
	if(!c) c=++clock;
	x[c]+=val;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
}
long long Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe) return 0;
	if(qs>se || ss>qe) return 0;
	if(qs<=ss && se<=qe) return x[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
void Set(int c, int t, int qi, int val)
{
	for(c;c<=n;c+=c&-c) Set(root[c][t],1,n,qi,val);
}
long long Get(int c, int t, int qs, int qe)
{
	long long ans=0;
	for(c;c>0;c-=c&-c) ans+=Get(root[c][t],1,n,qs,qe);
	return ans;
}
set<int> index[N];
void Del(int a, int k)
{
	set<int>::iterator it1,it2;
	it1=it2=index[a].find(k);
	bool FL=0,FR=0;
	if(it1!=index[a].begin())
	{
		it1--;
		FL=1;
		Set(k,0,*it1,-(k-(*it1)));
		Set(k,1,k,-(k-(*it1)));
	}
	it2++;
	if(it2!=index[a].end())
	{
		FR=1;
		Set(*it2,1,*it2,-(*it2-k));
		Set(*it2,0,k,-(*it2-k));
	}
	if(FL && FR)
	{
		Set(*it2,0,*it1,(*it2-(*it1)));
		Set(*it2,1,*it2,(*it2-(*it1)));
	}
	index[a].erase(k);
}
void Ins(int a, int k)
{
	set<int>::iterator it1,it2;
	index[a].insert(k);
	it1=it2=index[a].find(k);
	bool FL=0,FR=0;
	if(it1!=index[a].begin())
	{
		it1--;
		FL=1;
		Set(k,0,*it1,(k-(*it1)));
		Set(k,1,k,(k-(*it1)));
	}
	it2++;
	if(it2!=index[a].end())
	{
		FR=1;
		Set(*it2,1,*it2,(*it2-k));
		Set(*it2,0,k,(*it2-k));
	}
	if(FL && FR)
	{
		Set(*it2,0,*it1,-(*it2-(*it1)));
		Set(*it2,1,*it2,-(*it2-(*it1)));
	}
}
int Prev[N],b[N];
int main()
{
	int q,i,a,l,r,t;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a);
		b[i]=a;
		index[a].insert(i);
		if(Prev[a])
		{
			Set(i,1,i,i-Prev[a]);
			Set(i,0,Prev[a],i-Prev[a]);
		}
		Prev[a]=i;
	}
	while(q--)
	{
		scanf("%i %i %i",&t,&l,&r);
		if(t==1)
		{
			Del(b[l],l);
			b[l]=r;
			Ins(b[l],l);
		}
		else
		{
			printf("%lld\n",Get(r,1,1,r)-Get(r,0,1,l-1));
		}
	}
	return 0;
}