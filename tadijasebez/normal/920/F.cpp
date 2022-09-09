#include <stdio.h>
#include <set>
#include <vector>
using namespace std;
#define ll long long
const int S=1005;
vector<int> Prime;
bool sieve[S];
void FindPrimes()
{
	int i,j;
	for(i=2;i<S;i++)
	{
		if(!sieve[i])
		{
			Prime.push_back(i);
			for(j=i;j<S;j+=i) sieve[j]=1;
		}
	}
}
int Make(int x)
{
	int ret=1;
	for(int i=0;i<Prime.size() && Prime[i]*Prime[i]<=x;i++)
	{
		int cnt=1;
		while(!(x%Prime[i])) x/=Prime[i],cnt++;
		ret*=cnt;
	}
	if(x>1) ret*=2;
	return ret;
}
set<int> Undone;
set<int>::iterator it;
const int N=300050;
const int M=N*2;
ll x[M];
int ls[M],rs[M],clock,root,a[N];
void Build(int &c, int ss, int se)
{
	c=++clock;
	if(ss==se){ x[c]=a[ss];return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	x[c]=x[ls[c]]+x[rs[c]];
}
void Set(int c, int ss, int se, int qi, int val)
{
	x[c]+=val;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
}
ll Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
int main()
{
	FindPrimes();
	int n,m,i;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),Undone.insert(i);
	Build(root,1,n);
	int l,r,t;
	while(m--)
	{
		scanf("%i %i %i",&t,&l,&r);
		if(t==1)
		{
			for(it=Undone.lower_bound(l);it!=Undone.upper_bound(r);)
			{
				int id=*it;
				it++;
				int b=Make(a[id]);
				Set(root,1,n,id,b-a[id]);
				a[id]=b;
				if(b<3) Undone.erase(id);
			}
		}
		else printf("%lld\n",Get(root,1,n,l,r));
	}
	return 0;
}